#include "case.h"

Case::Case(int size, int xPos, int yPos)
{
    this->size = size;
    this->xPos = xPos+CHESSBOARD_POS.x();
    this->yPos = yPos+CHESSBOARD_POS.y();
}



    void Case::draw(QPainter *painter, QColor color)
    {
        QRect r1(this->xPos,this->yPos,this->size,this->size);
        painter->setPen(Qt::black);
        painter->setBrush(color);
        painter->drawRect(r1);
    }


