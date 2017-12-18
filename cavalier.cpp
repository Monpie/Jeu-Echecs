#include "cavalier.h"

Cavalier::Cavalier(QWidget *parent, QString color, Player * owner , int width, int height, int x,int y)
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

void Cavalier::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/cavalier_blanc.png")); //Image tour blanche
        this->namePiece = '2';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/cavalier_noir.png"));  //Image tour noire
        this->namePiece = 'c';
    }
}


void Cavalier::move(int x, int y){
    this->lbl->move(x*TAILLECASE+25,y*TAILLECASE);
    this->setTabPosX(x);
    this->setTabPosY(y);
}

bool Cavalier::isValidMove(int x, int y,std::vector<Piece*> pieces){
    if((abs(x-this->tabPosX)==2 && abs(y-this->tabPosY)==1 || abs(x-this->tabPosX)==1 && abs(y-this->tabPosY)==2) && this->moveInBoard(x,y) && this->checkIfMate(x,y))
        return true;
    else
        return false;
}

Cavalier::~Cavalier(){
    delete this->lbl;
}
