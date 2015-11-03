#include "ipsaver.h"

IPSaver* IPSaver::instance=NULL;

IPSaver::IPSaver() {
    read();
}

void IPSaver::read() {
    QString filename = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        QString line = "";
        line = stream.readLine();
        while(line!="") {
            hosts.append(line);
            line = stream.readLine();
        }
    }
}

void IPSaver::write() {
    QString filename = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite)) {
        QTextStream stream( &file );
        for(int i=0; i<hosts.length(); i++) {
            stream << hosts.at(i) << "\n";
        }
    }
}

void IPSaver::addNewHost(QString host) {
    if(!hosts.contains(host)) {
        getInstance()->hosts.append(host);
        write();
    }
}

IPSaver* IPSaver::getInstance() {
    if(!instance) {
        instance = new IPSaver();
    }
    return instance;
}

QString IPSaver::getMostRecentHost() {
    return getInstance()->getHosts().length()>0 ? getInstance()->getHosts().last() : "";
}

QList<QString> IPSaver::getHosts() {
    return getInstance()->hosts;
}
