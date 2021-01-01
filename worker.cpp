#include "worker.h"

Worker::Worker(int socketDescriptor, QObject *parent) :QObject(parent)
{
    this->socketDescriptor = socketDescriptor;
}
void Worker::ReadMessage()
{
    QByteArray array;
    array.append("From ");
    array.append(this->socketDescriptor.toString());
    array.append(":");
    if(this->tcpSocket->bytesAvailable())
    {
        array.append(this->tcpSocket->readAll());
    }

    qDebug()<< array;
    emit this->haveMessage(array);
}
void Worker::sendTcp(QByteArray msg)
{
    QByteArray dataout;
    QDataStream out(&dataout,QIODevice::WriteOnly);
    out.setByteOrder(QDataStream::BigEndian);
    out << msg;
    this->tcpSocket->write(dataout);
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
    if(this->tcpSocket->setSocketDescriptor(this->socketDescriptor.toInt()))
    {
        connect(this->tcpSocket,&QTcpSocket::readyRead,this,&Worker::ReadMessage,Qt::ConnectionType::DirectConnection);
        connect(this->tcpSocket,&QTcpSocket::disconnected,this,&Worker::disconnect);
    }

}
