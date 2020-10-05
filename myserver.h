#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <worker.h>

class MyServer:public QTcpServer
{
    Q_OBJECT
    Q_INVOKABLE
//    Q_PROPERTY(bool connection READ getConnection WRITE setConnection NOTIFY connectionChange)

public:
    MyServer(QObject *parent = nullptr);
    QString listenTcp();
    QString closeTcp();
    QTcpSocket *tcpSocketIO;
    void sendTcp(QByteArray msg);

public slots:
    void onDisconected();
    void onDetectNewConnection();
    void onReadyRead(QByteArray msg);
    void onSendSuccess();

signals:
    void connectionChange();
    void closeConnection(QString msg);
    void haveNewConnection(QString msg);
    void haveMessage(QByteArray msg);
    void SendMessage(QByteArray msg);
    void sendSuccess();
};

#endif // MYSERVER_H
