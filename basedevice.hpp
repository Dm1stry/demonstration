#ifndef BASE_DEVICE_HPP
#define BASE_DEVICE_HPP

#include <QObject>
#include <QByteArray>

//Базовый класс устройства

class BaseDevice : public QObject
{
Q_OBJECT
public:
    BaseDevice(QObject * parent = nullptr);
    virtual ~BaseDevice();
    bool setAddress();  //Устанавливает значение адреса данного устройства на шине
    quint8 getAddress();  //Возвращает адрес данного устройства
public slots:
    virtual void processData(QByteArray data) = 0;  //Обрабатывает данные, пришедшие от класса опреатора, в том числе проверяет принадлежность
signals:
    Q_SIGNAL void newCommand(QByteArray command);  //Сигнал, несущий команду, которую мы хотим послать физическому устройству
protected:
    quint8 address_;  //Байт адреса устройства
};

#endif