#include "pion.h"
#include "math.h"
#include "iostream"
using namespace std;

Pion::Pion(QWidget *parent, QString color, Player * owner,  int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->setImage(color);
    this->color = color;
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = owner;
    this->isPion=true;
}

void Pion::setImage(QString color){
    if(color==("Blanc")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/pion_blanc.png")); //Image tour blanche
        this->namePiece = '1';
    }else if(color==("Noir")){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/pion_noir.png"));  //Image tour noire
        this->namePiece = 'p';
    }
}

void Pion::move(int x,int y){
    this->lbl->move(x*TAILLECASE+25,y*TAILLECASE);
   // cout << "x = " << x << ", y = " << y << endl;
    this->setTabPosX(x);
    this->setTabPosY(y);
    //cout << "new pos X = " << this->tabPosX << ", new pos y = " << this->tabPosY << endl;
    this->firstMovePlayed();
    this->allPossibleMove.clear();
}


bool Pion::isValidMove(int x,int y){
    for(int i = 0; i<this->allPossibleMove.size();i++){
        if(this->allPossibleMove[i].x() == x && this->allPossibleMove[i].y() == y){
            cout << "if isValidMove ok" << endl;
            return true;
        }
    }

    if(this->firstMove){
        if(y<this->tabPosY+3 && x==this->tabPosX && y>tabPosY && this->color=="Blanc") {
            return true;
        }else if(this->color=="Noir" && (y>this->tabPosY-3 && x==this->tabPosX && y<this->tabPosY))
            return true;
        else
            return false;
    }else{
        if(y<this->tabPosY+2 && x==this->tabPosX && y>tabPosY && this->color=="Blanc")
            return true;
        else if(this->color=="Noir" && (y>this->tabPosY-2 && x==this->tabPosX && y<this->tabPosY))
            return true;
        else
            return false;
    }
}

void Pion::firstMovePlayed(){
    this->firstMove = false;
}

bool Pion::canAttack(char chessboard[8][8] ){
    bool flag = false;

    if(this->color=="Blanc")
    {   cout << "piece " <<endl;// this->owner->getPiecesAt(this->tabPosY+1,this->tabPosX+1)->getColor().toStdString() << endl;
        //this->owner->getPiecesAt(this->tabPosY+1,this->tabPosX+1)->getColor()!=this->color
        if(chessboard[this->tabPosY+1][this->tabPosX+1] != '0' && this->moveInBoard(this->tabPosX+1,this->tabPosY+1) && this->checkIfMate(this->tabPosX+1,this->tabPosY+1))
        {
            cout << "can attack" << endl;
            this->allPossibleMove.push_back(QPoint(this->tabPosX+1,this->tabPosY+1));
            flag = true;
        }

        if(chessboard[this->tabPosY+1][this->tabPosX-1] != '0' && this->moveInBoard(this->tabPosX-1,this->tabPosY+1) && this->checkIfMate(this->tabPosX-1,this->tabPosY+1))
        {
            cout << "can attack" << endl;
            this->allPossibleMove.push_back(QPoint(this->tabPosX-1,this->tabPosY+1));
            flag = true;
        }
    }else{
        if(chessboard[this->tabPosY-1][this->tabPosX-1] != '0' && this->moveInBoard(this->tabPosX-1,this->tabPosY-1) && this->checkIfMate(this->tabPosX-1,this->tabPosY-1))
        {
            this->allPossibleMove.push_back(QPoint(this->tabPosX-1,this->tabPosY-1));
            flag = true;
        }

        if(chessboard[this->tabPosY-1][this->tabPosX+1] != '0' && this->moveInBoard(this->tabPosX+1,this->tabPosY-1) && this->checkIfMate(this->tabPosX+1,this->tabPosY-1))
        {
            this->allPossibleMove.push_back(QPoint(this->tabPosX+1,this->tabPosY-1));
            flag = true;
        }
    }

    return flag;
}

bool Pion::checkIfMate(int x, int y){
    if(this->owner->getPiecesAt(x,y)){
        if(this->owner->getPiecesAt(x,y)->getOwner()!=this->owner){
            return true;
        }else
            return false;
    }else{
        return true;
    }
}

Pion::~Pion(){
    delete this->lbl;
}
