#include "remotebutton.h"

RemoteButton::RemoteButton(CommandFile *file, QWidget *parent) : QPushButton(parent) {
    this->file = file;
    setText(file->getLabel());
    connect(this,SIGNAL(clicked(bool)),this,SLOT(send(bool)));
}

RemoteButton::~RemoteButton() {
    delete file;
}

void RemoteButton::send(bool) {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl url = QUrl();
    url.setScheme(file->getScheme());
    //FIXME Needs autodetecting!
    url.setHost(file->getHost());
    url.setPort(file->getPort().toInt());
    url.setPath(file->getPath());
    cout << "Sending request for " << file->getLabel().toStdString() << endl;

    QNetworkRequest request = QNetworkRequest(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader,file->getContentTypeHeader());
    request.setHeader(QNetworkRequest::UserAgentHeader,file->getUserAgentHeader());
    QMap<QString,QString> otherHeaders = file->getRawHeaders();
    QList<QString> headers = otherHeaders.keys();
    for(int i=0; i<headers.length(); i++) {
        QString headerName = headers.at(i);
        QString headerValue = otherHeaders[headerName];
        request.setRawHeader(headerName.toLocal8Bit(),headerValue.toLocal8Bit());
    }
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(logResponse(QNetworkReply*)));

    manager->post(request,file->getDataFileContents().toLocal8Bit());
}

void RemoteButton::logResponse(QNetworkReply * reply) {
    int httpStatus = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if(httpStatus!=200) {
        cout << "http respons: " << httpStatus << endl;
        cout << "got response with error: " << reply->error() << endl;
    }
}
