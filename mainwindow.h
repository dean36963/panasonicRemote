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

#include <iostream>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QList<QPushButton*> buttons;
    QWidget *parent;
    void initUi();
public slots:
    void testSelected();
    void testFinished(QNetworkReply*reply);
};

#endif // MAINWINDOW_H
