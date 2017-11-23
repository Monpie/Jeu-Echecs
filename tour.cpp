#include "tour.h"

Tour::Tour(QWidget *parent,QString name, QString color, int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->lbl->setPixmap(QPixmap(":/images/piece.jpg"));
    this->name = name;
    this->width = width;
    this->height = height;
    this->color = color;
    this->x = x;
    this->y = y;
}

void Tour::setImage(QString color){
    if(color.compare("TB")){
        //this->lbl->setPixmap(); //Image tour blanche
    }else if(color.compare("TN")){
        //Image tour noire
    }else{
        //erreu
    }
}
