#include "fou.h"

Fou::Fou(QWidget *parent, QString color, int owner,  int width, int height, int x,int y)
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

void Fou::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/fou_blanc.png")); //Image tour blanche
        this->namePiece = '4';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/fou_noir.png"));  //Image tour noire
        this->namePiece = 'f';
    }
}

void Fou::move(int x, int y){
  //  if(this->isValidMove())
        this->lbl->move(x,y);
}

bool Fou::isValidMove(int x, int y){
    return false;
}
