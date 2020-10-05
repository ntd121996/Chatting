#include "worker.h"

Worker::Worker(int socketDescriptor, QObject *parent) :QObject(parent)
{
    this->socketDescriptor = socketDescriptor;
}
void Worker::ReadMessage()
{
    QByteArray data;
    qDebug() << this->socketDescriptor;
    if(this->tcpSocket->bytesAvailable())
    {
        data = this->tcpSocket->readAll();
    }
    emit this->haveMessage(data);
}
void Worker::sendTcp(QByteArray msg)
{
    this->tcpSocket->write(msg);
    emit this->sendSuccess();
}
void Worker::disconnect()
{
    this->tcpSocket->deleteLater();
    this->tcpSocket = 0;
    emit this->socketdisconnect();
}
void Worker::doWork()
{
    qDebug() << this->socketDescriptor;

    this->tcpSocket = new QTcpSocket();
    if(this->tcpSocket->setSocketDescriptor(this->socketDescriptor))
    {
        connect(this->tcpSocket,&QTcpSocket::readyRead,this,&Worker::ReadMessage,Qt::ConnectionType::DirectConnection);
        connect(this->tcpSocket,&QTcpSocket::disconnected,this,&Worker::disconnect);
    }

}
