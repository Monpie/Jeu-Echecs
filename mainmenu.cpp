#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "piece.h"
#include <QLabel>

#include <iostream>

#include <ostream>
#include <fstream>
MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    //QLabel* testLbl = new QLabel(this);
    //testLbl->setPixmap(QPixmap("D:/Utilisateur/Documents/Ecole/ENSIBS-2/Semestre 3/C++/Projet/Jeu-Echecs/echiquier.jpg"));
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}


//bouton new game
void MainMenu::on_newGameButton_clicked()
{
    ChessBoard board;
    this->hide();
    board.exec();
}


//bouton chargement
void MainMenu::on_loadGameButton_clicked()
{
    ChessBoard board;
    this->hide();
    board.exec();

}


//bouton quitter
void MainMenu::on_btnQuitter_clicked()
{
    this->close();
}


//Bouton règle
void MainMenu::on_btnRegle_clicked()
{
    this->close();
}
