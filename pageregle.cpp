#include "pageregle.h"
#include "ui_pageregle.h"

pageRegle::pageRegle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pageRegle)
{
    ui->setupUi(this);
}

pageRegle::~pageRegle()
{
    delete ui;
}

//bouton quitter
void pageRegle::on_pushButton_clicked()
{
    MainMenu menu;
    menu.exec();
    this->close();
}

//bouton suivant
void pageRegle::on_pushButton_2_clicked()
{
    ui->label->setPixmap(QPixmap(":/images/game//game/regle2.PNG"));

}

//bouton précédent
void pageRegle::on_pushButton_3_clicked()
{
    ui->label->setPixmap(QPixmap(":/images/game//game/regle1.PNG"));
}
