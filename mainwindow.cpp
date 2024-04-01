#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QListWidget>
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

int dialogYesNo(QString message){
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    return msgBox.exec();
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
    rowsCount->setStyleSheet("background-color: lightgray;");
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
    codeDockWidget->setMinimumWidth(static_cast<int>(0.6 * this->width()));

    // Crear varios botones en una sola fila
    QGridLayout *buttonLayout = new QGridLayout;
    QPushButton *button1 = new QPushButton("Léxico");
    QPushButton *button2 = new QPushButton("Sintáctico");
    QPushButton *button3 = new QPushButton("Semántica");
    QPushButton *button4 = new QPushButton("Código intermedio");

    buttonLayout->addWidget(button1, 0, 0);
    buttonLayout->addWidget(button2, 0, 1);
    buttonLayout->addWidget(button3, 0, 2);
    buttonLayout->addWidget(button4, 0, 3);

    // Crear el cuadro de texto
    QTextEdit *editText = new QTextEdit;
    editText->setReadOnly(true);
    // Layout para organizar los botones y el cuadro de texto
    QVBoxLayout *buttonTextEditLayout = new QVBoxLayout;
    buttonTextEditLayout->addLayout(buttonLayout);
    buttonTextEditLayout->addWidget(editText);

    // Widget para contener los botones y el cuadro de texto
    QWidget *buttonTextEditWidget = new QWidget;
    buttonTextEditWidget->setLayout(buttonTextEditLayout);

    // Convertir la ventana de botones en un dockWidget
    QDockWidget *buttonDockWidget = new QDockWidget("Depuración", this);
    buttonDockWidget->setWidget(buttonTextEditWidget);
    addDockWidget(Qt::TopDockWidgetArea, buttonDockWidget);
    buttonDockWidget->setMinimumWidth(static_cast<int>(0.3 * this->width()));

    // Convertir la ventana de texto en un dockWidget
    QDockWidget *bottomDockWidget = new QDockWidget("Vista de Texto Abajo", this);
    QTextEdit *textVistaAbajo = new QTextEdit;
    textVistaAbajo->setReadOnly(true);
    bottomDockWidget->setWidget(textVistaAbajo);
    addDockWidget(Qt::BottomDockWidgetArea, bottomDockWidget);
    bottomDockWidget->setMinimumHeight(static_cast<int>(0.3 * this->height()));


    //Opciones del menu de arriba
    // Crear el menú "Archivo"
    QMenu *menuArchivo = this->menuBar()->addMenu("&Archivo");
    QMenu *menuCodigo = this->menuBar()->addMenu("&Código");
    QMenu *menuComponent = this->menuBar()->addMenu("&Componentes");


    // Crear cinco acciones (botones) en el menú "Archivo"
    QAction *action1 = menuArchivo->addAction("Abrir");
    QAction *action2 = menuArchivo->addAction("Cerrar");
    QAction *action3 = menuArchivo->addAction("Salvar");
    QAction *action4 = menuArchivo->addAction("Salvar como");
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
                file->close();
            }
        }
        QStringList partesRuta = fileName->split("/");
        QString nombreArchivo = partesRuta[partesRuta.length()-1].split(".")[0];
        this->setWindowTitle("IDE - " + nombreArchivo);
        qDebug() << fileName->toStdString().c_str();
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
            }
        }
        fileName->assign("");
        codeEditor->clear();
        QStringList partesRuta = fileName->split("/");
        QString nombreArchivo = partesRuta[partesRuta.length()-1].split(".")[0];
        this->setWindowTitle("IDE - " + nombreArchivo);
        qDebug() << fileName->toStdString().c_str();
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
        this->setWindowTitle("IDE - " + nombreArchivo);
        qDebug() << fileName->toStdString().c_str();
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
        this->setWindowTitle("IDE - " + nombreArchivo);
        qDebug() << fileName->toStdString().c_str();
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
