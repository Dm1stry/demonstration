#include "operator.hpp"

Operator::Operator(QObject * parent)
  : QObject(parent)
{
    connect(connection_, &UDPConnection::newData, this, &Operator::newData);
}

void Operator::addDevice(BaseDevice * device)
{
    devices_.push_back(device);
    connect(this, &Operator::newData, device, &BaseDevice::processData);
    connect(device, &BaseDevice::newCommand, this, &Operator::sendCommand);
}

void Operator::sendCommand(QByteArray command)
{
    connection_->sendData(command);
    emit newCommand(command);
}

void Operator::sendData(QByteArray data)
{
    emit newData(data);
}

