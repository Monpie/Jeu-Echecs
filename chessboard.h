#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QDialog>
#include <QLabel>
#include <QMouseEvent>

#include <QPushButton>
#include <QPainter>
#include "case.h"
#include "piece.h"
#include "roi.h"
#include "reine.h"
#include<string>
using namespace std;
namespace Ui {
class ChessBoard;
}

class ChessBoard : public QDialog
{
    Q_OBJECT

public:
    explicit ChessBoard(QWidget *parent = 0);
    explicit ChessBoard(QWidget *parent, string fichier);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void initGame();
    ~ChessBoard();

    void modifierCase(char valeur, int ligne, int colonne);
    void lectureFichier(string Sauvegarde);
    void ecritureFichierSauvegarde();

private slots:
    void on_boutonSauvegarder_clicked();



private:
    Ui::ChessBoard *ui;
    Roi *piece;
    Roi *secondRoi;
    Piece *tab[8][8] ;
    vector<Piece*> pieces;
    const int taille = 75;
    bool isClicked = false;
    int currentPlayer = 0;
};

#endif // CHESSBOARD_H
