#ifndef PLAYER_H
#define PLAYER_H
#include "piece.h"
using namespace std;

class Player
{
public:
    Player(int id);

protected:
    vector<Piece*> pieces ; //collection de piece
    int id; //identifiant joueur
    bool asPlay;

    void removePiece(Piece piece);
    void addPiece(Piece piece);
    void playPiece();

    //getteur setteur asplay
    bool getAsPlay();
    void setAsPlay(bool asPlay);
    int getId();
};

#endif // PLAYER_H
