#include "chessboard.h"
#include "ui_chessboard.h"
#include <QPainter>
#include "pion.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <QGridLayout>
#include <QHBoxLayout>
#include "constante.h"
#include "math.h"

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
                    caseBoard[i][j] = new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, Qt::white);
                }else{
                    caseBoard[i][j] = new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, Qt::gray);
                }
            }else{
                if(j%2==0){
                    caseBoard[i][j]= new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, Qt::gray);

                }else{
                    caseBoard[i][j]=new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, Qt::white);
                }
            }
        }
    }
}

//____________________________________________________________DEPLACEMENT PIECE___________________________________________________
void ChessBoard::mousePressEvent(QMouseEvent *event){
       if(event->buttons() & Qt::LeftButton ){
        for(unsigned int i=0;i<this->pieces.size();i++){
            if(event->x() > this->pieces.at(i)->getX() && event->x() <this->pieces.at(i)->getX()+50 && event->y() > this->pieces.at(i)->getY() && event->y() < this->pieces.at(i)->getY()+50){
                //cout << event->pos().x() << "old pos x pion : " << this->pieces.at(i)->getX()<< "old pos y pion : " << this->pieces.at(i)->getY() << endl;
                //cout << this->pieces.at(i)->getX()+50 << " , " << this->pieces.at(i)->getY()+50 << endl;
                cout << this->pieces.at(i)->getTabPosX() << " , " << this->pieces.at(i)->getTabPosY() << endl;
               // this->pieces.at(i)->validClick(event);
                this->selectedPiece = this->pieces.at(i);
                this->selectedPiece->setOldX(event->x());
                this->selectedPiece->setOldY(event->y());
            }

          /* QLabel *test  = static_cast<QLabel*> (this->childAt(event->pos()));
           if(test->inherits("QLabel")){
               cout << "if ok" << endl;
               this->selectedPiece = dynamic_cast <Piece*> (this->childAt(event->pos()));
           }*/

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

void ChessBoard::mouseReleaseEvent(QMouseEvent *event){
    qDebug("releaseEvent");
    this->isClicked = false;
    //cout << "oldPosTabX = " << this->selectedPiece->getTabPosX() << ", y= " << this->selectedPiece->getTabPosY() << endl;
   // this->selectedPiece->setTabPosX(floor(event->x()/TAILLECASE));
  //  this->selectedPiece->setTabPosY(floor(event->y()/TAILLECASE));
    //cout << "newPosTabX = " << this->selectedPiece->getTabPosX() << ", y= " << this->selectedPiece->getTabPosY() << endl;
    if(this->selectedPiece!=NULL)
        this->centrerPiece(this->selectedPiece, event->pos());
    this->selectedPiece = NULL;



    /*if(this->currentPlayer==0)
        this->currentPlayer=1;
    else
        this->currentPlayer = 0;*/

    // cout << "current player : " << this->currentPlayer << endl;
}

void ChessBoard::mouseMoveEvent(QMouseEvent *event){

    if(this->selectedPiece!=NULL) {
        this->selectedPiece->move(event->x()-TAILLECASE/4,event->y()-TAILLECASE/4);
   // cout << " piece pos x : " << this->selectedPiece->getX() << " , old x : " << this->selectedPiece->getOldX() << endl;
   // cout << " pos curseur x : " << event->x() << " , y :" << event->y() << endl;
}


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
            case '1':
            {
                Pion *pion = new Pion(this,"Blanc",1,50,50,j*TAILLECASE+25,i*TAILLECASE);
                pion->setTabPosX(j);
                pion->setTabPosY(i);
                this->pieces.push_back(pion);
                break;
            }
            case '2' :
            {
                Cavalier *cavalier = new Cavalier(this,"Blanc",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                cavalier->setTabPosX(j);
                cavalier->setTabPosY(i);
                this->pieces.push_back(cavalier);
                break;
            }
            case '3' :
            {
                Tour *tour = new Tour(this,"Blanc",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                tour->setTabPosX(j);
                tour->setTabPosY(i);
                this->pieces.push_back(tour);
                break;
            }
            case '4' :
            {
                Fou *fou = new Fou(this,"Blanc",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                fou->setTabPosX(j);
                fou->setTabPosY(i);
                this->pieces.push_back(fou);
                break;
            }
            case '5' :
            {
                Reine *reine = new Reine(this,"Blanc",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                reine->setTabPosX(j);
                reine->setTabPosY(i);
                this->pieces.push_back(reine);
                break;
            }
            case '6' :
            {
                Roi *roi = new Roi(this,"Blanc",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                roi->setTabPosX(j);
                roi->setTabPosY(i);
                this->pieces.push_back(roi);
                break;
            }
            case 'p' :
            {
                Pion *pion2 = new Pion(this,"Noir",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                pion2->setTabPosX(j);
                pion2->setTabPosY(i);
                this->pieces.push_back(pion2);
                break;
            }
            case 't' :
            {
                Tour *tour = new Tour(this,"Noir",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                tour->setTabPosX(j);
                tour->setTabPosY(i);
                this->pieces.push_back(tour);
                break;
            }
            case 'c' :
            {
                Cavalier *cavalier = new Cavalier(this,"Noir",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                cavalier->setTabPosX(j);
                cavalier->setTabPosY(i);
                this->pieces.push_back(cavalier);
                break;
            }
            case 'f' :
            {
                Fou *fou = new Fou(this,"Noir",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                fou->setTabPosX(j);
                fou->setTabPosY(i);
                this->pieces.push_back(fou);
                break;
            }
            case 'k' :
            {
                Roi *roi = new Roi(this,"Noir",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                roi->setTabPosX(j);
                roi->setTabPosY(i);
                this->pieces.push_back(roi);
                break;
            }
            case 'q' :
            {
                Reine *reine = new Reine(this,"Noir",1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                reine->setTabPosX(j);
                reine->setTabPosY(i);
                this->pieces.push_back(reine);
                break;
            }
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
    //this->lectureFichier("initialisation.txt");
    this->ecritureFichierSauvegarde();
}


//Gestion du bouton quitter
void ChessBoard::on_pushButton_clicked()
{
    this->close();
    MainMenu menu;
    menu.exec();

}


//__________________________________CENTRER CASE___________________________________





void ChessBoard::centrerPiece(Piece *piece, QPoint pos){
    int posX = floor(pos.x()/TAILLECASE);
    int posY = floor(pos.y()/TAILLECASE);
    piece->move((posX)*TAILLECASE+25,(posY)*TAILLECASE);
    piece->setTabPosX(posX);
    piece->setTabPosY(posY);
    cout << "oldX = " << piece->getOldX() << ", oldY = " << piece->getOldY() << endl;
    cout << "i = " << (int)(floor(piece->getOldX()/TAILLECASE)) << ", j = " << (int)(floor(piece->getOldY()/TAILLECASE))<< endl;
    this->chessBoard[(int)(floor(piece->getOldY()/TAILLECASE))][(int)(floor(piece->getOldX()/TAILLECASE))] = '0';
    this->chessBoard[posY][posX] = piece->getPieceName();

}
