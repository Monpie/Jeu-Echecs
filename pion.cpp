#include "pion.h"
#include "math.h"
#include "iostream"
using namespace std;

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
        this->namePiece = '1';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/pion_noir.png"));  //Image tour noire
        this->namePiece = 'p';
    }
}

void Pion::move(int x,int y){
    if(this->isValidMove(x,y)){
        this->lbl->move(x,y);
    }
}

bool Pion::isValidMove(int x,int y){
    if(this->firstMove){
        if(y<(this->tabPosY+2)*TAILLECASE && x<(this->tabPosX+0.5)*TAILLECASE && x>(this->tabPosX-0.15)*TAILLECASE ){
            cout << "y = " << y << "tabPos = " << this->tabPosY << endl;
            //this->firstMove = false;
            return true;
        }
        else
            return false;
    }else{
        if(y<(this->tabPosY+1)*TAILLECASE && x<(this->tabPosX+0.5)*TAILLECASE && x>(this->tabPosX-0.15)*TAILLECASE) // && (this->getTabPosY()-this->getY())==0))
            return true;
        else
            return false;
    }
}

void Pion::firstMovePlayed(){
    this->firstMove = false;
}


