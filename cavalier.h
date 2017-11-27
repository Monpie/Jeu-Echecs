#ifndef CAVALIER_H
#define CAVALIER_H

#include "piece.h"

class Cavalier : public Piece
{
public:
    Cavalier(QWidget *parent, QString color, int width, int height, int x,int y);
    void setImage(QString color);
};

#endif // CAVALIER_H
