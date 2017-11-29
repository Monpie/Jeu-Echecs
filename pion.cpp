#include "pion.h"
#include "math.h"

Pion::Pion(QWidget *parent, QString color, int owner,  int width, int height, int x,int y)
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



void Pion::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/pion_blanc.png")); //Image tour blanche
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/pion_noir.png"));  //Image tour noire
    }
}

void Pion::move(int x,int y){
    this->setTabPosX(x);
    this->setTabPosY(y);
    this->lbl->move(x*75,y*75);
}

bool Pion::isValidMove(){
    if(this->firstMove){
        if((this->getTabPosX()-this->getX())<=2 && (this->getTabPosY()-this->getY())==0){
            this->firstMove = false;
            return true;
        }
        else
            return false;
    }else{
        if((this->getTabPosX()-this->getX()==1 && (this->getTabPosY()-this->getY())==0))
            return true;
        else
            return false;
    }
}


