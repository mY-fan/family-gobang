#include <QObject>
#include <QDebug>
#include "database.h"
#include "house.h"
int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Database db("QSQLITE","gobang","","");
    if(!db.create_table()){
        qDebug()<< "create table fail ";
        return 0;
    }

    if(!db.insert_user("fan2","123")){
        qDebug() << "insert data fail ";
        return 0;
    }



    User_information infor;
    QString name="fan2";
    if(db.user_information(name,infor))
        qDebug() << infor.user_name << endl <<
                infor.fight_count << endl <<
                infor.win_count << endl;

    return 0;
}
