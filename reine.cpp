#include "reine.h"
#include "iostream"
using namespace std;

Reine::Reine(QWidget *parent, QString color,Player * owner, int width, int height, int x,int y)
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

void Reine::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/reine_blanc.png")); //Image tour blanche
        this->namePiece = '5';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/reine_noir.png"));  //Image tour noire
        this->namePiece = 'q';
    }
}



void Reine::move(int x, int y){
    this->lbl->move(x*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),y*TAILLECASE+CHESSBOARD_POS.y());
    this->setTabPosX(x);
    this->setTabPosY(y);
}

bool Reine::isValidMove(int x, int y,std::vector<Piece*> pieces){
    this->updateAllPossibleMove(pieces);

    if(( this->checkIfMate(x,y) && ((x!=this->tabPosX*TAILLECASE && y==this->tabPosY) && this->moveInBoard(x,y) || (abs(x-this->tabPosX)==abs(y-this->tabPosY)) || (x==this->tabPosX && y != this->tabPosY)&& this->moveInBoard(x,y) ) && (x!=this->tabPosX || y!=this->tabPosY) ) && this->IsPossibleMove(x,y,this->allPossibleMove))
        return true;
    else
        return false;
}

Reine::~Reine(){
    delete this->lbl;
}

void Reine::updateAllPossibleMove(std::vector<Piece*> pieces){
    int i=this->tabPosX-1,j=this->tabPosY-1;
    bool alreadyHasEnemy = false;

    while(this->moveInBoard(i,j)){
        if(!this->checkIfMate(i,j) || alreadyHasEnemy)
        {
            //cout << "break true gauche" << endl;
            break;
        }else{
            if(this->getPieceAt(pieces,i,j) && this->getPieceAt(pieces,i,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,j));
            //cout << "move ajouté : i = " << i << " , j " << j << endl;
        }
        i--;
        j--;
    }

    i=this->tabPosX-1,j=this->tabPosY+1;
    alreadyHasEnemy = false;
    while(this->moveInBoard(i,j)){
        if(!this->checkIfMate(i,j) || alreadyHasEnemy)
        {
            //cout << "break true gauche" << endl;
            break;
        }else{
            if(this->getPieceAt(pieces,i,j) && this->getPieceAt(pieces,i,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,j));
            //cout << "move ajouté : i = " << i << " , j " << j << endl;
        }
        i--;
        j++;
    }

    i=this->tabPosX+1,j=this->tabPosY-1;
    alreadyHasEnemy = false;
    while(this->moveInBoard(i,j)){
        if(!this->checkIfMate(i,j) || alreadyHasEnemy)
        {
            //cout << "break true gauche" << endl;
            break;
        }else{
            if(this->getPieceAt(pieces,i,j) && this->getPieceAt(pieces,i,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,j));
            //cout << "move ajouté : i = " << i << " , j " << j << endl;
        }
        i++;
        j--;
    }

    i=this->tabPosX+1,j=this->tabPosY+1;
    alreadyHasEnemy = false;
    while(this->moveInBoard(i,j)){
        if(!this->checkIfMate(i,j) || alreadyHasEnemy)
        {
           // cout << "break true gauche" << endl;
            break;
        }else{
            if(this->getPieceAt(pieces,i,j) && this->getPieceAt(pieces,i,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,j));
           // cout << "move ajouté : i = " << i << " , j " << j << endl;
        }
        i++;
        j++;
    }

     i=this->tabPosX-1,j=this->tabPosX+1;
     alreadyHasEnemy = false;
   // cout << "methode updatePossibleMove" << endl;
    while(i>=0){
        //if(getPieceAt(pieces,i,this->tabPosY))
        if(!this->checkIfMate(i,this->tabPosY) || alreadyHasEnemy)
        {
           // cout << "break true gauche" << endl;
            break;
        }else{
            if(this->getPieceAt(pieces,i,this->tabPosY) && this->getPieceAt(pieces,i,this->tabPosY)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(i,this->tabPosY));
        }
        i--;
    }

    alreadyHasEnemy = false;
    while(j<8){
        //if(this->getPieceAt(pieces,j,this->tabPosY))
        if(!this->checkIfMate(j,this->tabPosY) || alreadyHasEnemy)
        {
           // cout << "break true droite" << endl;
            break;
        }
        else{
            if(this->getPieceAt(pieces,j,this->tabPosY) && this->getPieceAt(pieces,j,this->tabPosY)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(j,this->tabPosY));
        }
        j++;
    }

    alreadyHasEnemy = false;
    i=this->tabPosY+1,j=this->tabPosY-1;
    while(i<8){
        //if(this->getPieceAt(pieces,this->tabPosX,i))
        if(!this->checkIfMate(this->tabPosX,i) || alreadyHasEnemy)
        {
           // cout << "break true bas" << endl;
            break;
        }
        else{
            if(this->getPieceAt(pieces,this->tabPosX,i) && this->getPieceAt(pieces,this->tabPosX,i)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(this->tabPosX,i));
        }
        i++;
    }

    alreadyHasEnemy = false;
    while(j>=0){
        //if(this->getPieceAt(pieces,this->tabPosX,j))
        if(!this->checkIfMate(this->tabPosX,j) || alreadyHasEnemy)
        {
            cout << "break true" << endl;
            break;
        }else{
            if(this->getPieceAt(pieces,this->tabPosX,j) && this->getPieceAt(pieces,this->tabPosX,j)->getOwner()!=this->owner)
                alreadyHasEnemy = true;
            this->allPossibleMove.push_back(QPoint(this->tabPosX,j));
        }
        j--;
    }
}

bool Reine::IsPossibleMove(int x, int y, vector<QPoint> possibleMove){
   cout << "ispossibleMove" ;
    for(int i=0;i<possibleMove.size();i++)
    {
        if(QPoint(x,y)==possibleMove[i])
            return true;
    }
    return false;
}
