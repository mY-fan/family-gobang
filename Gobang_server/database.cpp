#include "database.h"

Database::Database()
{   
}


Database::Database(const QString db_type,const QString db_name,const QString user_name,const QString user_passwd)
{
    db=QSqlDatabase::addDatabase(db_type);
    db.setHostName("localhost");
    db.setDatabaseName(db_name);
    db.setUserName(user_name);
    db.setPassword(user_passwd);
    try{
        if(!db.open())
            throw runtime_error("open database faile ");
        else
            cout << "open database success " ;
    }catch(runtime_error &error){
        cout << error.what() << endl;
    }
}

Database::~Database()
{
    db.close();
}

bool Database::create_table()
{
    QSqlQuery query=QSqlQuery(db);


    //detect tables is exist
    query.exec("show tables");
    if(query.size()==2)
        return true;

    if(!query.exec(CREATE_USER_INFORMATION)){
#ifndef DEBUG
        cout << "create user_information error " << endl;
#endif
        return false;
    }
    if(!query.exec(CREATE_FIGHT_HISTORY)){
#ifndef DEBUG
        cout << "create user_information error " << endl;
#endif
        return false;
    }
    return true;
}

bool Database::query_user(const QString &name,const QString &passwd)
{
    QSqlQuery query=QSqlQuery(db);
    QString str="select user_name from user_information where user_name = '" + name + "' and user_passwd='"+passwd+"'";
    query.exec(str);
    QSqlRecord rec = query.record();
    if(rec.count()>0){
        return true;
    }else
        return false;


}

bool Database::insert_user(const QString &name,const QString &passwd)
{
    QSqlQuery query=QSqlQuery(db);

    query.exec("select user_id from user_information where user_name='"+name+"'");
    if(query.size()==1)
        return false;
    QString str="insert into user_information (user_name,user_passwd) values('"+name+"','"+passwd+"')";

    if(query.exec(str))
        return true;
    else
        return false;
}

bool Database::user_information(const QString &user_name,User_information &info) const
{
    QSqlQuery query=QSqlQuery(db);
    QString str="select user_name,fight_count,win_count from user_information where user_name='"+user_name+"'";
    query.exec(str);
    QSqlRecord rec = query.record();
    int nameCol=rec.indexOf("user_name");
    if(query.next()){
        info.user_name=query.value(nameCol).toString();
        info.fight_count=query.value(1).toInt();
        info.win_count=query.value(2).toInt();
        return true;
    }else
        return false;


}
bool Database::fight_history(const QString &user_name,multimap<bool,QString> &mmap) const
{
    QSqlQuery query=QSqlQuery(db);
    QString str="select win,date from fight_history,user_information where user_information.user_id=fight_history.user_id and user_information.user_name='"+user_name+"'";
    if(!query.exec(str))
        return false;
    while(query.next()){
        bool b=query.value(0).toBool();
        QString str=query.value(1).toString();
        mmap.insert(make_pair(b,str));
    }
    return true;
}

