#include <QApplication>
#include "client/client.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    UdpClient * client = new UdpClient();
    client->show(); 
    app.exec();
}