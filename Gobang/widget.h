#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QLine>
#include <QLineF>
#include <QPointF>
#include <QPoint>
#include <QColor>
#include <QPen>
#include <QDebug>
#include <map>
#include "piece.h"
#include "piece.cpp"
#define ROW 17
#define COLUMN 17
#define SPACE 30

#define WIDTH 640
#define HEIGHT 480


#define CONVERT_POINT(x,y) {\
    int left_space=WIDTH-COLUMN*SPACE+SPACE;\
    int top_space=(HEIGHT-ROW*SPACE+SPACE)>>1;\
    x-=left_space;\
    y-=top_space;\
    int row=x/SPACE; \
    int column=y/SPACE;\
    int offset_x=x%30;\
    int offset_y=y%30;\
    if(offset_x/10==1 || offset_y/10==1)\
        return ;\
    if(offset_x/10==2)\
        row++;\
    if(offset_y/10==2)\
        column++;\
    x=row*30+left_space-RADIUS/2;\
    y=column*30+top_space-RADIUS/2;\
}
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void init();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    bool black;

    Piece<ROW,COLUMN> piece;
    QLineF lines[ROW*COLUMN];

};

#endif // WIDGET_H
