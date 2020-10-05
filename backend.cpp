#include "backend.h"

Backend::Backend(QObject *parent):QObject(parent)
{
    this->myServer = new MyServer(this);
    connect(this->myServer,&MyServer::haveNewConnection,this,&Backend::NewConnection);
    connect(this->myServer,&MyServer::haveMessage,this,&Backend::NewMessage);
    connect(this->myServer,&MyServer::closeConnection,this,&Backend::CloseDetected);
    connect(this->myServer,&MyServer::sendSuccess,this,&Backend::onSendSuccess);
}
QString Backend::onCloseClicked()
{
    return this->myServer->closeTcp();
}
QString Backend::onStartClicked()
{
    return this->myServer->listenTcp();
}
void Backend::onSendClicked(QByteArray msg)
{
    this->myServer->sendTcp(msg);
}

void Backend::NewConnection(QString msg)
{
    emit haveNewConnection(msg);
}
void Backend::NewMessage(QByteArray msg )
{
    emit haveMessage( msg );
}
void Backend::CloseDetected(QString msg)
{
    emit closeConnection(msg);
}
void Backend::onSendSuccess()
{
    emit sendSuccess();
}

