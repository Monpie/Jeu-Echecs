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

    if(((x!=this->tabPosX && y==this->tabPosY) || (x==this->tabPosX && y != this->tabPosY)) && this->moveInBoard(x,y) && this->checkIfMate(x,y))
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

void Tour::updateAllPossibleMove(vector<Piece *> pieces){
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
}
