#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QDialog>
#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include <QPushButton>
#include <QPainter>
#include <QException>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "case.h"
#include "piece.h"
#include "roi.h"
#include "cavalier.h"
#include "reine.h"
#include "fou.h"
#include "tour.h"
#include "mainmenu.h"
#include "constante.h"
#include "player.h"

#include "pion.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include "choixupgrade.h"


using namespace std;


namespace Ui {
class ChessBoard;
}

class ChessBoard : public QDialog
{
    Q_OBJECT

public:
   // explicit ChessBoard(QWidget *parent = 0);
    explicit ChessBoard(QString file,QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void initGame(QString fichier);
    ~ChessBoard();
    void lectureFichier(string Sauvegarde);
    void ecritureFichierSauvegarde(QString fileName);
    void centrerPiece(Piece *piece, QPoint pos);
    void initPlayers();
    Piece * getPieceAt(int x,int y);
    int operator +(int a);
    void removePiece(Piece *piece);
    //void resizeEvent(QResizeEvent *e);

private slots:
    void on_boutonSauvegarder_clicked();
    void upgradePion();
    void on_pushButton_clicked();
    void transformToReine();
    void transformToTour();
    void transformToCavalier();
    void transformToFou();

private:
    Ui::ChessBoard *ui;
    vector<Piece*> pieces;
    Piece *selectedPiece = 0;
    char chessBoard[8][8]; //Tableau de char
    Case *caseBoard[8][8]; // Tableau de Case
    vector<Case *> possibleMove;
    Player *player1;
    Player *player2;
    Player *currentPlayer;
    QPoint posDeadPiece;
    int a=5;

signals:
    void maxAtteint();
};

#endif // CHESSBOARD_H
