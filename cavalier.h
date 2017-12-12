#ifndef CAVALIER_H
#define CAVALIER_H

#include "piece.h"

class Cavalier : public Piece
{
public:
    Cavalier(QWidget *parent, QString color,int owner , int width, int height, int x,int y);
    void setImage(QString color);
    void move(int x, int y);
    bool isValidMove(int x, int y);
};

#endif // CAVALIER_H
