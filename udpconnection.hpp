#ifndef UDP_CONNECTION_HPP
#define UDP_CONNECTION_HPP

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QVector>
#include <memory>

class UDPConnection : public QObject
{
Q_OBJECT
public:
    UDPConnection(QObject * parent = nullptr);
    UDPConnection(quint32 destination_ip4, qint16 destination_port, qint16 source_port, QObject * parent = nullptr);
    bool setDestinationPort(qint16 destination_port);
    bool setDestinationIP(quint32 destination_ip4);
    bool setDestinationIP(QHostAddress destination_address);
    bool setSourcePort(qint16 source_port);
    bool startConnection();
    QVector<QByteArray> receiveData();
    bool sendData(QByteArray data);
private slots:
    void collectData();
signals:
    void newData();
private:
    QVector<QByteArray> received_data_;
    QUdpSocket * socket_;
    QHostAddress connected_ip4_;
    qint16 connected_port_;
};
#endif