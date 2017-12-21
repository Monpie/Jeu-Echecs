#ifndef PLAYER_H
#define PLAYER_H
#include "piece.h"

using namespace std;
class Player
{
public:
    Player(int id);
    void removePiece(Piece *piece);
    void addPiece(Piece * piece);
    void playPiece();
    vector<Piece *> getPieces();
    Piece * getPiecesAt(int x, int y);

    //getteur setteur asplay
    bool getHasPlayed();
    void setHasPlayed(bool hasPlayed);
    int getId();

private:
    vector<Piece *>  pieces ; //collection de piece
    int id; //identifiant joueur
    bool hasPlayed;
};

#endif // PLAYER_H
