#ifndef REMOTEBUTTON_H
#define REMOTEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStyle>
#include <QColor>

#include "commandfile.h"

#include <iostream>

using namespace std;


class RemoteButton : public QPushButton
{
    Q_OBJECT
public:
    explicit RemoteButton(CommandFile *file, QWidget *parent = 0);
    ~RemoteButton();
    void setHost(QString host);

private:
    CommandFile *file;
    QString host;
signals:

public slots:
    void send(bool);
    void logResponse(QNetworkReply *reply);
};

#endif // REMOTEBUTTON_H
