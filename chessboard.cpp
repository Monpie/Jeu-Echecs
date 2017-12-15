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
    this->player1 = new Player(0);
    this->player2 = new Player(1);
    this->initGame("initialisation.txt");
    this->initPlayers();
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
                    caseBoard[i][j]->draw(&painter, Qt::darkBlue);
                }else{
                    caseBoard[i][j] = new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, Qt::lightGray);
                }
            }else{
                if(j%2==0){
                    caseBoard[i][j]= new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, Qt::lightGray);

                }else{
                    caseBoard[i][j]=new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, Qt::darkBlue);
                }
            }
        }
    }
    if(this->selectedPiece)
    {
        for(int i=0; i< this->selectedPiece->allPossibleMove.size();i++){
            this->possibleMove.push_back( new Case(TAILLECASE,this->selectedPiece->allPossibleMove.at(i).x()*TAILLECASE,this->selectedPiece->allPossibleMove[i].y()*TAILLECASE));
            this->possibleMove.at(i)->draw(&painter, Qt::white);

        }
    }
}

//____________________________________________________________DEPLACEMENT PIECE___________________________________________________
void ChessBoard::mousePressEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton ){
        if(this->selectedPiece){
            if(this->selectedPiece->isValidMove(floor(event->x()/TAILLECASE),floor(event->y()/TAILLECASE)))
            {
                Piece * test = this->getPieceAt((int)floor(event->x()/TAILLECASE),(int)floor(event->y()/TAILLECASE));
                if(test && test!=this->selectedPiece && test->getOwner()!=this->selectedPiece->getOwner())
                    delete test;

                this->selectedPiece->move(floor(event->x()/TAILLECASE),floor(event->y()/TAILLECASE));
                this->chessBoard[(int)(floor(this->selectedPiece->getOldY()/TAILLECASE))][(int)(floor(this->selectedPiece->getOldX()/TAILLECASE))] = '0';
                this->chessBoard[(int)floor(event->y()/TAILLECASE)][(int)floor(event->x()/TAILLECASE)] = this->selectedPiece->getPieceName();
            }

            /*for(int i=0; i<this->selectedPiece->allPossibleMove.size();i++){
                cout << "move : " << i << " " << this->selectedPiece->allPossibleMove.at(i).x() << ", y = " << this->selectedPiece->allPossibleMove.at(i).y() << endl;
            }*/

            this->selectedPiece->allPossibleMove.clear();
            this->possibleMove.clear();
            this->selectedPiece = NULL;
            this->update();
        }
        else{
            for(unsigned int i=0;i<this->pieces.size();i++){
                if(event->x() > this->pieces.at(i)->getTabPosX()*TAILLECASE && event->x() <this->pieces.at(i)->getTabPosX()*TAILLECASE+TAILLECASE && event->y() > this->pieces.at(i)->getY() && event->y() < this->pieces.at(i)->getY()+TAILLECASE){
                    //cout << event->pos().x() << "old pos x pion : " << this->pieces.at(i)->getX()<< "old pos y pion : " << this->pieces.at(i)->getY() << endl;
                    //cout << this->pieces.at(i)->getX()+50 << " , " << this->pieces.at(i)->getY()+50 << endl;
                    cout << this->pieces.at(i)->getTabPosX() << " , " << this->pieces.at(i)->getTabPosY() << endl;
                    this->selectedPiece = this->pieces.at(i);
                    this->selectedPiece->setOldX(event->x());
                    this->selectedPiece->setOldY(event->y());

                    if(this->selectedPiece->getIsPion()){
                        Pion *pion = static_cast<Pion *>(this->selectedPiece);
                        pion->canAttack(this->chessBoard);
                    }
                    for(int i=0;i<8;i++)
                    {
                        for(int j=0;j<8;j++){
                            if(this->selectedPiece->isValidMove(i,j))
                            {
                                this->selectedPiece->allPossibleMove.push_back(QPoint(i,j));
                            }
                        }
                    }
                    this->update();
                }

                /* QLabel *test  = static_cast<QLabel*> (this->childAt(event->pos()));
           if(test->inherits("QLabel")){
               cout << "if ok" << endl;
               this->selectedPiece = dynamic_cast <Piece*> (this->childAt(event->pos()));
           }*/
            }
        }
    }
}

