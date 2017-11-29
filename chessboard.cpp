#include "chessboard.h"
#include "ui_chessboard.h"
#include <QPainter>
#include "pion.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <QGridLayout>
#include <QHBoxLayout>


//Constructeur initial
ChessBoard::ChessBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChessBoard)
{
    ui->setupUi(this);
}



ChessBoard::~ChessBoard()
{
    delete ui;
}

void ChessBoard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for(int i=0; i<8 ; i++){
        for(int j=0; j<8; j++){
            if(i%2==0){
                if(j%2==0){
                    caseBoard[i][j] = new Case(this->TAILLE,i*this->TAILLE,j*this->TAILLE);
                    caseBoard[i][j]->draw(&painter, Qt::white);
                }else{
                    caseBoard[i][j] = new Case(this->TAILLE,i*this->TAILLE,j*this->TAILLE);
                    caseBoard[i][j]->draw(&painter, Qt::gray);
                }
            }else{
                if(j%2==0){
                    caseBoard[i][j]= new Case(this->TAILLE,i*this->TAILLE,j*this->TAILLE);
                    caseBoard[i][j]->draw(&painter, Qt::gray);

                }else{
                    caseBoard[i][j]=new Case(this->TAILLE,i*this->TAILLE,j*this->TAILLE);
                    caseBoard[i][j]->draw(&painter, Qt::white);
                }
            }
        }
    }
}

//____________________________________________________________DEPLACEMENT PIECE___________________________________________________
void ChessBoard::mousePressEvent(QMouseEvent *event){
    //cout << event->pos().x() << "pos pion : " << this->piece->getX()<< endl;
    if(event->buttons() & Qt::LeftButton ){
        //qDebug("OK");
        for(int i=0;i<this->pieces.size();i++){
            if(event->x() > this->pieces.at(i)->getX() && event->x() <this->pieces.at(i)->getX()+50 && event->y() > this->pieces.at(i)->getY() && event->y() < this->pieces.at(i)->getY()+50){
                cout << "valid click" << endl;
                cout << event->pos().x() << "old pos x pion : " << this->pieces.at(i)->getX()<< "old pos y pion : " << this->pieces.at(i)->getY() << endl;
                //cout << this->pieces.at(i)->getX()+50 << " , " << this->pieces.at(i)->getY()+50 << endl;
                cout << this->pieces.at(i)->getTabPosX() << " , " << this->pieces.at(i)->getTabPosY() << endl;
               // this->pieces.at(i)->validClick(event);
                this->selectedPiece = this->pieces.at(i);
                this->selectedPiece->setOldX(event->x());
                this->selectedPiece->setOldY(event->y());
            }
        }

        /*this->piece->validClick(event);
        this->piece->setOldX(this->piece->getX());
        this->piece->setOldY(this->piece->getY());
        this->secondRoi->validClick(event);
        this->secondRoi->setOldX(this->secondRoi->getX());
        cout << event->pos().x() << "old pos x pion : " << this->secondRoi->getOldX()<< "old pos y pion : " << this->secondRoi->getOldY() << endl;
        this->secondRoi->setOldY(this->secondRoi->getY());*/

    }
}

void ChessBoard::mouseReleaseEvent(QMouseEvent *event){
    qDebug("releaseEvent");
    this->isClicked = false;
    /*if(this->currentPlayer==0)
        this->currentPlayer=1;
    else
        this->currentPlayer = 0;*/

    // cout << "current player : " << this->currentPlayer << endl;
}

void ChessBoard::mouseMoveEvent(QMouseEvent *event){
    //if(this->selectedPiece->isValidMove())
    //cout << (int)(this->selectedPiece->getX()/75) << endl;
    cout << " piece pos x : " << this->selectedPiece->getX() << " , old x : " << this->selectedPiece->getOldX() << endl;
    cout << " pos curseur x : " << event->x() << " , y :" << event->y() << endl;
   /* if(event->x() > this->selectedPiece->getOldX() && event->x() < this->selectedPiece->getOldX() +150){
        qDebug("Move ok");
        this->selectedPiece->move(event->x(),event->y());
    }*/

    this->selectedPiece->move(event->x(),event->y());



   /* for(int i=0;i<this->pieces.size();i++){
        if(this->pieces.at(i)->validClick(event))
            this->pieces.at(i)->move(event->x(),event->y());
    }*/
    //qDebug("moveEvent");
    /*if(this->piece->validClick(event) && this->piece->getMyOwner()==this->currentPlayer)
    {

        this->piece->move(event->x()-this->taille/4,event->y()-this->taille/4);
    }else if(this->secondRoi->validClick(event) && this->secondRoi->getMyOwner()==this->currentPlayer){
        this->secondRoi->move(event->x()-this->taille/4,event->y()-this->taille/4);
    }*/
}


