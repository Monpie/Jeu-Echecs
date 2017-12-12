#include "reine.h"

Reine::Reine(QWidget *parent, QString color,int owner, int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->setImage(color);
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = owner;
}

void Reine::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/reine_blanc.png")); //Image tour blanche
        this->namePiece = '5';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/reine_noir.png"));  //Image tour noire
        this->namePiece = 'q';
    }
}



void Reine::move(int x, int y){
   // if(this->isValidMove())
        this->lbl->move(x,y);
}

bool Reine::isValidMove(int x, int y){
    return false;
}
