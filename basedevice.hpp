#ifndef BASE_DEVICE_HPP
#define BASE_DEVICE_HPP

#include <QObject>
#include <QByteArray>

class BaseDevice : public QObject
{
Q_OBJECT
public:
    BaseDevice(QObject * parent = nullptr);
    virtual ~BaseDevice();
    bool setAddress();
    quint8 getAddress();
public slots:
    virtual void processData(QByteArray data);
signals:
    Q_SIGNAL void newCommand(QByteArray command);
protected:
    quint8 address_;
};

#endif