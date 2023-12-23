#include <iostream>
#include <QApplication>
#include <QLabel>
#include "udpconnection.hpp"

int main(int argc, char * argv[])
{
    std::cout << "UDP connection started";
    QApplication app(argc, argv);
    UDPConnection * connection = new UDPConnection(QHostAddress(QHostAddress::LocalHost).toIPv4Address(), 5555, 7575);
    const char * msg = "Some message";
    //while(true)
    
    connection->sendData(msg);
    
    app.exec();
    //std::cout << QString(data[0]).toStdString();
}