#ifndef PIECE_H
#define PIECE_H
#include <QLabel>
#include <QMouseEvent>
//#include "roi.h"

class Piece
{
public:
     int getX();
     int getY();
     int getOwner();
     int setX();
     int setY();
     int getWidth();
     int getHeigth();
     //virtual void setImage(QString name);
     void move(int x, int y);
     void isValidMove();
     bool validClick(QMouseEvent *event);
     //void mousePressEvent(QMouseEvent *ev);

protected:
    QLabel* lbl;    //Image de la pièce
    QString name;   //Nom de la pièce
    QString color;  //Couleur de la pièce
    int width;  //Largeur de la pièce
    int height; //Hauteur de la pièce
    int x;  //Position x de la pièce
    int y;  //Position y de la pièce
    int owner;
    bool isClicked = false;
};

#endif // PIECE_H
