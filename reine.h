#ifndef REINE_H
#define REINE_H

 #include "piece.h"

class Reine : public Piece
{
public:
    Reine(QWidget *parent, QString color,Player * owner , int width, int height, int x,int y);
    void setImage(QString color);
    void move(int x, int y);
    bool isValidMove(int x, int y);
    ~Reine();
};

#endif // REINE_H
