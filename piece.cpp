#include "piece.h"

int Piece::getWidth(){
    return this->width;
}

int Piece::getHeigth(){
   return this->height;
}

int Piece::getX(){
    return this->lbl->x();
}

int Piece::getY(){
    return this->lbl->y();
}

int Piece::getOwner(){
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

bool Piece::validClick(QMouseEvent *event){
    if(event->pos().x() <= this->getX()+this->getWidth() && event->pos().y() <= this->getY()+this->getHeigth() && event->pos().x() >= this->getX() && event->pos().y() >= this->getY())
    {
        this->isClicked = true;
        qDebug("OK");
        /*while(this->isClicked){
           // qDebug("while");

            if(event->button() & Qt::LeftButton ){
                qDebug("buttins");
                this->move(event->pos().x(),event->pos().y());
                this->isClicked = false;
            }
        }*/
    }
}

void Piece::move(int x,int y){
        this->lbl->move(x,y);
}

