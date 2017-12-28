#include "player.h"

//_______________________________PLAYER_________________________________

/**
 * @brief Player::Player, constructor of a player
 * @param id
 */
Player::Player(int id)
{
    this->id = id;
}

//_______________________________METHOD_________________________________

/**
 * @brief Player::setHasPlayed, check if the player has played
 * @param hasPlayed
 */
void Player::setHasPlayed(bool hasPlayed)
{
    this->hasPlayed = hasPlayed;
}

/**
 * @brief Player::getHasPlayed
 * @return bool
 */
bool Player::getHasPlayed()
{
    return this->hasPlayed;
}

/**
 * @brief Player::getId
 * @return int
 */
int Player::getId()
{
    return this->id;
}

/**
 * @brief Player::removePiece
 * @param piece
 */
void Player::removePiece(Piece  *piece)
{    
    for(std::vector<Piece *>::iterator it = this->pieces.begin() ; it < this->pieces.end(); it++)
        if(piece==*it){
            this->pieces.erase(it);
        }
}


/**
 * @brief Player::addPiece
 * @param piece
 */
void Player::addPiece(Piece * piece){
    this->pieces.push_back(piece);
}


/**
 * @brief Player::getPieces
 * @return vector<Pieces>
 */
vector<Piece *> Player::getPieces(){
    return this->pieces;
}

/**
 * @brief Player::getPiecesAt a position
 * @param x
 * @param y
 * @return Piece
 */
Piece * Player::getPiecesAt(int x, int y){
    for(unsigned int i=0; i<this->pieces.size();i++){
        if(pieces[i]->getTabPosX()==x && pieces[i]->getTabPosY()==y){
            return this->pieces[i];
        }
    }
}
