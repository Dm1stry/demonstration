#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <QObject>
#include "udpconnection.hpp"
#include "basedevice.hpp"

class Operator : public QObject
{
Q_OBJECT
public:
    Operator(QObject * parent = nullptr);
public slots:
    void addDevice(BaseDevice * device);  //Добавить новое устройство
private slots:
    void sendCommand(QByteArray);  // Кослать команду через UDP на физическое устройство
    void sendData(QByteArray);  //Передать полученные от физического устройства данные, программным устройствам
signals:
    void newData(QByteArray);  // Сигнал о том, что получены новые данные, передается устройствам
    void newCommand(QByteArray);  // Сигнал о том, что получена новая команда для физического устройства (пока никуда не подключен, просто есть)
private:
    UDPConnection * connection_;  //Хранит подключение (сокет, порты и адрес)
    QVector<BaseDevice *> devices_;  //Массив указателей на устройства
};
#endif