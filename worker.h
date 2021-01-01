#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
class Worker: public QObject
{
    Q_OBJECT
public:
    Worker(int socketDescriptor, QObject *parent = 0);

signals:
    void haveMessage( QByteArray msg);
    void socketdisconnect();
    void sendSuccess();

public slots:
    void sendTcp(QByteArray msg);
    void ReadMessage();
    void disconnect();
    void doWork();



private:
    QTcpSocket *tcpSocket;
    QVariant socketDescriptor;
};

#endif // WORKER_H
