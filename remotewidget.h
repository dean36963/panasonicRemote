#ifndef REMOTEWIDGET_H
#define REMOTEWIDGET_H

#include <QWidget>
#include <QDir>
#include <QCoreApplication>
#include <QDirIterator>
#include <QPushButton>
#include <QList>
#include <QGridLayout>
#include <QLineEdit>
#include <QSplitter>
#include <QLabel>
#include <QComboBox>
#include <QSocketNotifier>

#include "commandfile.h"
#include "remotebutton.h"
#include "ipsaver.h"

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
    QList<RemoteButton*> buttons;
    QGridLayout *layout;
    QComboBox *hostSelector;
    QLabel *hostLabel;
    QPushButton *pingHost;
    QGridLayout *buttonLayout;
    QSplitter *splitter;
    QString getHost();

signals:

public slots:
    void hostChanged();
    void pingHostClicked();
};

#endif // REMOTEWIDGET_H
