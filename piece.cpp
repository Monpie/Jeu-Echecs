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



