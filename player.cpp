#include "player.h"

//_______________________________PLAYER_________________________________
Player::Player(int id)
{
    this->id = id;
}

//_______________________________METHOD_________________________________

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
void Player::removePiece(Piece  *piece)
{    
    for(std::vector<Piece *>::iterator it = this->pieces.begin() ; it < this->pieces.end(); it++)
        if(piece==*it){
            this->pieces.erase(it);
        }
}


//addPiece
void Player::addPiece(Piece * piece){
    this->pieces.push_back(piece);
}


vector<Piece *> Player::getPieces(){
    return this->pieces;
}

Piece * Player::getPiecesAt(int x, int y){
    for(unsigned int i=0; i<this->pieces.size();i++){
        if(pieces[i]->getTabPosX()==x && pieces[i]->getTabPosY()==y){
            return this->pieces[i];
        }
    }
}
