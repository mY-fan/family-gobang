#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(WIDTH,HEIGHT);
    init();
}

Widget::~Widget()
{

}

void Widget::init()
{
    //init lines
    int left_space=WIDTH-COLUMN*SPACE+SPACE;
    int top_space=(HEIGHT-ROW*SPACE+SPACE)>>1;

    int num=0;
    for(int y=top_space,
        x0=left_space,
        x1=WIDTH;
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

    //black piece precede
    black=true;


}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::RightButton)
        return ;

    int x(event->x());
    int y(event->y());
    //convert mouse press point to piece point
    CONVERT_POINT(x,y);
    if(black){
        if(!piece.add(x,y,true))
            return ;
    }else{
        if(!piece.add(x,y,false))
            return ;
    }
    black=!black;
    update();
    return ;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    this->setStyleSheet("background-color:rgb(234,191,122)");

    QPainter p(this);
    QPen pen;
    pen.setWidth(2);
    p.setPen(pen);

    //draw gobang board
    p.drawLines(lines,ROW*COLUMN);
    //draw pieces
    piece.draw_pieces(p,WIDTH,HEIGHT,SPACE);
}
