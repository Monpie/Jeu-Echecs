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
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/pion_noir.png"));  //Image tour noire
    }
}

void Pion::move(int x,int y){
    cout << "move PION appelé" << endl;
    if(this->isValidMove(x,y)){
        this->setTabPosX(x);
        this->setTabPosY(y);
        this->lbl->move(x,y);
    }
}

bool Pion::isValidMove(int x,int y){
    cout << "pion.getOldX()= " << this->getOldX()<< " x = "<< x<< endl;
    cout << "getoldX - x = " << this->getOldX()-x << endl;
    cout << "tabX/Taillecase  = " << this->getX()/TAILLECASE << endl;
    if(this->firstMove){
        if((this->getOldX()-x)<=150 && (this->getOldY()-y)<35){
            qDebug("First Move");
            //this->firstMove = false;
            return true;
        }
        else
            return false;
    }else{
        if((this->getOldX()-this->getX()<=75)) // && (this->getTabPosY()-this->getY())==0))
            return true;
        else
            return false;
    }
}

void Pion::firstMovePlayed(){
    this->firstMove = true;
}

