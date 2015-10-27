#ifndef COMMANDFILE_H
#define COMMANDFILE_H

#include <QString>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QDir>

#include <iostream>

using namespace std;

/**
 * @brief The CommandFile class
 *
 * An object representing a command to send to the TV.
 */
class CommandFile
{
public:
    CommandFile(QString file, QString dir);
    QString getScheme();
    QString getHost();
    QString getPort();
    QString getPath();
    QString getContentTypeHeader();
    QString getUserAgentHeader();
    QMap<QString,QString> getRawHeaders();
    QFile* getDataFile();
    QString getDataFileContents();
    QString getLabel();
    int getRow();
    int getColumn();
private:
    void processLine(QString line);
    void processProperty(QString property, QString value);

    QString file;
    QString dir;

    QString scheme;
    QString host;
    QString port;
    QString path;

    QString contentTypeHeader;
    QString userAgentHeader;
    QMap<QString,QString> rawHeaders;

    QFile dataFile;

    QString label;
    int row;
    int column;
};

#endif // COMMANDFILE_H