/*void ChessBoard::mouseReleaseEvent(QMouseEvent *event){
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
        this->currentPlayer = 0;

    // cout << "current player : " << this->currentPlayer << endl;
}*/

/*void ChessBoard::mouseMoveEvent(QMouseEvent *event){

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
    }
}*/


//____________________________________________________________INITIALISATION JEU__________________________________________________
void ChessBoard::initGame(string fichier){
    this->lectureFichier(fichier);
    for(int i=0; i<8;i++){
        for(int j=0; j<8;j++){
            switch(chessBoard[i][j])
            {
            case '1':
            {
                Pion *pion = new Pion(this,"Blanc",this->player1,50,50,j*TAILLECASE+25,i*TAILLECASE);
                pion->setTabPosX(j);
                pion->setTabPosY(i);
                this->pieces.push_back(pion);
                break;
            }
            case '2' :
            {
                Cavalier *cavalier = new Cavalier(this,"Blanc",this->player1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                cavalier->setTabPosX(j);
                cavalier->setTabPosY(i);
                this->pieces.push_back(cavalier);
                break;
            }
            case '3' :
            {
                Tour *tour = new Tour(this,"Blanc",this->player1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                tour->setTabPosX(j);
                tour->setTabPosY(i);
                this->pieces.push_back(tour);
                break;
            }
            case '4' :
            {
                Fou *fou = new Fou(this,"Blanc",this->player1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                fou->setTabPosX(j);
                fou->setTabPosY(i);
                this->pieces.push_back(fou);
                break;
            }
            case '5' :
            {
                Reine *reine = new Reine(this,"Blanc",this->player1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                reine->setTabPosX(j);
                reine->setTabPosY(i);
                this->pieces.push_back(reine);
                break;
            }
            case '6' :
            {
                Roi *roi = new Roi(this,"Blanc",this->player1 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                roi->setTabPosX(j);
                roi->setTabPosY(i);
                this->pieces.push_back(roi);
                break;
            }
            case 'p' :
            {
                Pion *pion2 = new Pion(this,"Noir",this->player2 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                pion2->setTabPosX(j);
                pion2->setTabPosY(i);
                this->pieces.push_back(pion2);
                break;
            }
            case 't' :
            {
                Tour *tour = new Tour(this,"Noir",this->player2 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                tour->setTabPosX(j);
                tour->setTabPosY(i);
                this->pieces.push_back(tour);
                break;
            }
            case 'c' :
            {
                Cavalier *cavalier = new Cavalier(this,"Noir",this->player2 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                cavalier->setTabPosX(j);
                cavalier->setTabPosY(i);
                this->pieces.push_back(cavalier);
                break;
            }
            case 'f' :
            {
                Fou *fou = new Fou(this,"Noir",this->player2 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                fou->setTabPosX(j);
                fou->setTabPosY(i);
                this->pieces.push_back(fou);
                break;
            }
            case 'k' :
            {
                Roi *roi = new Roi(this,"Noir",this->player2 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
                roi->setTabPosX(j);
                roi->setTabPosY(i);
                this->pieces.push_back(roi);
                break;
            }
            case 'q' :
            {
                Reine *reine = new Reine(this,"Noir",this->player2 ,50,50,j*TAILLECASE +25,i*TAILLECASE);
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
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


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

void ChessBoard::initPlayers(){
    for(int i=0;i<this->pieces.size();i++){
        if(this->pieces[i]->getOwner()==this->player1){
            this->player1->addPiece(this->pieces[i]);
        }else{
            this->player2->addPiece(this->pieces[i]);
        }
    }
}

Piece * ChessBoard::getPieceAt(int x, int y){
    for(int i=0;i<this->pieces.size();i++)
    {
        if(x==this->pieces[i]->getTabPosX() && y==this->pieces[i]->getTabPosY())
        {
            cout << "piece : " << this->pieces[i]->getPieceName() << endl;
            return this->pieces[i];
        }
    }
    cout << "NULL" << endl;
    return 0;
}
