#include "player.h"

Player::Player(int id)
{
    this->id = id;
}


//getteur et setteur
void Player::setHasPlayed(bool hasPlayed)
{
     this->hasPlayed = hasPlayed;
}

//getAsPlar
bool Player::getHasPlayed()
{
    return this->hasPlayed;
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


