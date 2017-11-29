#include "roi.h"
#include <QDebug>
#include "case.h"

Roi::Roi(QWidget *parent, QString color,int my_owner, int width, int height, int x, int y)
{
    this->lbl = new QLabel(parent);
    this->lbl->setPixmap(QPixmap(":/images/Pieces/roi_blanc.png"));
    this->setImage(color);
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
    this->owner = my_owner;
}

void Roi::move(int x,int y){
    if(this->isValidMove())
        this->lbl->move(x,y);
    else
    {
        //this->lbl->move(this->getX()-75,this->getY());
        qDebug("Illegal move");
    }
}

bool Roi::isValidMove(){
    if(this->getX()<=600 && this->getX()>=0 && this->getY() <=600 && this->getY()>=0 && this->getX()<this->getOldX()+75 && this->getY()<this->getOldY()+75 && this->getX()>this->getOldX()-75 && this->getY()>this->getOldY() -75)
    {
        return true;
    }else{
       return false;
    }
}

bool Roi::validClick(QMouseEvent *event){
    if(event->pos().x() <= this->getX()+this->getWidth() && event->pos().y() <= this->getY()+this->getHeigth() && event->pos().x() >= this->getX() && event->pos().y() >= this->getY())
    {
        this->isClicked = true;
        qDebug("OK");

        /*while(this->isClicked){
           // qDebug("while");

            if(event->button() & Qt::LeftButton ){
                qDebug("buttins");
                this->move(event->pos().x(),event->pos().y());
                this->isClicked = false;
            }
        }*/
    }
}

void Roi::setImage(QString color){
    if(color == "Blanc"){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/roi_blanc.png")); //Image tour blanche
    }else if(color == "Noir"){
        this->lbl->setPixmap(QPixmap(":/images/Pieces/roi_noir.png"));  //Image tour noire
    }
}

void Roi::setOldX(int x){
    this->oldX =x;
}

void Roi::setOldY(int y){
    this->oldY =y;
}

int Roi::getOldX(){
    return this->oldX;
}

int Roi::getOldY(){
    return this->oldY;
}

int Roi::getMyOwner(){
    return this->my_owner;
}
