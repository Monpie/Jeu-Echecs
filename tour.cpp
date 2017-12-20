#include "tour.h"
#include "iostream"
using namespace std;
Tour::Tour(QWidget *parent, QString color, Player * owner,  int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->setImage(color);
    this->width = width;
    this->height = height;
    this->color = color;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = owner;
    this->isTour = true;
}

void Tour::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/tour_blanc.png")); //Image tour blanche
        this->namePiece = '3';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/tour_noir.png"));  //Image tour noire
        this->namePiece = 't';
    }
}

bool Tour::isValidMove(int x, int y,std::vector<Piece*> pieces){

    /* for(Piece * piece : pieces){
        if(piece->getTabPosX()==this->tabPosX+1)
        {
            this->verticalBlocked = true;
            cout <<" Mouvement vertical bloqué" << endl;
        }

        if(piece->getTabPosY()==this->tabPosY+1){
            this->horizontalBlocked = true;
            cout <<" Mouvement horizontal bloqué" << endl;
        }
    }*/
    //this->updateAllPossibleMove(pieces);

    if(((x!=this->tabPosX && y==this->tabPosY) || (x==this->tabPosX && y != this->tabPosY)) && this->moveInBoard(x,y) && this->checkIfMate(x,y) && this->IsPossibleMove(x,y,this->allPossibleMove) )
        return true;
    else
        return false;
}

void Tour::move(int x, int y){
    this->lbl->move(x*TAILLECASE+25,y*TAILLECASE);
    this->setTabPosX(x);
    this->setTabPosY(y);
}


Tour::~Tour(){
    delete this->lbl;
}

/*void Tour::updateAllPossibleMove(vector<Piece *> pieces){
    Piece * verticalPiece;
    Piece * horizotalPiece;
    for(Piece * piece : pieces){
            if(piece->getTabPosX()==this->tabPosX+1)
            {
                this->verticalBlocked = true;
                verticalPiece = piece;
                cout <<" Mouvement vertical bloqué" << endl;
            }

            if(piece->getTabPosY()==this->tabPosY+1){
                this->horizontalBlocked = true;
                horizotalPiece = piece;
                cout <<" Mouvement horizontal bloqué" << endl;
            }
    }



    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(this->isValidMove(i,j,pieces)){
                this->allPossibleMove.push_back(QPoint(i,j));
            }
        }
    }
}*/

void Tour::updateAllPossibleMove(std::vector<Piece *> pieces){
    int i=this->tabPosX-1,j=this->tabPosX+1;
    bool alreadyHasEnemy = false;
    cout << "methode updatePossibleMove" << endl;
    while(i>=0){
        //if(getPieceAt(pieces,i,this->tabPosY))
        if(!this->checkIfMate(i,this->tabPosY) || alreadyHasEnemy)
        {
            cout << !this->checkIfMate(i,this->tabPosY) << endl;
            cout << "break true gauche" << endl;
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
            cout << "break true droite" << endl;
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
            cout << "break true bas" << endl;
            cout << !this->checkIfMate(i,this->tabPosY) << endl;
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

    /* for(int i=0;i<this->allPossibleMove.size();i++){
        cout << " i = " << i << " , x = " << this->allPossibleMove[i].x() << " , y = " << this->allPossibleMove[i].y() << endl;
    }*/

    /*int i=1,j=1;

    while(!this->checkIfMate(abs(this->tabPosX-i),this->tabPosY) && this->isValidMove(i,this->tabPosY,pieces)){
        if(this->getPieceAt(pieces,i,this->tabPosY) && this->getPieceAt(pieces,i,this->tabPosY)!=this){
            cout << "break appelé " << i << endl;
            break;
        }else{
            cout << "move enregistré : " << abs(this->tabPosX-i) << " , j = " << this->tabPosY << endl;
            this->allPossibleMove.push_back(QPoint(abs(this->tabPosX-i),this->tabPosY));
        }
        i++;
    }
cout << "second while" << endl;
    while(!this->checkIfMate(this->tabPosX,abs(this->tabPosX-j)) && this->moveInBoard(this->tabPosX,j)){
        cout << "j = " << j << endl;
        if(this->getPieceAt(pieces,this->tabPosX,j) && this->getPieceAt(pieces,this->tabPosX,j)!=this){
            cout << "break appelé " << i << endl;
            break;
        }else{
            cout << "move enregistré : " << this->tabPosX << " , j = " << abs(this->tabPosX-j) << endl;
            this->allPossibleMove.push_back(QPoint(this->tabPosX,abs(this->tabPosX-j)));
        }
        j++;
    }*/
}

bool Tour::IsPossibleMove(int x, int y, vector<QPoint> possibleMove){
    for(int i=0;i<possibleMove.size();i++)
    {
        if(QPoint(x,y)==possibleMove[i])
            return true;
    }
    return false;
}
