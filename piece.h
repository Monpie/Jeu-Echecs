#ifndef PIECE_H
#define PIECE_H
#include <QLabel>
#include <QMouseEvent>

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
     int getOldX();
     int getOldY();
     void setOldX(int x);
     void setOldY(int y);
     int getTabPosX();
     int getTabPosY();
     void setTabPosX(int x);
     void setTabPosY(int y);
     void move(int x, int y);
     bool isValidMove();
     bool validClick(QMouseEvent *event);
     void setImage(QString color);

protected:
    QLabel  *lbl;    //Image de la pièce
    QString color;  //Couleur de la pièce
    int width;  //Largeur de la pièce
    int height; //Hauteur de la pièce
    int x;  //Position x de la pièce
    int y;  //Position y de la pièce
    int oldX;
    int oldY;
    int tabPosX;    //position ligne de la pièce dans le tableau
    int tabPosY;    //position colonne de la pièce dans le tableau
    int owner;
    bool isClicked = false;
};

#endif // PIECE_H
