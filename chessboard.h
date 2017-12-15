#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QDialog>
#include <QLabel>
#include <QMouseEvent>
#include <QPoint>

#include <QPushButton>
#include <QPainter>
#include "case.h"
#include "piece.h"
#include "roi.h"
#include "cavalier.h"
#include "reine.h"
#include "fou.h"
#include "tour.h"
#include<string>
#include "constante.h"
#include "player.h"

using namespace std;
namespace Ui {
class ChessBoard;
}

class ChessBoard : public QDialog
{
    Q_OBJECT

public:
    explicit ChessBoard(QWidget *parent = 0);
   //explicit ChessBoard(QWidget *parent = 0, QString file = "initialisation.txt");

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void initGame(string fichier);
    ~ChessBoard();
    void lectureFichier(string Sauvegarde);
    void ecritureFichierSauvegarde();
    void centrerPiece(Piece *piece, QPoint pos);
    void initPlayers();
    Piece * getPieceAt(int x,int y);

private slots:
    void on_boutonSauvegarder_clicked();

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
};

#endif // CHESSBOARD_H
