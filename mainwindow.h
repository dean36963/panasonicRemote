#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QList>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QHttpMultiPart>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QCoreApplication>

#include "remotewidget.h"

#include <iostream>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool isFinished();
private:
    QList<QPushButton*> buttons;
    QWidget *parent;
    RemoteWidget *remoteWidget;
    void initUi();
    QString path;
    QString autoExecCmdFile;
    bool finished;
public slots:

};

#endif // MAINWINDOW_H
