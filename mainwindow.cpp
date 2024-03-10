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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Crear controles
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QTextEdit *codeEditor = new QTextEdit;
    QPlainTextEdit *textView = new QPlainTextEdit;
    mainLayout->addWidget(codeEditor);
    mainLayout->addWidget(textView);

    // Convertir la ventana de código en un dockWidget
    QDockWidget *codeDockWidget = new QDockWidget("Editor de Código", this);
    codeDockWidget->setWidget(codeEditor);
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
    bottomDockWidget->setWidget(new QTextEdit);
    addDockWidget(Qt::BottomDockWidgetArea, bottomDockWidget);
    bottomDockWidget->setMinimumHeight(static_cast<int>(0.3 * this->height()));

}

MainWindow::~MainWindow()
{

}
