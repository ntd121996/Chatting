#ifndef BACKEND_H
#define BACKEND_H
#include "myserver.h"

class Backend: public QObject
{
    Q_OBJECT
public:
    Backend(QObject *parent = 0);
    bool connection;
    Q_INVOKABLE QString onStartClicked();
    Q_INVOKABLE QString onCloseClicked();
    Q_INVOKABLE void onSendClicked(QByteArray msg);

signals:
    void closeConnection(QString msg);
    void haveMessage(QByteArray msg);
    void haveNewConnection(QString msg);
    void sendSuccess();

private:
    MyServer *myServer;
private slots:

    void NewConnection(QString msg);
    void NewMessage(QByteArray msg);
    void CloseDetected(QString msg);
    void onSendSuccess();
};

#endif // BACKEND_H
