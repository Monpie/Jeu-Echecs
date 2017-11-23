#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QDialog>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include "case.h"
#include "piece.h"
#include "roi.h"

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
    void initGame();
    ~ChessBoard();

private:
    Ui::ChessBoard *ui;
    Roi *piece;
    Piece *tab[8][8] ;
    QPushButton *test;
};

#endif // CHESSBOARD_H
