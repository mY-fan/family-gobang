#ifndef PIECE_H
#define PIECE_H
#include <QPainter>
#include <QDebug>
#define RADIUS 20


#define DETECT(x,y,offset_x,offset_y,black,count) {\
    int a=x;\
    int b=y;\
    a+=offset_x;\
    b+=offset_y;\
    for(;a>0 && a<=COLUMN && b>0 && b<=ROW && count<5;count++,a+=offset_x,b+=offset_y)\
        if(pieces[a][b]!=black)\
            break;\
}

template<int ROW,int COLUMN>
class Piece
{
public:
    Piece();

    bool add(int x,int y,bool black=true);
    int count();

    void draw_pieces(QPainter &painter,int width,int height,int space);

    void clear();

    bool is_win(int x,int y,bool black);
private:
    char pieces[COLUMN+1][ROW+1];
    int black_count;
    int white_count;


};

#endif // PIECE_H
