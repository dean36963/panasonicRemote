#ifndef REMOTEWIDGET_H
#define REMOTEWIDGET_H

#include <QWidget>
#include <QDir>
#include <QCoreApplication>
#include <QDirIterator>
#include <QPushButton>
#include <QList>
#include <QGridLayout>

#include "commandfile.h"
#include "remotebutton.h"

#include <iostream>

using namespace std;

class RemoteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RemoteWidget(QString pathToConfig, QWidget *parent = 0);
    ~RemoteWidget();

private:
    QString configPath;
    void initUi();
    QList<QPushButton*> buttons;
    QGridLayout *layout;

signals:

public slots:
};

#endif // REMOTEWIDGET_H
