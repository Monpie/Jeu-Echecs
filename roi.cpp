#include "roi.h"
#include <QDebug>

Roi::Roi(QWidget *parent, QString name, int width, int height, int x, int y)
{
    this->lbl = new QLabel(parent);
    this->lbl->setPixmap(QPixmap(":/images/piece.jpg"));
    this->name = name;
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->lbl->move(x,y);
}

void Roi::move(int x,int y){
    this->lbl->move(x,y);
}

void Roi::isValidMove(){

}

void Roi::validClick(QMouseEvent *event){
    if(event->pos().x() <= this->getX()+this->getWidth() && event->pos().y() <= this->getY()+this->getHeigth() && event->pos().x() >= this->getX() && event->pos().y() >= this->getY())
    {
        this->isClicked = true;
        qDebug("OK");

        while(this->isClicked){
           // qDebug("while");

            if(event->button() & Qt::LeftButton ){
                qDebug("buttins");
                this->move(event->pos().x(),event->pos().y());
                this->isClicked = false;
            }
        }
    }
}
