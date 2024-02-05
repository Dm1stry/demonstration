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
    UDPConnection(QObject * parent = nullptr);  //Создает сокет, но не биндит его
    UDPConnection(quint32 destination_ip4, qint16 destination_port, qint16 source_port, QObject * parent = nullptr);  //Создает и бандит сокет
    bool setDestinationPort(qint16 destination_port);
    bool setDestinationIP(quint32 destination_ip4);
    bool setDestinationIP(QHostAddress destination_address);
    bool setSourcePort(qint16 source_port);
    bool startConnection();  //Начать подключение
    QVector<QByteArray> receiveData();  // Получает всё, что успело придти через соединение
    bool sendData(QByteArray data);  //Посылает данные через соединение
private slots:
    void collectData();  // Слот, чтобы копировать всё что приходило на сокет и сохранять в буффере
signals:
    void newData();  //Сигнал о том, что появились новые данные
private:
    QVector<QByteArray> received_data_;  //Буффер полученных данных
    QUdpSocket * socket_;  //Сокет
    QHostAddress connected_ip4_;  //IPv4 устройства, куда мы отправляем
    qint16 connected_port_;  //Порт на устройстве, куда мы отправляем
    qint16 source_port_;  //Порт на котором мы слушаем
};
#endif