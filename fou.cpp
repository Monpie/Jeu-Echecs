#include "fou.h"
#include "iostream"
using namespace std;

//_______________________________FOU_________________________________

Fou::Fou(QWidget *parent, QString color, Player * owner,  int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->setImage(color);
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = owner;
    this->lbl->setVisible(true);
}

//_______________________________METHOD_________________________________

void Fou::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/fou_blanc.png")); //Image tour blanche
        this->namePiece = '4';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/fou_noir.png"));  //Image tour noire
        this->namePiece = 'f';
    }
}

void Fou::move(int x, int y){
    this->lbl->move(x*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),y*TAILLECASE+CHESSBOARD_POS.y());
    this->setTabPosX(x);
    this->setTabPosY(y);
}



bool Fou::isValidMove(int x, int y,std::vector<Piece*> pieces){
    this->updateAllPossibleMove(pieces);
    if((abs(x-this->tabPosX)==abs(y-this->tabPosY)) && this->moveInBoard(x,y)  && this->checkIfMate(x,y) && (x!=this->tabPosX || y!=this->tabPosY) && this->IsPossibleMove(x,y,this->allPossibleMove))
        return true;
    else
        return false;
}

Fou::~Fou(){
    delete this->lbl;
}

void Fou::updateAllPossibleMove(std::vector<Piece*> pieces){
    int i=this->tabPosX-1,j=this->tabPosY-1;
    bool alreadyHasEnemy = false;

    while(this->moveInBoard(i,j)){
        if(!this->checkIfMate(i,j) || alreadyHasEnemy)
        {
            break;
        }else{
            if(this->getPieceAt(pieces,i,j) && this->getPieceAt(pieces,i,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,j));
        }
        i--;
        j--;
    }

    i=this->tabPosX-1,j=this->tabPosY+1;
    alreadyHasEnemy = false;
    while(this->moveInBoard(i,j)){
        if(!this->checkIfMate(i,j) || alreadyHasEnemy)
        {
            break;
        }else{
            if(this->getPieceAt(pieces,i,j) && this->getPieceAt(pieces,i,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,j));
        }
        i--;
        j++;
    }

    i=this->tabPosX+1,j=this->tabPosY-1;
    alreadyHasEnemy = false;
    while(this->moveInBoard(i,j)){
        if(!this->checkIfMate(i,j) || alreadyHasEnemy)
        {
            break;
        }else{
            if(this->getPieceAt(pieces,i,j) && this->getPieceAt(pieces,i,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,j));
        }
        i++;
        j--;
    }

    i=this->tabPosX+1,j=this->tabPosY+1;
    alreadyHasEnemy = false;
    while(this->moveInBoard(i,j)){
        if(!this->checkIfMate(i,j) || alreadyHasEnemy)
        {
            break;
        }else{
            if(this->getPieceAt(pieces,i,j) && this->getPieceAt(pieces,i,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,j));
        }
        i++;
        j++;
    }
}

/*bool Fou::IsPossibleMove(int x, int y, vector<QPoint> possibleMove){
    for(int i=0;i<possibleMove.size();i++)
    {
        if(QPoint(x,y)==possibleMove[i])
            return true;
    }
    return false;
}*/
