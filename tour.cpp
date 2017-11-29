#include "tour.h"

Tour::Tour(QWidget *parent, QString color, int owner,  int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->setImage(color);
    this->width = width;
    this->height = height;
    this->color = color;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = owner;
}

void Tour::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/tour_blanc.png")); //Image tour blanche
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/tour_noir.png"));  //Image tour noire
    }
}

bool Tour::isValidMove(){
    if((this->getX()>0 && this->getX()<800 && this->getY()> this->getOldY()-25 && this->getY() <this->getOldY()+25) || (this->getY()>0 && this->getY()<800 && this->getX()> this->getOldX()-25 && this->getX() <this->getOldX()+25))
        return true;
    else
        return false;
}
