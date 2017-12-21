#include "choixupgrade.h"
#include "ui_choixupgrade.h"
#include "iostream"
using namespace std;
ChoixUpgrade::ChoixUpgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoixUpgrade)
{
    ui->setupUi(this);
}

ChoixUpgrade::~ChoixUpgrade()
{
    delete ui;
}

void ChoixUpgrade::on_btn_reine_clicked()
{
    emit btn_reine_clicked();
    this->close();
}

void ChoixUpgrade::on_btn_tour_clicked()
{
    emit btn_tour_clicked();
    this->close();
}

void ChoixUpgrade::on_btn_fou_clicked()
{
    emit btn_fou_clicked();
    this->close();
}

void ChoixUpgrade::on_btn_cavalier_clicked()
{
    emit btn_cavalier_clicked();
    this->close();
}
