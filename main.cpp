#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QMainWindow>
#include <QScreen>
#include <QMenuBar>
#include <QAction>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "IDEnsamblador_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    w.setGeometry(screenGeometry);

    // Crear el menú "Archivo"
    QMenu *menuArchivo = w.menuBar()->addMenu("&Archivo");
    QMenu *menu = w.menuBar()->addMenu("&Archivo");

    // Crear cinco acciones (botones) en el menú "Archivo"
    QAction *action1 = menuArchivo->addAction("Abrir");
    QAction *action2 = menuArchivo->addAction("Cerrar");
    QAction *action3 = menuArchivo->addAction("Salvar");
    QAction *action4 = menuArchivo->addAction("Salvar como");


    w.show();

    return a.exec();
}
