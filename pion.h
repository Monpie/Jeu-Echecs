#ifndef PION_H
#define PION_H

#include "piece.h"

class Pion : public Piece
{
public:
    Pion(QWidget *parent, QString name, QString color, int width, int height, int x,int y);
};

#endif // PION_H
