#ifndef CAVALIER_H
#define CAVALIER_H

#include "piece.h"
#include "player.h"

class Cavalier : public Piece
{
public:
    Cavalier(QWidget *parent, QString color,Player * owner , int width, int height, int x,int y);
    void setImage(QString color);
    void move(int x, int y);
    bool isValidMove(int x, int y);
    ~Cavalier();
};

#endif // CAVALIER_H
