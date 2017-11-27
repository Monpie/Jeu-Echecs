#ifndef FOU_H
#define FOU_H

#include "piece.h"

class Fou : public Piece
{
public:
    Fou(QWidget *parent, QString color,int owner , int width, int height, int x,int y);
    void setImage(QString color);
    void move(int x, int y);
};

#endif // FOU_H
