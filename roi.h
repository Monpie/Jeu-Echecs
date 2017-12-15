#ifndef ROI_H
#define ROI_H

#include "piece.h"
#include <QMouseEvent>

class Roi : public Piece
{
public:
    Roi(QWidget *parent, QString color,Player * owner, int width, int height, int x,int y);
    void move(int x, int y);
    bool isValidMove(int x, int y);
    void setImage(QString color);
    bool isInDanger(int x, int y);
    ~Roi();
};

#endif // ROI_H
