#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(!w.isFinished()) {
        w.show();
    } else {
        w.setHidden(true);
    }
    return a.exec();
}
