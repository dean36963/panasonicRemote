#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->parent = parent;
    QStringList args = QCoreApplication::arguments();
    finished = false;
    if(args.length()==3) {
        path = args.at(1);
        autoExecCmdFile = args.at(2);
        finished = true;
    } else {
        path = QString("res")
                .append(QDir::separator())
                .append("panasonic_viera_e_series");
        autoExecCmdFile = "";
    }
    initUi();
}

MainWindow::~MainWindow() {
    delete remoteWidget;
}

void MainWindow::initUi() {
    remoteWidget = new RemoteWidget(path,autoExecCmdFile,this);
    //Set this widget as the main menu
    setCentralWidget(remoteWidget);
}

bool MainWindow::isFinished() {
    return finished;
}
