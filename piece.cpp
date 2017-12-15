#include "piece.h"
#include "iostream"
#include "player.h"
using namespace std;

int Piece::getWidth(){
    return this->width;
}

int Piece::getHeigth(){
   return this->height;
}

/*int Piece::getX(){
    return this->lbl->x();
}*/

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
    this->lbl->move(x*TAILLECASE+25,y*TAILLECASE);
}

bool Piece::isValidMove(int x, int y){
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

bool Piece::allyPiece(int x, int y, char chessboard[8][8]){
    if(chessboard[x][y]!=0)
        return false;
    else
        return true;
}

Piece::~Piece(){}
