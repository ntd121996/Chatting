#include "myserver.h"

MyServer::MyServer(QObject *parent):QTcpServer(parent)
{
}
//function
QString MyServer::listenTcp()
{
    if( this->listen(QHostAddress::Any,8000))
    {
        connect( this,&QTcpServer::newConnection,this,&MyServer::onDetectNewConnection);
        return " Server is listen....";
    }
    return " Server is listen already!!!";
}
QString MyServer::closeTcp()
{   
    disconnect(this,&QTcpServer::newConnection,this,&MyServer::onDetectNewConnection);
    this->close();
    return "Server is close sucess";

}
void MyServer::sendTcp(QByteArray msg)
{
    emit SendMessage(msg);
}

//slot
void MyServer::onDetectNewConnection()
{
    Worker *TcpWorker = new Worker( this->nextPendingConnection()->socketDescriptor());
    QThread *mythread = new QThread();


    connect(mythread,&QThread::finished,mythread,&QThread::deleteLater);
    connect(mythread,&QThread::started,TcpWorker,&Worker::doWork);
    connect(TcpWorker,&Worker::haveMessage,this,&MyServer::onReadyRead);
    connect(TcpWorker,&Worker::socketdisconnect,this,&MyServer::onDisconected);
    connect(TcpWorker,&Worker::sendSuccess,this,&MyServer::onSendSuccess);

    connect(this,&MyServer::SendMessage,TcpWorker,&Worker::sendTcp);
    TcpWorker->moveToThread(mythread);
    mythread->start();
    emit this->haveNewConnection("New Connection");

}
void MyServer::onDisconected()
{
    emit MyServer::closeConnection("Client has disconected");
}

void MyServer::onReadyRead(QByteArray buffer)
{
    emit MyServer::haveMessage(buffer);
}
void MyServer::onSendSuccess()
{
    emit sendSuccess();
}





