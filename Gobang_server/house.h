#ifndef HOUSE_H
#define HOUSE_H

#include <QDateTime>
#include <QString>
#include <iostream>
#include <vector>
#include <map>
#include <QTcpSocket>
using namespace std;

class House
{
public:
    House(QString bl,QString wh);
    House(const House &hou);
    House &operator=(const House & hou);

    QString house_id;
    QString black;
    QString white;
    map<QString,QTcpSocket *> look_users;
private:
    House();
};

#endif // HOUSE_H
