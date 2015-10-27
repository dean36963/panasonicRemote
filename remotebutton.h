#ifndef REMOTEBUTTON_H
#define REMOTEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

#include "commandfile.h"


class RemoteButton : public QPushButton
{
    Q_OBJECT
public:
    explicit RemoteButton(CommandFile *file, QWidget *parent = 0);
    ~RemoteButton();

private:
    CommandFile *file;
signals:

public slots:
    void send(bool);
    void logResponse(QNetworkReply *reply);
};

#endif // REMOTEBUTTON_H
