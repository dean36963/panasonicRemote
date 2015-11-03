#ifndef IPSAVER_H
#define IPSAVER_H

#include <QString>
#include <QList>
#include <QStandardPaths>
#include <QStringList>
#include <QFile>
#include <iostream>
#include <QTextStream>

class IPSaver
{
protected:
    IPSaver();
public:
    static IPSaver *getInstance();
    QString getMostRecentHost();
    QList<QString> getHosts();
    void addNewHost(QString host);
private:
    static IPSaver *instance;
    QList<QString> hosts;
    void write();
    void read();
};

#endif // IPSAVER_H
