#include "reine.h"

Reine::Reine(QWidget *parent, QString color, int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->setImage(color);
    this->name = name;
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
}

void Reine::setImage(QString color){
    if(color.compare("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/pion_blanc.png")); //Image tour blanche
    }else if(color.compare("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/pion_noir.png"));  //Image tour noire
    }
}
