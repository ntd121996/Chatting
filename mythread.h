#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class MyThread: public QThread
{
    Q_OBJECT
public:
    MyThread( int socketDescriptor,QObject *parent = 0);




signals:
    void haveMessage( QByteArray msg);
    void socketdisconnect();
    void sendSuccess();
public slots:
    void sendTcp(QByteArray msg);
    void ReadMessage();
    void disconnect();
    void OnRun();
private:
    QTcpSocket *tcpSocketIO;
    int         socketDescriptor;
};

#endif // MYTHREAD_H
