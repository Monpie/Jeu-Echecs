#include "player.h"

Player::Player(int id)
{
    this->id = id;
}


//getteur et setteur
void Player::setAsPlay(bool asPlay)
{
     this->asPlay = asPlay;
}

//getAsPlar
bool Player::getAsPlay()
{
    return this->asPlay;
}

//getID
int Player::getId()
{
    return this->id;
}

//removePiece
void Player::removePiece(Piece piece)
{
    //this->pieces.erase(piece);
}

//addPiece
void Player::addPiece(Piece piece){
    this->pieces.push_back(&piece);
}


