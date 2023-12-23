#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <QObject>
#include "udpconnection.hpp"

class Operator : public QObject
{
public:
    Operator(QObject * parent = nullptr);
private:
    UDPConnection * connection_;
};
#endif