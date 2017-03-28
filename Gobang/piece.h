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

template<int MAX>
class Piece
{
public:
    Piece();

    bool add(int x,int y,bool black=true);
    int count();

    void draw_pieces(QPainter &painter);

    void clear();

private:
    Point blacks[MAX/2];
    Point whites[MAX/2];
    int black_count;
    int white_count;

};

#endif // PIECE_H
