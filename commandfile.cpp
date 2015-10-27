#include "commandfile.h"

CommandFile::CommandFile(QString file, QString dir) {
    this->file = file;
    this->dir = dir;
    cout << "Attempting to open: " << file.toStdString() << endl;
    QFile qFile(file);

    if(qFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&qFile);
        while(!in.atEnd()) {
            QString line = in.readLine();
            processLine(line);
        }
        qFile.close();
    }
}

void CommandFile::processLine(QString line) {
    if(!line.contains('=')) {
        return;
    }
    QStringList tokenisedString = line.split('=');
    if(tokenisedString.length()<2) {
        return;
    }
    QString property = tokenisedString.at(0);
    tokenisedString.removeFirst();
    int i=0;
    QString value = tokenisedString.at(i);
    i++;
    while(i<tokenisedString.length()) {
        value = value.append('=')
                .append(tokenisedString.at(i));
    }
    processProperty(property,value);
}

void CommandFile::processProperty(QString property, QString value) {
    if(property==NULL) {
        return;
    } else if(property=="scheme") {
        scheme = value;
    } else if(property=="host") {
        host = value;
    } else if(property=="port") {
        port = value;
    } else if(property=="path") {
        path = value;
    } else if(property=="user.agent") {
        userAgentHeader = value;
    } else if(property=="content.type") {
        contentTypeHeader = value;
    } else if(property=="data") {
        QString path = dir.append(QDir::separator())
                .append(value);
        dataFile.setFileName(path);
    } else if(property.contains("header.")) {
        QStringList list = property.split('.');
        QString header = list.at(1);
        rawHeaders.insert(header,value);
    } else if(property=="label") {
        label = value;
    } else if(property=="row") {
        row = value.toInt();
    } else if(property=="column") {
        column = value.toInt();
    }
}

QString CommandFile::getDataFileContents() {
    QString dataContents;
    if(dataFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&dataFile);
        while(!in.atEnd()) {
            dataContents.append(in.readLine());
        }
        dataFile.close();
    }
    return dataContents;
}

//Boring Getters
QString CommandFile::getScheme() {
    return scheme;
}
QString CommandFile::getHost() {
    return host;
}
QString CommandFile::getPort() {
    return port;
}
QString CommandFile::getPath() {
    return path;
}
QString CommandFile::getContentTypeHeader() {
    return contentTypeHeader;
}
QString CommandFile::getUserAgentHeader() {
    return userAgentHeader;
}
QMap<QString,QString> CommandFile::getRawHeaders() {
    return rawHeaders;
}
QFile* CommandFile::getDataFile() {
    return &dataFile;
}
QString CommandFile::getLabel() {
    return label;
}
int CommandFile::getRow() {
    return row;
}
int CommandFile::getColumn(){
    return column;
}
