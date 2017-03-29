#ifndef PIECE_H
#define PIECE_H
#include <QPainter>

#define RADIUS 20
struct Point
{
    int x;
    int y;
    bool black;
};

template<int ROW,int COLUMN>
class Piece
{
public:
    Piece();

    bool add(int x,int y,bool black=true);
    int count();

    void draw_pieces(QPainter &painter);

    void clear();

    bool is_win(int x,int y,bool black);
private:
    Point blacks[ROW*COLUMN/2];
    Point whites[ROW*COLUMN/2];
    int black_count;
    int white_count;


};

#endif // PIECE_H
