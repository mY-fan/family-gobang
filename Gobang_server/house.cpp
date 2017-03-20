#include "house.h"

House::House()
{
}

House::House(QString bl,QString wh):black(bl),white(wh)
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    house_id = time.toString("yyyy-MM-dd hh:mm:ss"); //设置显示格式
}

House::House(const House &hou)
{
    this->house_id=hou.house_id;
    this->black=hou.black;
    this->white=hou.white;
    this->look_users=hou.look_users;
}

House& House::operator=(const House & hou)
{
    this->house_id=hou.house_id;
    this->black=hou.black;
    this->white=hou.white;
    this->look_users=hou.look_users;
    return *this;
}
