#include "mythread.h"

MyThread::MyThread( int socketDescriptor, QObject *parent ):QThread(parent)
{
    this->socketDescriptor = socketDescriptor;

}
void MyThread::OnRun()
{
    this->tcpSocketIO = new QTcpSocket();
    this->tcpSocketIO->setSocketDescriptor(this->socketDescriptor);
    connect(this->tcpSocketIO,&QIODevice::readyRead,this,&MyThread::ReadMessage,Qt::DirectConnection);
    connect(this->tcpSocketIO,&QAbstractSocket::disconnected,this,&MyThread::disconnect);
    qDebug() << socketDescriptor;
//    this->exec();
}
void MyThread::ReadMessage()
{
    qDebug() << this->currentThreadId();
    QByteArray data;
    if( this->tcpSocketIO->bytesAvailable())
    {
        data = this->tcpSocketIO->readAll();
    }
    emit haveMessage(data);
}
void MyThread::disconnect()
{
    this->tcpSocketIO->close();
    this->tcpSocketIO->deleteLater();
    emit socketdisconnect();
    this->quit();
}
void MyThread::sendTcp(QByteArray msg)
{
    if( this->tcpSocketIO != nullptr )
    {
        this->tcpSocketIO->write(msg);
    }
    emit sendSuccess();

}



