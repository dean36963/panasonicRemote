#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->parent = parent;
    //TODO setup menus
    initUi();
}

MainWindow::~MainWindow() {
    delete remoteWidget;
}

void MainWindow::initUi() {
    QString path = QString("res")
                .append(QDir::separator())
                .append("panasonic_viera_e_series");
    remoteWidget = new RemoteWidget(path);
    //Set this widget as the main menu
    setCentralWidget(remoteWidget);
}
