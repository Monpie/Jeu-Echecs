#ifndef PION_H
#define PION_H

#include "piece.h"
#include "constante.h"

class Pion : public Piece
{
public:
    Pion(QWidget *parent, QString color, int owner, int width, int height, int x,int y);
    void setImage(QString color);
    void move(int x, int y);
    bool isValidMove(int x, int y);
    void firstMovePlayed();
    ~Pion();

private:
    bool firstMove = true;
};

#endif // PION_H
