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
#include <map>
#include "piece.h"
#include "piece.cpp"
#define ROW 17
#define COLUMN 17
#define SPACE 30

#define WIDTH 640
#define HEIGHT 480


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

    Piece<(ROW-1)*(COLUMN-1)> piece;
    QLineF lines[ROW*COLUMN];
};

#endif // WIDGET_H
