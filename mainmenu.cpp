#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "piece.h"
#include <QLabel>

#include <iostream>

#include <ostream>
#include <fstream>

//_______________________________MAINMENU_________________________________

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    QSound::play(":/musique/Musique/Game_of_Thrones.wav");
    ui->setupUi(this);
    this->setFixedSize(this->size());   //Empêche le redimensionnement de la fenêtre en fixant la taille actuelle de la fenêtre
}

MainMenu::~MainMenu()
{
    delete ui;
}

//_______________________________METHOD_________________________________

//bouton new game
void MainMenu::on_newGameButton_clicked()
{
    ChessBoard board("initialisation.txt");
    this->hide();
    board.exec();
}

//bouton chargement
void MainMenu::on_loadGameButton_clicked()
{
    ChessBoard board("sauvegarde.txt");
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
    pageRegle page;
    this->close();
    page.exec();
}
