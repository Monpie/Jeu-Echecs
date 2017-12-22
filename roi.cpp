#include "roi.h"
#include <QDebug>
#include "case.h"

Roi::Roi(QWidget *parent, QString color,Player * owner, int width, int height, int x, int y)
{
    this->lbl = new QLabel(parent);
    this->lbl->setPixmap(QPixmap(":/images/Pieces/roi_blanc.png"));
    this->setImage(color);
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = owner;
    this->isKing = true;
}

void Roi::move(int x,int y){
    this->lbl->move(x*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),y*TAILLECASE+CHESSBOARD_POS.y());
    this->setTabPosX(x);
    this->setTabPosY(y);
}

bool Roi::isValidMove(int x,int y,std::vector<Piece*> pieces){
    if(abs(x-this->tabPosX)<=1 && abs(y-this->tabPosY)<=1 && this->moveInBoard(x,y) && (x!=this->tabPosX || y!=this->tabPosY) && this->checkIfMate(x,y))
        return true;
    else
        return false;
}

void Roi::setImage(QString color){
    if(color == "Blanc"){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/roi_blanc.png")); //Image tour blanche
        this->namePiece = '6';
    }else if(color == "Noir"){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/roi_noir.png"));  //Image tour noire
        this->namePiece = 'k';
    }
}

bool Roi::isInDanger(int x, int y){

}

Roi::~Roi(){
    delete this->lbl;
}
