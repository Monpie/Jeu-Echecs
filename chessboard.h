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
using namespace std;
#include <mainmenu.h>


namespace Ui {
class ChessBoard;
}

class ChessBoard : public QDialog
{
    Q_OBJECT

public:
    explicit ChessBoard(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void initGame(string fichier);
    ~ChessBoard();
    void modifierCase(char valeur, int ligne, int colonne);
    void lectureFichier(string Sauvegarde);
    void ecritureFichierSauvegarde();
    void centrerPiece(Piece *piece, QPoint pos);

private slots:
    void on_boutonSauvegarder_clicked();



    void on_pushButton_clicked();

private:
    Ui::ChessBoard *ui;

    vector<Piece*> pieces;
    const int taille = 95;
    bool isClicked = false;
    Piece *selectedPiece;
    int currentPlayer = 0;
    char chessBoard[8][8]; //Tableau de char
    Case *caseBoard[8][8]; // Tableau de Case
};

#endif // CHESSBOARD_H
