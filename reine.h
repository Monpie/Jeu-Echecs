#ifndef REINE_H
#define REINE_H

 #include "piece.h"

class Reine : public Piece
{
public:
    Reine(QWidget *parent, QString color,int owner , int width, int height, int x,int y);
    void setImage(QString color);
    bool isValidMove();
    void move(int x, int y);
};

#endif // REINE_H
