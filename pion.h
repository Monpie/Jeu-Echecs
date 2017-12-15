#ifndef PION_H
#define PION_H

#include "piece.h"
#include "constante.h"
#include "QPoint"
#include "chessboard.h"

class Pion : public Piece
{
public:
    Pion(QWidget *parent, QString color, Player * owner, int width, int height, int x,int y);
    void setImage(QString color);
    void move(int x, int y);
    bool isValidMove(int x, int y);
    void firstMovePlayed();
    bool canAttack(char chessboard[8][8]);
    bool checkIfMate(int x, int y);
    ~Pion();

private:
    bool firstMove = true;

};

#endif // PION_H
