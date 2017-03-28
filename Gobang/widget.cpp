#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(WIDTH,HEIGHT);
    init();

    piece.add(20,20,false);

}

Widget::~Widget()
{

}

void Widget::init()
{
    //init lines
    int left_space=(WIDTH-COLUMN*SPACE+SPACE)>>1;
    int top_space=(HEIGHT-ROW*SPACE+SPACE)>>1;

    int num=0;
    for(int y=top_space,
        x0=left_space,
        x1=WIDTH-left_space;
        num<ROW;
        num++,
        y+=SPACE)
        lines[num].setLine(x0,y,x1,y);
    for(int x=left_space,
        y0=top_space,
        y1=HEIGHT-top_space;
        num<ROW+COLUMN;
        num++,
        x+=SPACE)
        lines[num].setLine(x,y0,x,y1);


}

void Widget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    this->setStyleSheet("background-color:rgb(234,191,122)");


    QPainter p(this);
    QPen pen;
    pen.setWidth(2);
    p.setPen(pen);
    p.drawLines(lines,ROW*COLUMN);

    piece.draw_pieces(p);
}
