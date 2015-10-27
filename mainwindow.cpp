#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->parent = parent;
    //TODO setup menus
    initUi();
}

MainWindow::~MainWindow() {
    delete remoteWidget;
}

void MainWindow::initUi() {
    //Create a widget to hold lots of buttons
    QString path = QString("res")
                .append(QDir::separator())
                .append("panasonic_viera_e_series");
    remoteWidget = new RemoteWidget(path);
    //Set this widget as the main menu
    setCentralWidget(remoteWidget);

//    QPushButton * testButton = new QPushButton(parent);
//    testButton->setText("Test");
//    connect(testButton,SIGNAL(clicked(bool)),this,SLOT(testSelected()));
//    setCentralWidget(testButton);
}

void MainWindow::testSelected() {
    //TODO move this completely to some other class
    cout << "test" << endl;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
//    QUrl url = QUrl("http://192.168.0.7:55000/nrc/control_0");
    QUrl url = QUrl();
    url.setScheme("http");
    url.setHost("192.168.0.7");
    url.setPort(55000);
    url.setPath("/nrc/control_0");

    cout << "Url: " << url.toString().toStdString() << endl;

    QNetworkRequest request = QNetworkRequest(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader,"text/xml");
    request.setHeader(QNetworkRequest::UserAgentHeader,"Panasonic Android VR-CP UPnP/2.0");
    request.setRawHeader("SOAPACTION","\"urn:panasonic-com:service:p00NetworkControl:1#X_SendKey\"");


    QString xml = QString::fromLocal8Bit("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
    xml.append("<s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\">");
    xml.append("<s:Body>");
    xml.append("<u:X_SendKey xmlns:u=\"urn:panasonic-com:service:p00NetworkControl:1\">");
    xml.append("<X_KeyEvent>NRC_DOWN-ONOFF</X_KeyEvent>");
    xml.append("</u:X_SendKey>");
    xml.append("</s:Body>");
    xml.append("</s:Envelope>");
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(testFinished(QNetworkReply*)));

    QByteArray b = xml.toLocal8Bit();

    manager->post(request,b);
//    delete manager;
}

void MainWindow::testFinished(QNetworkReply * reply) {
    cout << "http respons: " << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() << endl;
    cout << "got response with error: " << reply->error() << endl;
}
