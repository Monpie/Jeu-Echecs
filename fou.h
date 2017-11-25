#ifndef FOU_H
#define FOU_H

#include "piece.h"

class Fou : public Piece
{
public:
    Fou(QWidget *parent, QString color, int width, int height, int x,int y);
    void setImage(QString color);
};

#endif // FOU_H
