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
    QSound::play(":/musique/Musique/Game_of_Thrones.wav");
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}


//bouton new game
void MainMenu::on_newGameButton_clicked()
{
    ChessBoard board("initialisation.txt");
    this->hide();

   // board.initGame("initialisation.txt");

    board.exec();
}


//bouton chargement
void MainMenu::on_loadGameButton_clicked()
{
    ChessBoard board("sauvegarde.txt");
    this->hide();

    //board.initGame("sauvegarde.txt");
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
    pageRegle page;
    this->close();
    page.exec();
}
