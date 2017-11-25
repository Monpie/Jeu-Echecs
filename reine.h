#ifndef REINE_H
#define REINE_H

 #include "piece.h"

class Reine : public Piece
{
public:
    Reine(QWidget *parent, QString color, int width, int height, int x,int y);
    void setImage(QString color);
};

#endif // REINE_H
