#include "cavalier.h"

Cavalier::Cavalier(QWidget *parent, QString color, int owner , int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->setImage(color);
    this->name = name;
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = owner;
}

void Cavalier::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/cavalier_blanc.png")); //Image tour blanche
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/cavalier_noir.png"));  //Image tour noire
    }
}

