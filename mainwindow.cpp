#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QDockWidget>
#include <QScrollBar>
#include <QPainter>
#include <QTextBlock>
#include <QTextCursor>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QShortcut>
#include <QTableWidget>
#include <QTimer>
#include <QTreeView>
#include <QStandardItemModel>
//#include "sintatic.tab.c"
#include "lex.yy.c"

int currentMemLoc = 0;
class CustomQPlainTextEdit : public QPlainTextEdit {
public:
    // Constructor
    CustomQPlainTextEdit(QWidget *parent = nullptr) : QPlainTextEdit(parent) {}

protected:
    // Sobrescribir el evento de la rueda del mouse
    void wheelEvent(QWheelEvent *event) override {
        // Bloquear el evento para evitar que se desplace con la rueda del mouse
        event->ignore();
    }
};

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 32

/* the hash function */
static int hash(const std::string &key) {
    int temp = 0;
    int i = 0;
    while (i < key.length()) {
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

int dialogYesNo(QString message){
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    return msgBox.exec();
}

typedef struct LineListRec {
    int lineno;
    struct LineListRec* next;
} *LineList;

typedef struct BucketListRec {
    std::string name;
    LineList lines;
    std::string tipo;
    int memloc;
    std::string value;
    struct BucketListRec * next;
} * BucketList;


static BucketList hashTable[SIZE];

bool st_insert(const std::string& name,const std::string& tipo, int lineno, int loc, QTextEdit *error) {

    int h = hash(name);
    BucketList l = hashTable[h];

    while ((l != NULL) && (l->name != name)) {  // Ahora usamos la comparación directa con std::string
        l = l->next;
    }

    if (l == NULL) { // Si la variable no está en la tabla, la insertamos
        currentMemLoc++;
        l = (BucketList) calloc(1, sizeof(struct BucketListRec));
        l->name = name;  // Guardamos la variable como std::string
        if(tipo == ""){
            error->append("Error semántico: No está la variable declarada \"" + QString::fromStdString(std::string(name)) + "\" anteriormente, línea: " + QString::number(lineno));
            return false;
        }
        l->tipo = tipo;
        l->lines = (LineList) calloc(1, sizeof(struct LineListRec));
        l->lines->lineno = lineno;
        l->memloc = loc;
        l->value = "0";
        l->lines->next = NULL;
        l->next = hashTable[h];
        hashTable[h] = l;
    } else { // Si ya existe, solo actualizamos los números de línea
        if(l->tipo != tipo && tipo != ""){
            error->append("Error semántico: Variable ya declarada con otro tipo \"" + QString::fromStdString(std::string(name)) + "\" con otro tipo anteriormente, línea: " + QString::number(lineno));
            return false;
        }
        LineList t = l->lines;
        while (t->next != NULL) t = t->next;
        t->next = (LineList) malloc(sizeof(struct LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;
    }
    return true;
}


int getNextMemLocation() {
    return currentMemLoc;  // Incrementa y devuelve la ubicación de memoria actual
}
char* toMutableCharArray(const std::string& str) {
    char* mutableStr = new char[str.size() + 1];  // Crear un array dinámico
    std::copy(str.begin(), str.end(), mutableStr);  // Copiar el contenido de la cadena
    mutableStr[str.size()] = '\0';  // Asegurarse de terminar con un carácter nulo
    return mutableStr;
}

void showLexicData(std::vector<Lexico> *vec, QTableWidget *table, QTextEdit *error){
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels(QStringList() << "Clave" << "Lexema" << "Fila" << "Columna");
    table->setRowCount(vec->size());
    bool checkError = false;
    for(int i = 0; i<vec->size(); i++){
        //qDebug() << vec->at(i).lexema;
        if(QString::fromStdString(vec->at(i).clave).compare("Error", Qt::CaseInsensitive) == 0){
            error->append("Error léxico en linea: " + QString::number(vec->at(i).fila) + ", columna: " + QString::number(vec->at(i).columna));
            checkError = true;
        }
        table->setItem(i,0, new QTableWidgetItem(QString::fromStdString(vec->at(i).clave)));
        table->setItem(i,1, new QTableWidgetItem(QString::fromStdString(vec->at(i).lexema)));
        table->setItem(i,2, new QTableWidgetItem(QString::number(vec->at(i).fila)));
        table->setItem(i,3, new QTableWidgetItem(QString::number(vec->at(i).columna)));
    }
    if(!checkError){
        error->append("Léxico completo sin problemas");
    }
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
}
void printSymTabToView(QTableWidget *table) {
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels(QStringList() << "Variable name" << "Type" << "Location" << "Line Numbers");
    table->setRowCount(SIZE);
    bool checkError = false;
    for (int i = 0; i < SIZE; ++i) {
        if (hashTable[i] != NULL) {
            BucketList l = hashTable[i];
            while (l != NULL) {
                table->setItem(i,0, new QTableWidgetItem(QString::fromStdString(l->name)));
                table->setItem(i,1, new QTableWidgetItem(QString::fromStdString(l->tipo)));
                QString output = QString("%1").arg(l->memloc);
                table->setItem(i,2, new QTableWidgetItem(output));
                QString aux = "";
                LineList t = l->lines;
                while (t != NULL) {
                    aux.append(QString::number(t->lineno) + " ");
                    t = t->next;
                }
                table->setItem(i,3, new QTableWidgetItem(aux));
                l = l->next;
            }
        }
    }
}

bool showSintaticData(Nodo *init, QTextEdit *error, QStandardItem *view = NULL){

    if(init != NULL){
        //qDebug() << "iteracion: " << init->nombre;
        if(QString::fromStdString(init->nombre).compare("apuntador", Qt::CaseInsensitive) == 0){
            if(init->hijos.size() > 0){
                bool exito = showSintaticData(init->hijos.at(0), error, view);
                if(exito){
                    error->append("Sintáctico completo sin problemas");
                }
                return exito;
            }
        }else{

            QStandardItem *node = new QStandardItem(QString::fromStdString(init->nombre) + ": " + QString::fromStdString(init->valor));

            view->appendRow(node);

            bool comprobado = true;
            if(QString::fromStdString(init->nombre).compare("Error sintactico", Qt::CaseInsensitive) == 0){

                error->append("Error sintáctico: " + QString::fromStdString(init->valor));
                comprobado = false;
            }
            for(int i=0; i<init->hijos.size(); i++){

                bool res = showSintaticData(init->hijos.at(i), error, node);
                if(!res){
                    //if(!QString::fromStdString(init->nombre).isEmpty() && init->hijos.size() > 1){
                    //    error->append("Error sintáctico: " + QString::fromStdString(init->hijos.at(i)->valor) + ", en: " + QString::fromStdString(init->hijos.at(init->hijos.size()-2)->nombre));
                    //}else{
                    //    error->append("Error sintáctico: " + QString::fromStdString(init->hijos.at(i)->valor));
                    //}
                    comprobado = false;
                }
            }
            return comprobado;
        }
    }
    return true;
}

BucketList getVariable(std::string name){
    int h = hash(name);
    BucketList l = hashTable[h];

    while ((l != NULL) && (l->name != name)) {  // Ahora usamos la comparación directa con std::string
        l = l->next;
    }
    return l;
}

std::string eval(Nodo *init, QTextEdit *error) {
    if (init != NULL) {
        // Si es un nodo de operación
        if (init->nombre == "suma" || init->nombre == "resta" ||
            init->nombre == "multiplicacion" || init->nombre == "division" ) {

            if (init->hijos.size() >= 2) {
                // Evaluamos recursivamente los hijos
                std::string leftString = eval(init->hijos.at(0), error);
                std::string rightString = eval(init->hijos.at(1), error);
                float leftValue = 0;
                float rightValue = 0;
                if(leftString == "true" || leftString == "false"){
                    error->append("Error semántico: Operación incompatible entre booleano y numero, linea: " + QString::number(init->noLinea));
                    return "0";
                }
                if(rightString == "true" || rightString == "false"){
                    error->append("Error semántico: Operación incompatible entre booleano y numero, linea: " + QString::number(init->noLinea));
                    return "0";
                }
                if(leftString != ""){
                    leftValue = std::stof(leftString);  // Hijo izquierdo
                }
                if(rightString != ""){
                     rightValue = std::stof(rightString);  // Hijo derecho
                }
                float result = 0;
                // Realizamos la operación correspondiente
                if (init->nombre == "suma") {
                    result = leftValue + rightValue;
                } else if (init->nombre == "resta") {
                    result = leftValue - rightValue;
                } else if (init->nombre == "multiplicacion") {
                    result = leftValue * rightValue;
                } else if (init->nombre == "division") {
                    if (rightValue == 0) {
                        error->append("Error: División por cero");
                        return 0;
                    }
                    result = leftValue / rightValue;
                }

                // Guardamos el resultado en el nodo y lo devolvemos
                init->anotacion = std::to_string(result);
                return std::to_string(result);
            }
        } else if (init->nombre == "numero") {
            try {
                // Convertimos el valor del nodo de string a float
                return init->valor;
            } catch (const std::invalid_argument&) {
                error->append("Error: Valor inválido en el nodo '" + QString::fromStdString(init->valor) + "'");
                return 0;
            }
        } else if(init->nombre == "identificador"){
            try{
                BucketList l = getVariable(init->valor);
                if(l!=NULL){
                    if(l->tipo == "int" || l->tipo == "float"){
                        return l->value;
                    }else{
                        init->anotacion = "Error semántico, la variable " + init->valor + " no es compatible con la operación, línea: " + std::to_string(init->noLinea);
                        error->append("Error semántico, la variable " + QString::fromStdString(init->valor) + " no es compatible con la operación, línea: " + QString::number(init->noLinea));
                        return 0;
                    }
                }else{
                    init->anotacion = "Error semántico, no existe la declaración de la variable " + init->valor;
                    error->append("Error semántico, no existe la declaración de la variable " + QString::fromStdString(init->valor));
                    return 0;
                }
            }catch(const std::invalid_argument&){
                error->append("Error: Valor inválido en el nodo '" + QString::fromStdString(init->valor) + "'");
                return 0;
            }
        }else if(init->nombre == "booleano"){
            if(init->valor == "true"){
                return "true";
            }else{
                return "false";
            }
        }
    }
    return "";
}

bool showSemanticData(Nodo *init, QTextEdit *error, bool correct, QStandardItem *view) {
    if(init != NULL){
        //qDebug() << "iteracion: " << init->nombre;
        if(QString::fromStdString(init->nombre).compare("apuntador", Qt::CaseInsensitive) == 0){
            if(init->hijos.size() > 0){
                bool exito = showSemanticData(init->hijos.at(0), error, correct, view);
                if(exito && correct){
                    error->append("Semántico completo sin problemas");
                }
                return exito;
            }
        }else{



            bool comprobado = true;
            QStandardItem *node = new QStandardItem();
            for(int i=0; i<init->hijos.size(); i++){

                bool res = showSemanticData(init->hijos.at(i), error, correct, node);
                if(!res){
                    //if(!QString::fromStdString(init->nombre).isEmpty() && init->hijos.size() > 1){
                    //    error->append("Error sintáctico: " + QString::fromStdString(init->hijos.at(i)->valor) + ", en: " + QString::fromStdString(init->hijos.at(init->hijos.size()-2)->nombre));
                    //}else{
                    //    error->append("Error sintáctico: " + QString::fromStdString(init->hijos.at(i)->valor));
                    //}
                    comprobado = false;
                }
            }

            //Agregar casos para operacioens especificas
            if(init->anotacion == ""){
                std::string result = "";
                //Caso 0 identificador
                if (init->nombre == "identificador") {
                    // Obtener el valor evaluado con la función eval
                    BucketList l = getVariable(init->valor);
                    if(l!=NULL){
                        init->anotacion = l->value;
                    }else{
                        init->anotacion = "Error semántico, no existe la declaración de la variable " + init->valor;
                    }
                }
                //Caso 1 asignaciones
                if (init->nombre == "sent-assign") {
                    // Obtener el valor evaluado con la función eval
                    result = eval(init->hijos.at(1), error);
                    BucketList l = getVariable(init->hijos.at(0)->valor);
                    if(l!=NULL){
                        //Revisar el tipo de variable
                        if(l->tipo != "bool" && (result == "false" || result == "true")){
                            init->anotacion = "Error semántico, asignación de tipos incompatible " + init->hijos.at(0)->valor;
                            error->append("Error semántico, asignación de tipos incompatible " + QString::fromStdString(init->hijos.at(0)->valor) + " linea, " + QString::number(init->noLinea));
                        }else if(l->tipo == "int" && std::stof(result) != std::stoi(result)){
                            init->anotacion = "Error semántico, asignación de tipos incompatible " + init->hijos.at(0)->valor;
                            error->append("Error semántico, asignación de tipos incompatible " + QString::fromStdString(init->hijos.at(0)->valor) + " linea, " + QString::number(init->noLinea));
                        }else{
                            l->value = result;
                            init->anotacion = result;
                        }
                    }else{
                        init->anotacion = "Error semántico, no existe la declaración de la variable " + init->hijos.at(0)->valor;
                        error->append("Error semántico, no existe la declaración de la variable "  + QString::fromStdString(init->hijos.at(0)->valor) + " linea, " + QString::number(init->noLinea));
                    }
                }
                //Caso 2 operaciones
                if (init->nombre == "suma" || init->nombre == "resta" ||
                    init->nombre == "multiplicacion" || init->nombre == "division"
                    || init->nombre == "numero") {
                    // Obtener el valor evaluado con la función eval
                    result = eval(init, error);
                    init->anotacion = result;

                }
            }



            //Agregar a la vista junto a las anotaciones

            if(init->nombre == "identificador" || init->nombre == "list-id"){
                BucketList l = getVariable(init->valor);
                if(l!=NULL){
                    node->setText(QString::fromStdString(init->nombre) + ": " + QString::fromStdString(init->valor) + " .type(" + QString::fromStdString(l->tipo) + ") .value(" + QString::fromStdString(init->anotacion) + ")" );
                }
            }else{
                node->setText(QString::fromStdString(init->nombre) + ": " + QString::fromStdString(init->valor) + " (" + QString::fromStdString(init->anotacion) + ")");
            }


            view->appendRow(node);



            return comprobado;
        }
    }
    return true;
}

bool procesarTablaHash(Nodo *init, QTextEdit *error, std::string var_tipo = "") {
    if (init == NULL) return true;
    if (QString::fromStdString(init->nombre).compare("decl", Qt::CaseInsensitive) == 0) {
        var_tipo = init->hijos.at(0)->valor;
    }
     bool correct = true;
    if (QString::fromStdString(init->nombre).compare("list-id", Qt::CaseInsensitive) == 0
        || QString::fromStdString(init->nombre).compare("identificador", Qt::CaseInsensitive) == 0) {
        std::string var_name = init->valor;   // Nombre de la
        int lineno = init->noLinea;;  // Asume que puedes obtener el número de línea
        int memloc = getNextMemLocation();  // Genera ubicación en memoria

        char* var_name_mutable = toMutableCharArray(var_name);
        // Insertar en la tabla hash

        if(!st_insert(var_name_mutable,var_tipo, lineno, memloc, error) && var_tipo != "s"){
            correct = false;
        }
        delete[] var_name_mutable;  // Liberar memoria
    }

    // Recorrer los hijos del nodo
    for (int i = 0; i < init->hijos.size(); i++) {
        if(!procesarTablaHash(init->hijos.at(i), error, var_tipo)){
            correct = false;
        }
    }
    return correct;
}



void formatText(QPlainTextEdit *editor, int initialCursor){
    //Estilo default

    //Estilos especificos para cada tipo de clave
    QTextCharFormat claveFormat;
    claveFormat.setForeground(QColor("#F53A41"));
    QTextCharFormat identifierFormat;
    identifierFormat.setForeground(QColor("#003BEB"));
    QTextCharFormat cadenaFormat;
    cadenaFormat.setForeground(QColor("#F09200"));
    QTextCharFormat comentarioFormat;
    comentarioFormat.setForeground(QColor("#008000"));
    QTextCharFormat errorFormat;
    errorFormat.setUnderlineColor(QColor("#F53A41"));
    errorFormat.setUnderlineStyle(QTextCharFormat::WaveUnderline);
    QTextCharFormat elseFormat;
    std::vector<Lexico> vec = analyzeText(editor->toPlainText().toStdString().c_str());
    QTextCursor cursor(editor->document());
    cursor.setPosition(initialCursor); //Evita que realicé lecutras o cambios de elementos pasados, da un mejor rendimiento
    for(const auto&token : vec){
        int start = editor->toPlainText().indexOf(QString::fromStdString(token.lexema), cursor.position(), Qt::CaseSensitive);
        if(start!=-1){
            int length = QString::fromStdString(token.lexema).length();
            cursor.setPosition(start);
            int pastPosition = cursor.position();
            cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor, length);
            if(token.estilo == "Reservada" ){
                cursor.setCharFormat(claveFormat);
            }else if(token.estilo == "Simbolo"){
                cursor.setCharFormat(identifierFormat);
            }else if(token.estilo == "Cadena"){
                cursor.setCharFormat(cadenaFormat);
            }else if(token.estilo=="Comentario"){
                cursor.setCharFormat(comentarioFormat);
            }else if(token.estilo=="Error"){
                cursor.setCharFormat(errorFormat);
            }else{
                cursor.setCharFormat(elseFormat);
            }
        }
    }
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Crear controles
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QPlainTextEdit *codeEditor = new QPlainTextEdit; // Usar QPlainTextEdit en lugar de QTextEdit
    // Habilitar la visualización de números de línea
    codeEditor->setLineWrapMode(QPlainTextEdit::NoWrap);
    codeEditor->setPlainText("");
    QFont font;
    font.setFamily("Courier");
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(12);
    codeEditor->setFont(font);
    QFontMetrics fontMetrics(font);
    QTextDocument *doc = codeEditor->document();
    QTextOption opt = doc->defaultTextOption();
    opt.setTabStopDistance(4 * fontMetrics.averageCharWidth());
    doc->setDefaultTextOption(opt);
    codeEditor->setTabStopDistance(4 * fontMetrics.averageCharWidth());

    //Row counter
    CustomQPlainTextEdit *rowsCount = new CustomQPlainTextEdit;
    rowsCount->setReadOnly(true);
    rowsCount->setFixedWidth(3 * fontMetrics.averageCharWidth());
    rowsCount->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    rowsCount->insertPlainText("1");
    rowsCount->setFont(font);
    QHBoxLayout *editorLayout = new QHBoxLayout;
    editorLayout->addWidget(rowsCount);
    editorLayout->addWidget(codeEditor);


    //Cuando la barra del editor de codigo se deslplace, que también lo haga el de rows count
    connect(codeEditor->verticalScrollBar(), &QScrollBar::valueChanged, this, [=](int value){
        rowsCount->verticalScrollBar()->setPageStep(codeEditor->verticalScrollBar()->pageStep());
        rowsCount->verticalScrollBar()->setValue(value);
    });

    connect(codeEditor->horizontalScrollBar(), &QScrollBar::rangeChanged, this, [=](int min, int max){
        if(min == max){
             rowsCount->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        }else{
            rowsCount->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        }
    });

    //Posición del cursor para ir actualizando unicamente lo más reciente;


    /*struct myInt *myCursor = new struct myInt;
    struct myInt *antCursor = new struct myInt;
    myCursor->initialEditPosition = 0;
    antCursor->initialEditPosition = 0;
    // Conexión de la señal cursorPositionChanged para rastrear la posición del cursor
    connect(codeEditor, &QPlainTextEdit::cursorPositionChanged, this, [=]() {
        // antCursor, lleva el control de donde esta el cursor cuando se mueve.
        antCursor->initialEditPosition = codeEditor->textCursor().position();
        if(codeEditor->textCursor().position() < myCursor->initialEditPosition){
            /* Si el usuario coloca el cursor en una posición previa, se regresa
             * el apuntador inicial del analisis para observar todos los cambios que
             * hace el usuario.
            myCursor->initialEditPosition = codeEditor->textCursor().position();
        }
    });*/

    // Declaración de QTimer en tu clase
    QTimer *timer;
    // Configuración del temporizador en tu constructor
    // Timer para evitar que se hagan muchas llamadas a los estilos del codigo
    timer = new QTimer(this);
    timer->setSingleShot(true);

    connect(timer, &QTimer::timeout, this, [=]() {
        //Formatea el texto
        formatText(codeEditor, 0);
        /* Actualiza el puntero donde inicia el análisis a una posición mayor
         * de esta forma evitamos reanalizar texto anterior, haciendolo un poco
         * más eficiente
         *  myCursor->initialEditPosition = antCursor->initialEditPosition;
         */

    });

    connect(codeEditor, &QPlainTextEdit::textChanged, this, [=](){
        //Se llama a hacer update del color del texto después de 500ms para evitar una sobre carga
        timer->start(500);
    });

    //Cada vez que cambie el numero de lineas en el documento se actualizará en el widget lateral
    connect(codeEditor->document(), &QTextDocument::blockCountChanged, [codeEditor, rowsCount, fontMetrics](int newBlockCount) {
        QString numbers;
        for (int i = 1; i <= newBlockCount; ++i){
            numbers += QString::number(i) + QLatin1Char('\n');
        }
        rowsCount->clear();
        rowsCount->insertPlainText(numbers);
        rowsCount->setFixedWidth((QString::number(newBlockCount).length()+2)* fontMetrics.averageCharWidth());
        rowsCount->verticalScrollBar()->setPageStep(codeEditor->verticalScrollBar()->pageStep());
        rowsCount->verticalScrollBar()->setValue(codeEditor->verticalScrollBar()->value());
    });

    QWidget *codeEditorWidget = new QWidget;
    codeEditorWidget->setLayout(editorLayout);

    // Convertir la ventana de código en un dockWidget
    QDockWidget *codeDockWidget = new QDockWidget("Editor de Código", this);
    codeDockWidget->setWidget(codeEditorWidget);
    addDockWidget(Qt::TopDockWidgetArea, codeDockWidget);
    codeDockWidget->setMinimumWidth(static_cast<int>(0.7 * this->width()));
    codeDockWidget->setMinimumHeight(static_cast<int>(0.8 * this->height()));

    // Crear varios botones en una sola fila
    QGridLayout *buttonLayout = new QGridLayout;
    QPushButton *button1 = new QPushButton("Léxico");
    QPushButton *button2 = new QPushButton("Sintáctico");
    QPushButton *button3 = new QPushButton("Semántica");
    QPushButton *button5 = new QPushButton("Tabla de síbomolos");
    QPushButton *button4 = new QPushButton("Código intermedio");

    // Crear el cuadro de texto para el análisis sintáctico
    QTreeView *syntacticTreeView = new QTreeView;
    syntacticTreeView->setFont(font);
    syntacticTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Crear el cuadro de texto para el análisis semántico
    QTreeView *semanticTreeView = new QTreeView;
    semanticTreeView->setFont(font);
    semanticTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //Crear tabla para la tabla de símbolos
    QTableWidget *hashTableView = new QTableWidget();
    hashTableView->setColumnCount(4);
    hashTableView->setHorizontalHeaderLabels(QStringList() << "Variable name" << "Type" << "Location" << "Line Numbers");
    hashTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    hashTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    hashTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //Crear tabla
    QTableWidget *resultsTable = new QTableWidget();
    resultsTable->setColumnCount(5);
    resultsTable->setHorizontalHeaderLabels(QStringList() << "Clave" << "Lexema" << "Fila" << "Columna");
    resultsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    resultsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    resultsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QStackedWidget *stackedWidget = new QStackedWidget;
    //Añadir widgets al stackwidget para poder moverse entre ventanas.
    stackedWidget->addWidget(resultsTable);
    stackedWidget->addWidget(syntacticTreeView);
    stackedWidget->addWidget(semanticTreeView);
    stackedWidget->addWidget(hashTableView);

    // Layout para organizar los botones y el cuadro de texto
    QVBoxLayout *buttonTextEditLayout = new QVBoxLayout;
    buttonTextEditLayout->addLayout(buttonLayout);
    buttonTextEditLayout->addWidget(stackedWidget);

    buttonLayout->addWidget(button1, 0, 0);
    buttonLayout->addWidget(button2, 0, 1);
    buttonLayout->addWidget(button3, 0, 2);
    buttonLayout->addWidget(button5, 0, 3);
    buttonLayout->addWidget(button4, 0, 4);


    // Conectar botones a las funciones lambda para cambiar las vistas
    QObject::connect(button1, &QPushButton::clicked, [stackedWidget]() {
        stackedWidget->setCurrentIndex(0);
    });
    QObject::connect(button2, &QPushButton::clicked, [stackedWidget]() {
        stackedWidget->setCurrentIndex(1);
    });
    QObject::connect(button3, &QPushButton::clicked, [stackedWidget]() {
        stackedWidget->setCurrentIndex(2);
    });
    QObject::connect(button5, &QPushButton::clicked, [stackedWidget]() {
        stackedWidget->setCurrentIndex(3);
    });


    // Widget para contener los botones y el cuadro de texto
    QWidget *buttonTextEditWidget = new QWidget;
    buttonTextEditWidget->setLayout(buttonTextEditLayout);

    // Convertir la ventana de botones en un dockWidget
    QDockWidget *buttonDockWidget = new QDockWidget("Depuración", this);
    buttonDockWidget->setWidget(buttonTextEditWidget);
    addDockWidget(Qt::TopDockWidgetArea, buttonDockWidget);
    buttonDockWidget->setMinimumWidth(static_cast<int>(0.4 * this->width()));
    buttonDockWidget->setMinimumHeight(static_cast<int>(0.8 * this->height()));

    // Convertir la ventana de texto en un dockWidget
    QDockWidget *bottomDockWidget = new QDockWidget("Salida", this);
    QTextEdit *textVistaAbajo = new QTextEdit;
    textVistaAbajo->setFont(font);
    textVistaAbajo->setReadOnly(true);
    bottomDockWidget->setWidget(textVistaAbajo);
    addDockWidget(Qt::BottomDockWidgetArea, bottomDockWidget);
    bottomDockWidget->setMinimumHeight(static_cast<int>(0.4 * this->height()));


    //Opciones del menu de arriba
    // Crear el menú "Archivo"
    QMenu *menuArchivo = this->menuBar()->addMenu("&Archivo");
    QMenu *menuCodigo = this->menuBar()->addMenu("&Código");
    QMenu *menuComponent = this->menuBar()->addMenu("&Componentes");


    // Crear cinco acciones (botones) en el menú "Archivo"
    QAction *action1 = menuArchivo->addAction("Abrir");
    QAction *action3 = menuArchivo->addAction("Salvar");
    QAction *action4 = menuArchivo->addAction("Salvar como");
    QAction *action2 = menuArchivo->addAction("Cerrar");
    QAction *action5 = menuArchivo->addAction("Salir");
    QString *fileName = new QString;




    QObject::connect(action1, &QAction::triggered, this,[=](){
        fileName->assign(QFileDialog::getOpenFileName(this,"Seleccionar el archivo","", "Archivos de código (*.nlp)"));
        if(!fileName->isEmpty()){
            //Abrir el archivo
            QFile *file = new QFile;
            file->setFileName(fileName->toStdString().c_str());
            if(file->open(QIODevice::ReadOnly)){
                QTextStream in(file);
                QString text = in.readAll();
                codeEditor->clear();
                codeEditor->insertPlainText(text);
                formatText(codeEditor,0);
                file->close();
            }
        }
        QStringList partesRuta = fileName->split("/");
        QString nombreArchivo = partesRuta[partesRuta.length()-1].split(".")[0];
        this->setWindowTitle("IDEnsamblador - " + nombreArchivo);
    });

    QObject::connect(action2, &QAction::triggered, this,[=](){
        if(fileName->isEmpty()){
            codeEditor->clear();
            return;
        }
        int resp = dialogYesNo("Hay un archivo abierto ¿Desea guardar los cambios antes de continuar?");
        if(resp == QMessageBox::Yes){
            QFile file(fileName->toStdString().c_str());
            if(file.open(QIODevice::WriteOnly)){
                QTextStream out(&file);
                out << codeEditor->toPlainText();
                file.close();
                resultsTable->setRowCount(0);
                textVistaAbajo->clear();
                QStandardItemModel *modelSyntactic = qobject_cast<QStandardItemModel*>(syntacticTreeView->model());
                if (modelSyntactic) {
                    modelSyntactic->clear();
                }
                codeEditor->clear();
            }
        }else{
            resultsTable->setRowCount(0);
            textVistaAbajo->clear();
            QStandardItemModel *modelSyntactic = qobject_cast<QStandardItemModel*>(syntacticTreeView->model());
            if (modelSyntactic) {
                modelSyntactic->clear();
            }
            codeEditor->clear();
        }
        fileName->assign("");
        QStringList partesRuta = fileName->split("/");
        this->setWindowTitle("IDEnsamblador");
        //qDebug() << fileName->toStdString().c_str();
    });

    QObject::connect(action3, &QAction::triggered, this,[=](){
        bool save = false;
        if(fileName->isEmpty()){
            int resp = dialogYesNo("No hay un archivo abierto ¿Desea seleccionar uno?");
            if(resp == QMessageBox::Yes){
                fileName->assign(QFileDialog::getSaveFileName(this, "Cree o seleccione un archivo destino", "", "Archivos de código (*.nlp)"));
                if(fileName->isEmpty()) return;
                save = true;
            }
        }
        int resp = QMessageBox::Yes;
        if(!save) resp = dialogYesNo("¿Desea guardar los cambios?");
        if(resp == QMessageBox::Yes){
            QFile file(fileName->toStdString().c_str());
            if(file.open(QIODevice::WriteOnly)){
                QTextStream out(&file);
                out << codeEditor->toPlainText();
                file.close();
            }
        }
        QStringList partesRuta = fileName->split("/");
        QString nombreArchivo = partesRuta[partesRuta.length()-1].split(".")[0];
        this->setWindowTitle("IDEnsamblador - " + nombreArchivo);
        //qDebug() << fileName->toStdString().c_str();
    });

    QObject::connect(action4, &QAction::triggered, this,[=](){
        fileName->assign(QFileDialog::getSaveFileName(this, "Cree o seleccione un archivo destino", "", "Archivos de código (*.nlp)"));
        if(!fileName->isEmpty()){
            QFile file(fileName->toStdString().c_str());
            if(file.open(QIODevice::WriteOnly)){
                QTextStream out(&file);
                out << codeEditor->toPlainText();
                file.close();
            }
        }
        QStringList partesRuta = fileName->split("/");
        QString nombreArchivo = partesRuta[partesRuta.length()-1].split(".")[0];
        this->setWindowTitle("IDEnsamblador - " + nombreArchivo);
        //qDebug() << fileName->toStdString().c_str();
    });

    QObject::connect(action5, &QAction::triggered,[&](){
        QApplication::quit();
    });

    //Acciones de botones para el menú de componentes
    QAction *cAction1 = menuComponent->addAction("Editor");
    QAction *cAction2 = menuComponent->addAction("Depuración");
    QAction *cAction3 = menuComponent->addAction("Vista del texto");

    QObject::connect(cAction1, &QAction::triggered, this,[=](){
        if(codeDockWidget->isHidden()){
            codeDockWidget->show();
        }
    });
    QObject::connect(cAction2, &QAction::triggered, this,[=](){
        if(buttonDockWidget->isHidden()){
            buttonDockWidget->show();
        }
    });
    QObject::connect(cAction3, &QAction::triggered, this,[=](){
        if(bottomDockWidget->isHidden()){
            bottomDockWidget->show();
        }
    });


    //Acciones de botones del código
    QAction *codAction1 = menuCodigo->addAction("Compilar");
    QAction *codAction2 = menuCodigo->addAction("Correr");
    QAction *codAction3 = menuCodigo->addAction("Depurar");
    std::vector<Lexico> *lex = new std::vector<Lexico>;
    Nodo *sint = new struct Nodo;

    //Conecta los botones de la sección de depuración
    /*connect(button1, &QPushButton::clicked, this, [=](){
        textVistaAbajo->clear();
        syntacticText->clear();
        showSintaticData(sint, syntacticText,0,textVistaAbajo);
        showLexicData(lex, resultsTable, textVistaAbajo);
    });

    connect(button2, &QPushButton::clicked, this, [=](){
        textVistaAbajo->clear();
        syntacticText->clear();
        showSintaticData(sint, syntacticText,0,textVistaAbajo);
        showLexicData(lex, resultsTable, textVistaAbajo);
    });*/

    QObject::connect(codAction1, &QAction::triggered, this,[=](){
        bool open = false;
        //Revisa si hay algun archivo abierto, si no pide que se abra uno
        if(fileName->isEmpty()){
            if(codeEditor->toPlainText().length() == 0){
                int resp = dialogYesNo("No hay un archivo abierto ¿Desea abrir uno para compilar?");
                if(resp == QMessageBox::Yes){
                    fileName->assign(QFileDialog::getOpenFileName(this, "Seleccione un archivo para compilar", "", "Archivos de código (*.nlp)"));
                    if(fileName->isEmpty()) return;
                    open = true;
                    QFile *file = new QFile;
                    file->setFileName(fileName->toStdString().c_str());
                    if(file->open(QIODevice::ReadOnly)){
                        QTextStream in(file);
                        QString text = in.readAll();
                        codeEditor->clear();
                        codeEditor->insertPlainText(text);
                        formatText(codeEditor,0);
                        file->close();
                    }
                    QStringList partesRuta = fileName->split("/");
                    QString nombreArchivo = partesRuta[partesRuta.length()-1].split(".")[0];
                    this->setWindowTitle("IDEnsamblador - " + nombreArchivo);
                }
            }else{
                if(fileName->isEmpty()){
                    int resp = dialogYesNo("No hay un archivo para guardar los cambios ¿Desea crar uno?");
                    if(resp == QMessageBox::Yes){
                        fileName->assign(QFileDialog::getSaveFileName(this, "Cree o seleccione un archivo destino", "", "Archivos de código (*.nlp)"));
                        if(fileName->isEmpty()) return;
                        open = true;
                        QFile file(fileName->toStdString().c_str());
                        if(file.open(QIODevice::WriteOnly)){
                            QTextStream out(&file);
                            out << codeEditor->toPlainText();
                            file.close();
                        }
                        QStringList partesRuta = fileName->split("/");
                        QString nombreArchivo = partesRuta[partesRuta.length()-1].split(".")[0];
                        this->setWindowTitle("IDEnsamblador - " + nombreArchivo);
                    }
                }
            }
        }else{
            //Si hay un archivo abierto pregunta si se quieren guardar cambios
            int resp = QMessageBox::No;
            resp = dialogYesNo("¿Desea guardar los cambios antes de compilar?");
            if(resp == QMessageBox::Yes){
                QFile file(fileName->toStdString().c_str());
                if(file.open(QIODevice::WriteOnly)){
                    QTextStream out(&file);
                    out << codeEditor->toPlainText();
                    file.close();
                }
            }
            open = true;
        }
        if(open && !codeEditor->toPlainText().isEmpty()){
            lex->clear();
            std::vector<Lexico> vec = analyzeFile(fileName->toStdString().c_str());
            activateRet();
            textVistaAbajo->clear();
            lex->swap(vec);
            showLexicData(lex, resultsTable, textVistaAbajo);
            sint->nombre = "apuntador";
            sint->hijos.clear();
            sint->hijos.push_back(getSintactic(fileName->toStdString().c_str()));

            QStandardItemModel *modelSyntactic = qobject_cast<QStandardItemModel*>(syntacticTreeView->model());
            if (modelSyntactic) {
                modelSyntactic->clear();
            }
            QStandardItemModel *modelSyn = new QStandardItemModel;
            QStandardItem *rootSyntatic = modelSyn->invisibleRootItem();
            showSintaticData(sint, textVistaAbajo, rootSyntatic);
            syntacticTreeView->setModel(modelSyn);
            syntacticTreeView->show();
            syntacticTreeView->expandAll();

            currentMemLoc = 0;
            for(int i=0; i<SIZE; i++){
                if(hashTable[i]) hashTable[i] = NULL;

            }
            bool correct = procesarTablaHash(sint, textVistaAbajo);
            printSymTabToView(hashTableView);
            QStandardItemModel *modelSemantic = qobject_cast<QStandardItemModel*>(semanticTreeView->model());
            if (modelSemantic) {
                modelSemantic->clear();
            }
            QStandardItemModel *modelSem = new QStandardItemModel;
            QStandardItem *rootSem = modelSem->invisibleRootItem();
            showSemanticData(sint, textVistaAbajo, correct, rootSem);
            semanticTreeView->setModel(modelSem);
            semanticTreeView->show();
            semanticTreeView->expandAll();

        }
    });

    //Shortcuts

    /*QShortcut *saveShort = new QShortcut(Qt::Key_Save, this);
    connect(saveShort, &QShortcut::activated, this, [=](){
        bool save = false;
        if(fileName->isEmpty()){
            int resp = dialogYesNo("No hay un archivo abierto ¿Desea seleccionar uno?");
            if(resp == QMessageBox::Yes){
                fileName->assign(QFileDialog::getSaveFileName(this, "Cree o seleccione un archivo destino", "", "Archivos de código (*.nlp)"));
                if(fileName->isEmpty()) return;
                save = true;
            }
        }
        int resp = QMessageBox::Yes;
        if(!save) resp = dialogYesNo("¿Desea guardar los cambios?");
        if(resp == QMessageBox::Yes){
            QFile file(fileName->toStdString().c_str());
            if(file.open(QIODevice::WriteOnly)){
                QTextStream out(&file);
                out << codeEditor->toPlainText();
                file.close();
            }
        }
        QStringList partesRuta = fileName->split("/");
        QString nombreArchivo = partesRuta[partesRuta.length()-1].split(".")[0];
        this->setWindowTitle("IDE - " + nombreArchivo);
        qDebug() << fileName->toStdString().c_str();
    });*/

}

MainWindow::~MainWindow()
{

}
