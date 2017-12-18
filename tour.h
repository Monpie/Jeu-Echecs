#ifndef TOUR_H
#define TOUR_H

#include "piece.h"

class Tour : public Piece
{
public:
    Tour(QWidget *parent, QString color,Player * owner , int width, int height, int x,int y);
    void setImage(QString image);
    void move(int x, int y);
    bool isValidMove(int x, int y,std::vector<Piece*> pieces);
    void updateAllPossibleMove(std::vector<Piece*> pieces);
    ~Tour();

private:
    bool verticalBlocked = false;
    bool horizontalBlocked = true;
};

#endif // TOUR_H
