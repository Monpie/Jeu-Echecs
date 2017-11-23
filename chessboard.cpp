#include "chessboard.h"
#include "ui_chessboard.h"
#include <QPainter>
#include "pion.h"

#include "iostream"
using namespace std;
ChessBoard::ChessBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChessBoard)
{
    //this->test = new Roi(this,"RB",0,50);
   this->piece = new Roi(this,"Roi blanc",50,50,0,0);
    this->test = new QPushButton(this);
    this->test->setText("OK");
    //this->initGame();
    ui->setupUi(this);
}

ChessBoard::~ChessBoard()
{
    delete ui;
}

void ChessBoard::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

        for(int i=0; i<8 ; i++){
            for(int j=0; j<8; j++){
                if(i%2==0){
                    if(j%2==0){
                        Case c(50,i*50,j*50);
                        c.draw(&painter, Qt::white);
                    }else{
                        Case c(50,i*50,j*50);
                        c.draw(&painter, Qt::red);
                    }
                }else{
                    if(j%2==0){
                        Case c(50,i*50,j*50);
                        c.draw(&painter, Qt::red);
                    }else{
                        Case c(50,i*50,j*50);
                        c.draw(&painter, Qt::white);
                    }
                }
            }
        }
}

void ChessBoard::mousePressEvent(QMouseEvent *event){

   // cout << event->pos().x() << "pos pion : " << this->piece->getX()<< endl;
    if(event->buttons() & Qt::LeftButton ){
        qDebug("OK");
        this->test->move(event->x(),event->y());
        this->piece->validClick(event);
        //this->piece->move(200,200);
    }
}



void ChessBoard::initGame(){
    //this->tab[0][0] = new Tour(this,"Tour1","B",50,50,0,0);
    //this->tab[0][1] = new Cavalier(this,"Cavalier1","B",50,50,50,0);
    //this->tab[0][2] = new Fou(this,"Fou1","B",50,50,100,0);

    for(int i=0; i<8; i++){
        /*this->tab[1][i] = new Pion(this,"Pion","B",50,50,i*50,50);
        this->tab[6][i] = new Pion(this,"Pion","N",50,50,i*50,300);*/
        this->tab[1][i] = new Roi(this,"RB",50,50,i*50,50);
        this->tab[6][i] = new Roi(this,"RB",50,50,i*50,300);

    }

    /*for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout <<"Position piece : "<< i << "," <<j<< this->tab[i][j]->getX() << " , " << this->tab[i][j]->getY() << endl;
            }
    }*/

    /*for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Roi *test = new Roi(this,"RB",50,50,j*50,i*50);
            tab[i][j] = test;
            cout << "Roi : " << i <<" , " << j <<endl;
        }
    }*/
}
