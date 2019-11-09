#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QTcpSocket>

class SocketTest : public QObject
{
    Q_OBJECT
public:
    explicit SocketTest(QObject *parent = nullptr);

    void Connect();

signals:

public slots:

private:
    QTcpSocket *socket;

};

#endif // SOCKETTEST_H
