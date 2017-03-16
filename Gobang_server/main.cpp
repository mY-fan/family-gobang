#include <QObject>
#include "database.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Database database("QSQLITE","gobang","mysql","mysql");


    cout << CREATE_USER_INFORMATION << endl;

/*
    if(database.create_table())
        cout << "create table success" << endl;
    else
        return 0;*/
    if(database.insert_user("ruibiao","123"))
        cout << "insert user success "  << endl;
    else
        cout << "insert error ";



    return 0;
}
