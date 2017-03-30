#include "piece.h"
template<int ROW,int COLUMN>
Piece<ROW,COLUMN>::Piece()
{
    this->black_count=0;
    this->white_count=0;

    for(int i=0;i<=COLUMN;i++)
        for(int j=0;j<=ROW;j++)
            pieces[i][j]=0;
}

template<int ROW,int COLUMN>
bool Piece<ROW,COLUMN>::add(int x,int y,bool black)
{
    x++;
    y++;
    if(x<=0 || x>COLUMN || y<=0 || y>ROW)
        return false;
    if(pieces[x][y]!=0)
        return false;

    if(black){
        pieces[x][y]=1;
        black_count++;
        if(is_win(x,y,black))
            qDebug() << "black win";

    }else{
        pieces[x][y]=-1;
        white_count++;
        if(is_win(x,y,black))
            qDebug() << "white win";

    }

    return true;
}

template<int ROW,int COLUMN>
int Piece<ROW,COLUMN>::count()
{
    return this->white_count+this->black_count;
}

template<int ROW,int COLUMN>
void Piece<ROW,COLUMN>::draw_pieces(QPainter &painter,int width,int height,int space)
{
    int left_space=width-COLUMN*space+space;
    int top_space=(height-ROW*space+space)/2;

    painter.setPen(Qt::white);
    painter.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    for(int i=1;i<=COLUMN;i++){
        for(int j=1;j<=ROW;j++){
            if(pieces[i][j]==-1)
                painter.drawEllipse((i-1)*space+left_space-RADIUS/2,(j-1)*space+top_space-RADIUS/2,RADIUS,RADIUS);
        }
    }

    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::black,Qt::SolidPattern));
    for(int i=1;i<=COLUMN;i++){
        for(int j=1;j<=ROW;j++){
            if(pieces[i][j]==1)
                painter.drawEllipse((i-1)*space+left_space-RADIUS/2,(j-1)*space+top_space-RADIUS/2,RADIUS,RADIUS);
        }
    }


}

template<int ROW,int COLUMN>
void Piece<ROW,COLUMN>::clear()
{
    this->black_count=0;
    this->white_count=0;
    for(int i=0;i<=COLUMN;i++)
        for(int j=0;j<=ROW;j++)
            pieces[i][j]=0;
}

template<int ROW,int COLUMN>
bool Piece<ROW,COLUMN>::is_win(int x,int y,bool black)
{
    if(black==true && black_count<5)
        return false;
    if(black==false && white_count<5)
        return false;

    int count=1;
    int bl;
    if(black)
        bl=1;
    else
        bl=-1;

    DETECT(x,y,-1,-1,bl,count);
    DETECT(x,y,1,1,bl,count);
    if(count>=5)
        return true;

    count=1;
    DETECT(x,y,1,-1,bl,count);
    DETECT(x,y,-1,1,bl,count);
    if(count>=5)
        return true;

    count=1;
    DETECT(x,y,0,1,bl,count);
    DETECT(x,y,0,-1,bl,count);
    if(count>=5)
        return true;

    count=1;
    DETECT(x,y,1,0,bl,count);
    DETECT(x,y,-1,0,bl,count);
    if(count>=5)
        return true;

    return false;

}