//____________________________________________________________INITIALISATION JEU__________________________________________________
void ChessBoard::initGame(string fichier){
    this->lectureFichier(fichier);
    for(int i=0; i<8;i++){
        for(int j=0; j<8;j++){
            switch(chessBoard[i][j])
            {
            case '1' :
                Pion *pion = new Pion(this,"Blanc",1,50,50,j*75 +25,i*75);
                pion->setTabPosX(i);
                pion->setTabPosY(j);
                this->pieces.push_back(pion);
                break;
           /* case '2' :
                this->pieces.push_back(new Cavalier(this,"Blanc",1 ,50,50,j*75 +25,i*75));
                break;
            case '3' :
                this->pieces.push_back(new Tour(this,"Blanc", 1,50,50,j*75 +25,i*75));
                break;
            case '4' :
                this->pieces.push_back(new Fou(this,"Blanc", 1 ,50,50,j*75 +25,i*75));
                break;
            case '5' :
                this->pieces.push_back(new Reine(this,"Blanc", 1 ,50,50,j*75 +25,i*75));
                break;
            case '6' :
                this->pieces.push_back(new Roi(this,"Blanc", 1 ,50,50,j*75 +25,i*75));
                break;
            case 'p' :
                this->pieces.push_back(new Pion(this,"Noir",2,50,50,j*75 +25,i*75));
                break;
            case 't' :
                this->pieces.push_back(new Tour(this,"Noir",2,50,50,j*75 +25,i*75));
                break;
            case 'c' :
                this->pieces.push_back(new Cavalier(this,"Noir",2,50,50,j*75 +25,i*75));
                break;
            case 'f' :
                this->pieces.push_back(new Fou(this,"Noir",2,50,50,j*75 +25,i*75));
                break;
            case 'k' :
                this->pieces.push_back(new Roi(this,"Noir",2,50,50,j*75 +25,i*75));
                break;
            case 'q' :
                this->pieces.push_back(new Reine(this,"Noir",2,50,50,j*75 +25,i*75));
                break;*/
            }
        }
    }
}




//____________________________________________________________GESTION LECTURE FICHIER___________________________________________________


void ChessBoard::modifierCase(char valeur, int ligne, int colonne)
{
    chessBoard[ligne][colonne]= valeur;
}

//Méthode pour lire un fichier
void ChessBoard::lectureFichier(string sauvegarde){

    ifstream fichier(sauvegarde, ios::in);  // on ouvre le fichier en lecture
    if(fichier)  // si l'ouverture a réussi
    {
        cout<<"fichier ouvert"<<endl;
        string ligne;

        for(int i=0;i<8;i++){
                            getline(fichier, ligne);
            for(int j=0;j<8;j++){

                this->chessBoard[i][j] = ligne[j];
            }
        }

        /*for(int cpt1=0; cpt1<8 ; cpt1++)
        {
            getline(fichier, ligne);
            cout <<"valeur cptLigne "<< cptLigne<< " valeur cpt "<< cpt1 << endl;
            this->chessBoard[cpt1][cpt1] = ligne[cpt1];
            /*chessBoard[cptLigne][0]= ligne[0];
            chessBoard[cptLigne][1]= ligne[1];
            chessBoard[cptLigne][2]= ligne[2];
            chessBoard[cptLigne][3]= ligne[3];
            chessBoard[cptLigne][4]= ligne[4];
            chessBoard[cptLigne][5]= ligne[5];
            chessBoard[cptLigne][6]= ligne[6];
            chessBoard[cptLigne][7]= ligne[7];
            cptLigne++;
        }*/


        /*//Affichage du tableau
        cout<<endl;
        cout<<"Affichage tableau"<<endl;
        for(int cpt1=0; cpt1<8; cpt1++)
        {

            for(int cpt2=0; cpt2<8; cpt2++)
            {
                cout<<chessBoard[cpt1][cpt2];
            }
            cout<<endl;
        }*/

        fichier.close();
    }
    else //sinon
    {    cout<<"erreur"<<endl;
        cerr << "Impossible d'ouvrir le fichier !" << endl;}


}



//Ecriture fichier sauvegarde
void ChessBoard::ecritureFichierSauvegarde()
{
    using namespace std;
    ofstream fichier("sauvegarde.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    if(fichier)

    {

        for (int cpt1=0; cpt1<8 ;cpt1++ )
        {
            for (int cpt2=0; cpt2<8 ;cpt2++ )
            {
                fichier<<chessBoard[cpt1][cpt2];
            }

            fichier<<endl;
        }

        fichier.close();

    }

    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}


//Appui du bouton sauvegarde
void ChessBoard::on_boutonSauvegarder_clicked()
{
    this->lectureFichier("initialisation.txt");
    this->ecritureFichierSauvegarde();
}

