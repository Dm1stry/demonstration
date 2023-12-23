#include <iostream>
#include <QApplication>
#include <QLabel>
#include "udpconnection.hpp"

int main(int argc, char * argv[])
{
    std::cout << "UDP shit";
    QApplication app(argc, argv);
    UDPConnection * connection = new UDPConnection(QHostAddress(QHostAddress::LocalHost).toIPv4Address(), 5555, 7575);
    const char * msg = "Some message";
    QVector<QByteArray> data;
    //while(true)
    
        connection->sendData(msg);
        data = connection->receiveData();
        QLabel * lbl = new QLabel(QString(data[0]));
        lbl->show();
    
    app.exec();
    //std::cout << QString(data[0]).toStdString();
}