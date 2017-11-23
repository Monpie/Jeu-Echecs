#ifndef ROI_H
#define ROI_H

#include "piece.h"
#include <QMouseEvent>

class Roi : public Piece
{
public:
    Roi(QWidget *parent, QString name, int width, int height, int x,int y);
    void move(int x, int y);
    void validClick(QMouseEvent *event);
    void isValidMove();
private:
    bool isClicked = false;
};

#endif // ROI_H
