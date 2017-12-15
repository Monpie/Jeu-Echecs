#include "tour.h"

Tour::Tour(QWidget *parent, QString color, Player * owner,  int width, int height, int x,int y)
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
    if(((x!=this->tabPosX && y==this->tabPosY) || (x==this->tabPosX && y != this->tabPosY)) && this->moveInBoard(x,y))
        return true;
    else
        return false;
}

void Tour::move(int x, int y){
    this->lbl->move(x*TAILLECASE+25,y*TAILLECASE);
    this->setTabPosX(x);
    this->setTabPosY(y);
}


Tour::~Tour(){
    delete this->lbl;
}
