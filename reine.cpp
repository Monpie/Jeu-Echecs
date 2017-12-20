#include "reine.h"

Reine::Reine(QWidget *parent, QString color,Player * owner, int width, int height, int x,int y)
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
    this->lbl->move(x*TAILLECASE+25,y*TAILLECASE);
    this->setTabPosX(x);
    this->setTabPosY(y);
}

bool Reine::isValidMove(int x, int y,std::vector<Piece*> pieces){
    if( this->checkIfMate(x,y) && ((x!=this->tabPosX*TAILLECASE && y==this->tabPosY) && this->moveInBoard(x,y) || (abs(x-this->tabPosX)==abs(y-this->tabPosY)) || (x==this->tabPosX && y != this->tabPosY)&& this->moveInBoard(x,y)) && (x!=this->tabPosX || y!=this->tabPosY))
        return true;
    else
        return false;
}

Reine::~Reine(){
    delete this->lbl;
}
