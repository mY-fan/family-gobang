#include "piece.h"
template<int MAX>
Piece<MAX>::Piece()
{
    this->black_count=0;
    this->white_count=0;
}

template<int MAX>
bool Piece<MAX>::add(int x,int y,bool black)
{
    if(black==true){
        if(black_count>=MAX/2)
            return false;
        this->blacks[black_count].x=x;
        this->blacks[black_count].y=y;
        this->blacks[black_count].black=black;
        this->black_count++;
    }else{
        if(white_count>=MAX/2)
            return false;
        this->whites[white_count].x=x;
        this->whites[white_count].y=y;
        this->whites[white_count].black=black;
        this->white_count++;
    }
    return true;
}

template<int MAX>
int Piece<MAX>::count()
{
    return this->white_count+this->black_count;
}

template<int MAX>
void Piece<MAX>::draw_pieces(QPainter &painter)
{
    painter.setPen(Qt::white);
    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    for(int i=0;i<this->white_count;i++)
        painter.drawEllipse(whites[i].x,whites[i].y,RADIUS,RADIUS);
    painter.setPen(Qt::white);
    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    for(int i=0;i<this->black_count;i++)
        painter.drawEllipse(blacks[i].x,blacks[i].y,RADIUS,RADIUS);
}

template<int MAX>
void Piece<MAX>::clear()
{
    this->black_count=0;
    this->white_count=0;
}
