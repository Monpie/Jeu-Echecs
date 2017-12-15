#include "fou.h"
#include "iostream"
using namespace std;
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
}

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
    this->lbl->move(x*TAILLECASE+25,y*TAILLECASE);
    this->setTabPosX(x);
    this->setTabPosY(y);
}

bool Fou::isValidMove(int x, int y,std::vector<Piece*> pieces){
    cout << "Fou::isValidMove(int x, int y) = "<< x << endl;
    if((abs(x-this->tabPosX)==abs(y-this->tabPosY)) && this->moveInBoard(x,y) && (x!=this->tabPosX || y!=this->tabPosY))
        return true;
    else
        return false;
}

Fou::~Fou(){
    delete this->lbl;
}
