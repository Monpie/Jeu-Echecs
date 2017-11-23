#include "chessboard.h"
#include "ui_chessboard.h"
#include <QPainter>
#include "pion.h"

#include <iostream>
#include <ostream>
#include <fstream>



using namespace std;
char chessBoard [8][8];

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
                        c.draw(&painter, Qt::gray);
                    }
                }else{
                    if(j%2==0){
                        Case c(50,i*50,j*50);
                        c.draw(&painter, Qt::gray);

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
    //this->lectureFichier("initialisation.txt");

    /*for(int i=0; i<8;i++){
        for(int j=0; j<8;j++){
            switch()
            {
                case
            }
        }
    }*/
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


//Méthode pour lire un fichier
void ChessBoard::lectureFichier(){
    //Variable

    int cptLigne = 0;

    //QFile fichier("initialisation.txt");
    ifstream fichier("initialisation.txt", ios::in);  // on ouvre le fichier en lecture
    if(fichier)  // si l'ouverture a réussi
    {
        cout<<"fichier ouvert"<<endl;
        string ligne;
        for(int cpt1=0; cpt1<8 ; cpt1++)
        {

                getline(fichier, ligne);
                //cout<<ligne<<endl;

                cout<<"ligne[1]"<<ligne[2];


                chessBoard[cptLigne][0]= ligne[0];
                chessBoard[cptLigne][1]= ligne[1];
                chessBoard[cptLigne][2]= ligne[2];
                chessBoard[cptLigne][3]= ligne[3];
                chessBoard[cptLigne][4]= ligne[4];
                chessBoard[cptLigne][5]= ligne[5];
                chessBoard[cptLigne][6]= ligne[6];
                chessBoard[cptLigne][7]= ligne[7];
                cptLigne++;

        }


        //Affichage du tableau
        cout<<endl;
        cout<<"Affichage tableau"<<endl;
        for(int cpt1=0; cpt1<8; cpt1++)
        {

            for(int cpt2=0; cpt2<8; cpt2++)
            {
                cout<<chessBoard[cpt1][cpt2];
            }
            cout<<endl;
        }

        fichier.close();
    }
       else //sinon
           {    cout<<"erreur"<<endl;
            cerr << "Impossible d'ouvrir le fichier !" << endl;}


}


//Appui du bouton sauvegarde
void ChessBoard::on_boutonSauvegarder_clicked()
{
    this->lectureFichier();
}

