#include "pion.h"

Pion::Pion(QWidget *parent,QString name, QString color, int width, int height, int x,int y)
{
    this->name = name;
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
}
