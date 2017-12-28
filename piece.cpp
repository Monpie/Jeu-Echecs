#include "piece.h"
#include "iostream"
#include "player.h"
using namespace std;

//_______________________________PIECE_________________________________

int Piece::getWidth(){
    return this->width;
}

int Piece::getHeigth(){
   return this->height;
}

int Piece::getY(){
    return this->lbl->y();
}

Player * Piece::getOwner(){
    return this->owner;
}

void Piece::setOldX(int x){
    this->oldX =x;
}

void Piece::setOldY(int y){
    this->oldY =y;
}

int Piece::getOldX(){
    return this->oldX;
}

int Piece::getOldY(){
    return this->oldY;
}

int Piece::getTabPosX(){
    return this->tabPosX;
}

int Piece::getTabPosY(){
    return this->tabPosY;
}

void Piece::setTabPosX(int x){
    this->tabPosX = x;
}

void Piece::setTabPosY(int y){
    this->tabPosY = y;
}

void Piece::setX(int x){
    this->x = x;
}

void Piece::setY(int y){
    this->y = y;
}

void Piece::move(int x,int y){
    this->lbl->move(x*TAILLECASE+CENTRER_PIECE,y*TAILLECASE);
}

bool Piece::isValidMove(int x, int y, std::vector<Piece *> pieces){
    return false;
}

void Piece::centrer(int x, int y){
    this->lbl->move(x,y);
}

char Piece::getPieceName(){
    return this->namePiece;
}

bool Piece::moveInBoard(int x, int y){
    if(x<=7 && x>=0 && y<=7 && y>=0)
        return true;
    else
        return false;
}

QString Piece::getColor(){
    return this->color;
}

bool Piece::getIsPion(){
    return this->isPion;
}

Piece::~Piece(){}

Piece * Piece::getPieceAt(std::vector<Piece*> pieces, int x, int y){
    for(unsigned int i=0; i<pieces.size();i++){
        if(pieces[i]->getTabPosX()==x && pieces[i]->getTabPosY()==y){
            return pieces[i];
        }
    }
    return 0;
}

bool Piece::checkIfMate(int x, int y){
    if(this->owner->getPiecesAt(x,y)){
        if(this->owner->getPiecesAt(x,y)->getOwner()!=this->owner){
            return true;
        }else
            return false;
    }else{
        return true;
    }
}

void Piece::setImage(QString color){
    this->color = color;
}

bool Piece::getIsKing(){
    return this->isKing;
}

bool Piece::IsPossibleMove(int x, int y, vector<QPoint> possibleMove){
    for(int i=0;i<possibleMove.size();i++)
    {
        if(QPoint(x,y)==possibleMove[i])
            return true;
    }
    return false;
}
