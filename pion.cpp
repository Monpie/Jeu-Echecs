#include "pion.h"
#include "math.h"
#include "iostream"
using namespace std;

//_______________________________PION_________________________________

Pion::Pion(QWidget *parent, QString color, Player * owner,  int width, int height, int x,int y)
{
    this->lbl = new QLabel(parent);
    this->setImage(color);
    this->color = color;
   /* this->width = width;
    this->height = height;*/
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = owner;
    this->isPion=true;
    this->lbl->setVisible(true);
}

//_______________________________METHOD_________________________________

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
    this->lbl->move(x*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),y*TAILLECASE+CHESSBOARD_POS.y());
    this->setTabPosX(x);
    this->setTabPosY(y);
    this->firstMovePlayed();
    this->allPossibleMove.clear();
}


bool Pion::isValidMove(int x,int y,std::vector<Piece*> pieces){

    if(this->getColor()=="Blanc" && this->tabPosY!=1)
        this->firstMove=false;
    else if(this->getColor()=="Noir" && this->tabPosY!=6)
        this->firstMove=false;
    if(this->IsPossibleMove(x,y,this->allPossibleMove))
        return true;

    if(this->firstMove){
        this->test(pieces);
        if(y<=this->tabPosY+2 && x==this->tabPosX && y>tabPosY && this->color=="Blanc" && this->IsPossibleMove(x,y,this->allPossibleMove)){
            return true;
        }else if(this->color=="Noir" && (y>=this->tabPosY-2 && x==this->tabPosX && y<this->tabPosY) && this->IsPossibleMove(x,y,this->allPossibleMove))
            return true;
        else
            return false;
    }else{
        if(y<=this->tabPosY+1 && x==this->tabPosX && y>tabPosY && this->color=="Blanc" && !this->getPieceAt(pieces,this->tabPosX,this->tabPosY+1) && this->moveInBoard(x,y) )
            return true;
        else if(this->color=="Noir" && (y>=this->tabPosY-1 && x==this->tabPosX && y<this->tabPosY)&& !this->getPieceAt(pieces,this->tabPosX,this->tabPosY-1) && this->moveInBoard(x,y))
            return true;
        else
            return false;
    }

    // this->updateAllPossibleMove(pieces);
    //Bug mouvement pion
    //Si une piece est sur une case à 2 de distance du pion et que le pion a encore son first move, il ne peut plus bouger
    //Ou alors la piece peut sauter par dessus l'autre
    /*if(this->firstMove){
        if(y<=this->tabPosY+2 && x==this->tabPosX && y>tabPosY && this->color=="Blanc" && this->test(pieces,x,y)){
            return true;
        }else if(this->color=="Noir" && (y>=this->tabPosY-2 && x==this->tabPosX && y<this->tabPosY)  )//&& !this->getPieceAt(pieces,this->tabPosX,this->tabPosY-2))
            return true;
        else
            return false;
    }else{
        if(y<=this->tabPosY+1 && x==this->tabPosX && y>tabPosY && this->color=="Blanc" && !this->getPieceAt(pieces,this->tabPosX,this->tabPosY+1) )
            return true;
        else if(this->color=="Noir" && (y>=this->tabPosY-1 && x==this->tabPosX && y<this->tabPosY)&& !this->getPieceAt(pieces,this->tabPosX,this->tabPosY-1))
            return true;
        else
            return false;
    }*/

}

void Pion::firstMovePlayed(){
    this->firstMove = false;
}

bool Pion::canAttack(char chessboard[8][8] ){
    bool flag = false;

    if(this->color=="Blanc")
    {
        if(chessboard[this->tabPosY+1][this->tabPosX+1] != '0' && this->moveInBoard(this->tabPosX+1,this->tabPosY+1) && this->checkIfMate(this->tabPosX+1,this->tabPosY+1))
        {
            this->allPossibleMove.push_back(QPoint(this->tabPosX+1,this->tabPosY+1));
            flag = true;
        }

        if(chessboard[this->tabPosY+1][this->tabPosX-1] != '0' && this->moveInBoard(this->tabPosX-1,this->tabPosY+1) && this->checkIfMate(this->tabPosX-1,this->tabPosY+1))
        {
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

Pion::~Pion(){
    delete this->lbl;
}

/*bool Pion::IsPossibleMove(int x, int y, vector<QPoint> possibleMove){
    for(unsigned int i=0;i<possibleMove.size();i++)
    {
        if(QPoint(x,y)==possibleMove[i])
            return true;
    }
    return false;
}*/

void Pion::test(std::vector<Piece *> pieces){
    int i = tabPosY+1;

    while(i<=this->tabPosY+2 && this->color=="Blanc"){
        if(this->getPieceAt(pieces,this->tabPosX,i))
            break;
        else
            this->allPossibleMove.push_back(QPoint(this->tabPosX,i));
        i++;
    }

    i= tabPosY-1;
    while(i>=this->tabPosY-2 && this->color=="Noir"){
        if(this->getPieceAt(pieces,this->tabPosX,i))
            break;
        else
            this->allPossibleMove.push_back(QPoint(this->tabPosX,i));
        i--;
    }
}

void Pion::updateAllPossibleMove(std::vector<Piece *> pieces){
    for(int i=0;i<pieces.size();i++){

    }
}
