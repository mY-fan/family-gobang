#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QString>
#include <QChar>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <vector>
#include <map>
using namespace std;
struct User_information
{
    QString user_name;
    unsigned int fight_count;
    unsigned int win_count;
};
#define TABLE1 "user_information"
#define TABLE2 "fight_histroy"

#define CREATE_USER_INFORMATION "create table user_information(\
user_id int unsigned not null auto_increment primary key,\
user_name char(20) not null,\
user_passwd char(20) not null,\
fight_count int unsigned not null default 0,\
win_count int unsigned not null default 0,\
);"
#define CREATE_FIGHT_HISTORY "create table fight_history(\
fight_id int unsigned not null auto_increment primary key,\
user_id int unsigned not null,\
win bool not null default 0,\
date date not null\
);"
class Database
{
public:
    Database(const QString db_type,const QString db_name,const QString user_name,const QString user_passwd);
    ~Database();

    bool create_table();

    bool query_user(const QString &name,const QString &passwd);
    bool insert_user(const QString &name,const QString &passwd);

    bool user_information(const QString &user_name,User_information &) const ;
    bool fight_history(const QString &user_name,multimap<bool,QString> &mmap) const ;

private:
    Database();
    Database(const Database &){}
    void operator=(const Database &){}

    QSqlDatabase db;
};

#endif // DATABASE_H
