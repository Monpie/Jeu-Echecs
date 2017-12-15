#ifndef FOU_H
#define FOU_H

#include "piece.h"

class Fou : public Piece
{
public:
    Fou(QWidget *parent, QString color,Player * owner , int width, int height, int x,int y);
    void setImage(QString color);
    void move(int x, int y);
    bool isValidMove(int x, int y);
    ~Fou();
};

#endif // FOU_H
