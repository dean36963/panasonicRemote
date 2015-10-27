#include "remotewidget.h"

RemoteWidget::RemoteWidget(QString pathToConfig, QWidget *parent) : QWidget(parent) {
    this->configPath = pathToConfig;
    layout = new QGridLayout();
    setLayout(layout);
    initUi();
}

RemoteWidget::~RemoteWidget() {
    for(int i=0; i<buttons.length(); i++) {
        QPushButton * button = buttons.at(i);
        delete button;
    }
    delete layout;
}

void RemoteWidget::initUi() {
    QString path = QCoreApplication::applicationDirPath()
            .append(QDir::separator())
            .append(configPath);
    QDir configDir = QDir(path);
    if(!configDir.exists()) {
        cerr << "Couldn't init Remote ui as config dir "
             << path.toStdString()
             << " doesn't exist" << endl;
    }
    QDirIterator it(configDir,QDirIterator::NoIteratorFlags);
    while(it.hasNext()) {
        QString fileName = it.next();
        if(fileName.contains(".control")) {
            //RemoteButton handles the commandFile now.
            CommandFile *commandFile = new CommandFile(fileName,path);
            RemoteButton *button = new RemoteButton(commandFile,this);
            layout->addWidget(button,commandFile->getRow(),commandFile->getColumn(),1,1);
            //TODO Do some grid layout based on a commandfile property
            //TODO for connecting up these buttons, override the pushbutton
            //widget, connecting a slot to it's own selected signal
            //TODO also put an autorepeat option on the button to match a property on the commandfile
            buttons.push_back(button);
        }
    }
}
