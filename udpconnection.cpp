#include "udpconnection.hpp"

UDPConnection::UDPConnection(QObject * parent)
  : QObject(parent)
{
    socket_ = new QUdpSocket(this);
    connect(socket_, &QUdpSocket::readyRead, this, &UDPConnection::collectData);
}

UDPConnection::UDPConnection(quint32 destination_ip4, qint16 destination_port, qint16 source_port, QObject * parent)
  : QObject(parent),
    connected_ip4_(QHostAddress(destination_ip4)),
    connected_port_(destination_port)
{
    socket_ = new QUdpSocket(this);
    socket_->bind(QHostAddress::LocalHost, source_port);
    connect(socket_, &QUdpSocket::readyRead, this, &UDPConnection::collectData);
}

bool UDPConnection::setDestinationPort(qint16 destination_port)
{
    connected_port_ = destination_port;
    return true;  //Возможна проверка валидности порта
}

bool UDPConnection::setDestinationIP(quint32 destination_ip4)
{
    return this->setDestinationIP(QHostAddress(destination_ip4));
}

bool UDPConnection::setDestinationIP(QHostAddress destination_address)
{
    connected_ip4_ = destination_address;
    return true;  //Возможна проверка валидности адреса
}

bool UDPConnection::setSourcePort(qint16 source_port)
{
    source_port_ = source_port;
}

bool UDPConnection::startConnection()
{
    //Тут стоит добавить проверку, все ли значения установлены
    socket_->close();
    return socket_->bind(QHostAddress::LocalHost, source_port_);
}

QVector<QByteArray> UDPConnection::receiveData()
{
    QVector<QByteArray> data = received_data_;
    received_data_.clear();
    return data;
}

void UDPConnection::collectData()
{
    while(socket_->hasPendingDatagrams())// Есть дейтаграмма для чтения
    {
        QNetworkDatagram datagram = socket_->receiveDatagram();

        if(datagram.isValid() && datagram.senderAddress() == connected_ip4_ && datagram.senderPort())
        {
            received_data_.push_back(datagram.data());
        }
    }
}

bool UDPConnection::sendData(QByteArray data)
{
    qint64 send_bytes = socket_->writeDatagram(data, connected_ip4_, connected_port_);
    if(send_bytes != data.size())
    {
        return false;
    }
    return true;
}
