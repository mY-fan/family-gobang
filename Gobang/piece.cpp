#include "piece.h"
template<int ROW,int COLUMN>
Piece<ROW,COLUMN>::Piece()
{
    this->black_count=0;
    this->white_count=0;


}

template<int ROW,int COLUMN>
bool Piece<ROW,COLUMN>::add(int x,int y,bool black)
{
    for(int i=0;i<white_count;i++)
        if(whites[i].x==x && whites[i].y==y)
            return false;
    for(int i=0;i<black_count;i++)
        if(blacks[i].x==x && blacks[i].y==y)
            return false;


    if(black==true){
        if(black_count>=ROW*COLUMN/2)
            return false;
        this->blacks[black_count].x=x;
        this->blacks[black_count].y=y;
        this->blacks[black_count].black=black;
        this->black_count++;


    }else{
        if(white_count>=ROW*COLUMN/2)
            return false;
        this->whites[white_count].x=x;
        this->whites[white_count].y=y;
        this->whites[white_count].black=black;
        this->white_count++;

    }
    return true;
}

template<int ROW,int COLUMN>
int Piece<ROW,COLUMN>::count()
{
    return this->white_count+this->black_count;
}

template<int ROW,int COLUMN>
void Piece<ROW,COLUMN>::draw_pieces(QPainter &painter)
{
    painter.setPen(Qt::white);
    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    for(int i=0;i<this->white_count;i++)
        painter.drawEllipse(whites[i].x,whites[i].y,RADIUS,RADIUS);
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    for(int i=0;i<this->black_count;i++)
        painter.drawEllipse(blacks[i].x,blacks[i].y,RADIUS,RADIUS);
}

template<int ROW,int COLUMN>
void Piece<ROW,COLUMN>::clear()
{
    this->black_count=0;
    this->white_count=0;
}

template<int ROW,int COLUMN>
bool Piece<ROW,COLUMN>::is_win(int x,int y,bool black)
{
    if(black==true && black_count<5)
        return false;
    if(black==false && white_count<5)
        return false;
    int row,column,count;


#define DETECT(x,y,black,offsetx,offsety,count) {\
    while(x>0 && x<=ROW && y>0 && y<=COLUMN)


}
