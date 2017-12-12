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
        this->namePiece = '3';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/tour_noir.png"));  //Image tour noire
        this->namePiece = 't';
    }
}

bool Tour::isValidMove(int x, int y){
    if((x!=this->tabPosX*TAILLECASE && y<(this->tabPosY+0.15)*TAILLECASE && y>(this->tabPosY-0.15)*TAILLECASE) || (y!=this->tabPosY*TAILLECASE && x<(this->tabPosX+0.15)*TAILLECASE && x>(this->tabPosX-0.15)*TAILLECASE))
        return true;
    else
        return false;
}

void Tour::move(int x, int y){
    if(this->isValidMove(x,y))
        this->lbl->move(x,y);
}


