#ifndef TOUR_H
#define TOUR_H

#include "piece.h"

class Tour : public Piece
{
public:
    Tour(QWidget *parent, QString color,int owner , int width, int height, int x,int y);
    void setImage(QString image);
    void move(int x, int y);
    bool isValidMove();
};

#endif // TOUR_H
