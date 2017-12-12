#ifndef ROI_H
#define ROI_H

#include "piece.h"
#include <QMouseEvent>

class Roi : public Piece
{
public:
    Roi(QWidget *parent, QString color,int my_owner, int width, int height, int x,int y);
    void move(int x, int y);
    bool validClick(QMouseEvent *event);
    bool isValidMove(int x, int y);
    void setImage(QString color);
    void setOldX(int x);
    void setOldY(int y);
    int getOldX();
    int getOldY();

    int getMyOwner();
private:
    bool isClicked = false;
    int oldX;
    int oldY;
    int my_owner;
};

#endif // ROI_H
