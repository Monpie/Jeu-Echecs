#include "chessboard.h"
#include "ui_chessboard.h"


/*int ChessBoard::operator ++(int a){
    cout << "a = " << a << endl;
    a++;
    cout << "a++ = " << a << endl;
    return a;
}*/

ChessBoard& ChessBoard::operator ++(){
    cout << " a : " << this->a << endl;
    cout << "Operateur ++" << endl;
    this->a++;
    cout << " a : " << this->a;
    return *this;
}

//Constructeur initial
/*ChessBoard::ChessBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChessBoard)
{
    ui->setupUi(this);
    this->player1 = new Player(0);
    //this->player1->setHasPlayed(false);
    this->player2 = new Player(1);
 // this->player2->setHasPlayed(true);
    this->currentPlayer=this->player1;
    this->initGame(INIT_FILE);
    this->initPlayers();


    /*this->operator +(1);
    this->operator ++();


}*/

ChessBoard::ChessBoard(QString file,QWidget *parent):
    QDialog(parent),
    ui(new Ui::ChessBoard){
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->posDeadPiece.setX(0);
    this->posDeadPiece.setY(2);
    this->player1 = new Player(0);
    //this->player1->setHasPlayed(false);
    this->player2 = new Player(1);
    //this->player2->setHasPlayed(true);
    this->currentPlayer=this->player1;
    this->initGame(file);
    this->initPlayers();

    connect(this,SIGNAL(maxAtteint()),this,SLOT(upgradePion()));
    /*this->operator +(1);
    this->operator ++();*/
}

void ChessBoard::resizeEvent(QResizeEvent *e){
    qDebug() << "resize Event\n width = " << e->size().width() << " , height = " << e->size().height() << endl;
    //delete ui->label;
    ui->label->setFixedSize(1000,1000);
    /*ui->label = new QLabel(this);
    ui->label->setPixmap(QPixmap("/images/game/game/fond partie 1.jpg"));*/

   // ui->label->move(e->size().width()-100,e->size().height()-100);
   //ui->label->setVisible(true);
    //ui->label->setSizeIncrement(e->size());
   // ui->label->setFixedHeight(e->size().height());
  //  ui->label->setFixedWidth(e->size().width());
}

void ChessBoard::upgradePion(){

    cout << "methode slot appelé" << endl;
    ChoixUpgrade *choix = new ChoixUpgrade;
    connect(choix,SIGNAL(btn_reine_clicked()),this,SLOT(transformToReine()));
    connect(choix,SIGNAL(btn_tour_clicked()),this,SLOT(transformToTour()));
    connect(choix,SIGNAL(btn_cavalier_clicked()),this,SLOT(transformToCavalier()));
    connect(choix,SIGNAL(btn_fou_clicked()),this,SLOT(transformToFou()));
    choix->exec();
}

ChessBoard::~ChessBoard()
{
    delete ui;
}

void ChessBoard::transformToReine(){
    Reine *reine = new Reine(this,this->selectedPiece->getColor(),this->selectedPiece->getOwner(),this->selectedPiece->getWidth(),this->selectedPiece->getHeigth(),this->selectedPiece->getTabPosX()*TAILLECASE+25,this->selectedPiece->getTabPosY()*TAILLECASE);
    reine->setTabPosX(this->selectedPiece->getTabPosX());
    reine->setTabPosY(this->selectedPiece->getTabPosY());

    this->pieces.push_back(reine);
    reine->getOwner()->addPiece(reine);
    this->chessBoard[reine->getTabPosX()][reine->getTabPosY()] = reine->getPieceName();
    this->removePiece(this->selectedPiece);
    reine->getOwner()->removePiece(this->selectedPiece);
    delete this->selectedPiece;
    this->selectedPiece = reine;
}

void ChessBoard::transformToCavalier(){
    Cavalier *cavalier = new Cavalier(this,this->selectedPiece->getColor(),this->selectedPiece->getOwner(),this->selectedPiece->getWidth(),this->selectedPiece->getHeigth(),this->selectedPiece->getTabPosX()*TAILLECASE+25,this->selectedPiece->getTabPosY()*TAILLECASE);
    cavalier->setTabPosX(this->selectedPiece->getTabPosX());
    cavalier->setTabPosY(this->selectedPiece->getTabPosY());

    this->pieces.push_back(cavalier);
    cavalier->getOwner()->addPiece(cavalier);
    this->chessBoard[cavalier->getTabPosX()][cavalier->getTabPosY()] = cavalier->getPieceName();
    this->removePiece(this->selectedPiece);
    cavalier->getOwner()->removePiece(this->selectedPiece);
    delete this->selectedPiece;
    this->selectedPiece = cavalier;
}

void ChessBoard::transformToFou(){
    Fou *fou = new Fou(this,this->selectedPiece->getColor(),this->selectedPiece->getOwner(),this->selectedPiece->getWidth(),this->selectedPiece->getHeigth(),this->selectedPiece->getTabPosX()*TAILLECASE+25,this->selectedPiece->getTabPosY()*TAILLECASE);
    fou->setTabPosX(this->selectedPiece->getTabPosX());
    fou->setTabPosY(this->selectedPiece->getTabPosY());

    this->pieces.push_back(fou);
    fou->getOwner()->addPiece(fou);
    this->chessBoard[fou->getTabPosX()][fou->getTabPosY()] = fou->getPieceName();
    this->removePiece(this->selectedPiece);
    fou->getOwner()->removePiece(this->selectedPiece);
    delete this->selectedPiece;
    this->selectedPiece = fou;
}

void ChessBoard::transformToTour(){
    Tour *tour = new Tour(this,this->selectedPiece->getColor(),this->selectedPiece->getOwner(),this->selectedPiece->getWidth(),this->selectedPiece->getHeigth(),this->selectedPiece->getTabPosX()*TAILLECASE+25,this->selectedPiece->getTabPosY()*TAILLECASE);
    tour->setTabPosX(this->selectedPiece->getTabPosX());
    tour->setTabPosY(this->selectedPiece->getTabPosY());

    this->pieces.push_back(tour);
    tour->getOwner()->addPiece(tour);
    this->chessBoard[tour->getTabPosX()][tour->getTabPosY()] = tour->getPieceName();
    this->removePiece(this->selectedPiece);
    tour->getOwner()->removePiece(this->selectedPiece);
    delete this->selectedPiece;
    this->selectedPiece = tour;
}

void ChessBoard::paintEvent(QPaintEvent *)
{
    //a modifier

    QPainter painter(this);
    for(int i=0; i<8 ; i++){
        for(int j=0; j<8; j++){
            if(i%2==0){
                if(j%2==0){
                    caseBoard[i][j] = new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, QColor(36,68,92));
                }else{
                    caseBoard[i][j] = new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, QColor(206,206,206));
                }
            }else{
                if(j%2==0){
                    caseBoard[i][j]= new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, QColor(206,206,206));

                }else{
                    caseBoard[i][j]=new Case(TAILLECASE,i*TAILLECASE,j*TAILLECASE);
                    caseBoard[i][j]->draw(&painter, QColor(36,68,92));
                }
            }
        }
    }
    if(this->selectedPiece)
    {
        for(unsigned int i=0; i< this->selectedPiece->allPossibleMove.size();i++){
            this->possibleMove.push_back( new Case(TAILLECASE,this->selectedPiece->allPossibleMove.at(i).x()*TAILLECASE,this->selectedPiece->allPossibleMove[i].y()*TAILLECASE));
            this->possibleMove.at(i)->draw(&painter, QColor(255,87,51,150));

        }
    }
}

//____________________________________________________________DEPLACEMENT PIECE___________________________________________________
void ChessBoard::mousePressEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton ){
        if(this->selectedPiece){
            if(this->selectedPiece->isValidMove(floor(event->x()/TAILLECASE),floor(event->y()/TAILLECASE),this->pieces) && !this->selectedPiece->getOwner()->getHasPlayed())
              //  if(!this->selectedPiece->getOwner()->getHasPlayed())
            {

                ///***Détruire la pièce si elle est mangée***///
                Piece * test = this->getPieceAt((int)floor(event->x()/TAILLECASE),(int)floor(event->y()/TAILLECASE));
                if(test && test!=this->selectedPiece && test->getOwner()!=this->selectedPiece->getOwner()){
                    //if(test->getOwner()==this->player1)
                        test->move(this->posDeadPiece.x()+8,this->posDeadPiece.y());
                   /* else
                        test->move(this->posDeadPiece.x()+10,this->posDeadPiece.y());*/
                    this->posDeadPiece.setX(this->posDeadPiece.x()+1);
                    if(this->posDeadPiece.x()%6==0){
                        this->posDeadPiece.setY(this->posDeadPiece.y()+1);
                        this->posDeadPiece.setX(0);
                    }
                    if(test->getIsKing())
                    {
                        QMessageBox *msg = new QMessageBox(this);
                        QString test("Joueur ");
                        test+=QString::number(this->selectedPiece->getOwner()->getId()+1);
                        test.operator +=(" a gagné !");

                        msg->setText(test);
                        msg->addButton("Ok",QMessageBox::AcceptRole);
                        msg->exec();
                        this->close();
                        MainMenu menu;
                        menu.exec();
                    }

                    this->removePiece(test);

                    this->selectedPiece->getOwner()->removePiece(test);
                }

                ///*****************************************///

                ///*****Gestion du déplacement de la pièce*****///
                this->selectedPiece->move(floor(event->x()/TAILLECASE),floor(event->y()/TAILLECASE));
                this->chessBoard[(int)(floor(this->selectedPiece->getOldY()/TAILLECASE))][(int)(floor(this->selectedPiece->getOldX()/TAILLECASE))] = '0';
                this->chessBoard[(int)floor(event->y()/TAILLECASE)][(int)floor(event->x()/TAILLECASE)] = this->selectedPiece->getPieceName();

                ///********************************************///

                if(this->selectedPiece->getIsPion() && (this->selectedPiece->getTabPosY()==7 || this->selectedPiece->getTabPosY()==0))
                    emit maxAtteint();

                ///******Gestion tour joueur******///
                this->currentPlayer->setHasPlayed(true);
                if(this->currentPlayer==this->player1){
                    this->currentPlayer=this->player2;
                    ui->namePlayer->setText("Joueur 2");
                }else{
                    this->currentPlayer=this->player1;
                    ui->namePlayer->setText("Joueur 1");
                }
                this->currentPlayer->setHasPlayed(false);

                ///******************************///

            }

            this->selectedPiece->allPossibleMove.clear();
            this->possibleMove.clear();
            this->selectedPiece = NULL;
            this->update();
        }
        else{
            for(unsigned int i=0;i<this->pieces.size();i++){
                if(this->currentPlayer==this->pieces[i]->getOwner() && (event->x() > this->pieces.at(i)->getTabPosX()*TAILLECASE+CHESSBOARD_POS.x() && event->x() <this->pieces.at(i)->getTabPosX()*TAILLECASE+TAILLECASE+CHESSBOARD_POS.x() && event->y() > this->pieces.at(i)->getY() && event->y() < this->pieces.at(i)->getTabPosY()*TAILLECASE+TAILLECASE+CHESSBOARD_POS.y())){
                    this->selectedPiece = this->pieces.at(i);
                    this->selectedPiece->setOldX(event->x());
                    this->selectedPiece->setOldY(event->y());

                    if(this->selectedPiece->getIsPion()){
                        Pion *pion = static_cast<Pion *>(this->selectedPiece);
                        pion->canAttack(this->chessBoard);
                       }

                    /*for(int i=0;i<8;i++)
                    {
                        for(int j=0;j<8;j++){
                            if(this->selectedPiece->isValidMove(i,j,this->pieces))
                            {
                                this->selectedPiece->allPossibleMove.push_back(QPoint(i,j));

                            }
                        }
                    }*/
                    this->selectedPiece->pos.setX(this->selectedPiece->getTabPosX());
                    this->selectedPiece->pos.setY(this->selectedPiece->getTabPosY());
                    QPoint p(this->selectedPiece->operator -(QPoint(4,4)));
                    this->selectedPiece->updateAllPossibleMove(this->pieces);
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

//____________________________________________________________INITIALISATION JEU__________________________________________________
void ChessBoard::initGame(QString fichier){
    this->lectureFichier(fichier.toStdString());
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
        cout << chessBoard[i][j] << " ";
        cout << endl;
    }

    for(int i=0; i<8;i++){
        for(int j=0; j<8;j++){
            switch(chessBoard[i][j])
            {
            case '1':
            {
                Pion *pion = new Pion(this,"Blanc",this->player1,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                pion->setTabPosX(j);
                pion->setTabPosY(i);
                this->pieces.push_back(pion);
                break;
            }
            case '2' :
            {
                Cavalier *cavalier = new Cavalier(this,"Blanc",this->player1 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                cavalier->setTabPosX(j);
                cavalier->setTabPosY(i);
                this->pieces.push_back(cavalier);
                break;
            }
            case '3' :
            {
                Tour *tour = new Tour(this,"Blanc",this->player1 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                tour->setTabPosX(j);
                tour->setTabPosY(i);
                this->pieces.push_back(tour);
                break;
            }
            case '4' :
            {
                Fou *fou = new Fou(this,"Blanc",this->player1 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                fou->setTabPosX(j);
                fou->setTabPosY(i);
                this->pieces.push_back(fou);
                break;
            }
            case '5' :
            {
                Reine *reine = new Reine(this,"Blanc",this->player1 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                reine->setTabPosX(j);
                reine->setTabPosY(i);
                this->pieces.push_back(reine);
                break;
            }
            case '6' :
            {
                Roi *roi = new Roi(this,"Blanc",this->player1 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                roi->setTabPosX(j);
                roi->setTabPosY(i);
                this->pieces.push_back(roi);
                break;
            }
            case 'p' :
            {
                Pion *pion2 = new Pion(this,"Noir",this->player2 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                pion2->setTabPosX(j);
                pion2->setTabPosY(i);
                this->pieces.push_back(pion2);
                break;
            }
            case 't' :
            {
                Tour *tour = new Tour(this,"Noir",this->player2 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                tour->setTabPosX(j);
                tour->setTabPosY(i);
                this->pieces.push_back(tour);
                break;
            }
            case 'c' :
            {
                Cavalier *cavalier = new Cavalier(this,"Noir",this->player2 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                cavalier->setTabPosX(j);
                cavalier->setTabPosY(i);
                this->pieces.push_back(cavalier);
                break;
            }
            case 'f' :
            {
                Fou *fou = new Fou(this,"Noir",this->player2 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                fou->setTabPosX(j);
                fou->setTabPosY(i);
                this->pieces.push_back(fou);
                break;
            }
            case 'k' :
            {
                Roi *roi = new Roi(this,"Noir",this->player2 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
                roi->setTabPosX(j);
                roi->setTabPosY(i);
                this->pieces.push_back(roi);
                break;
            }
            case 'q' :
            {
                Reine *reine = new Reine(this,"Noir",this->player2 ,50,50,j*TAILLECASE+CENTRER_PIECE+CHESSBOARD_POS.x(),i*TAILLECASE+CHESSBOARD_POS.y());
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

    try{
        ifstream fichier(sauvegarde, ios::in);  // on ouvre le fichier en lecture
        string ligne;
        if(!fichier)
            throw QException();

        for(int i=0;i<8;i++){
            getline(fichier, ligne);
            for(int j=0;j<8;j++){
                this->chessBoard[i][j] = ligne[j];
            }
        }
        getline(fichier,ligne);
        cout << "ligne = " << ligne[0] << endl;
        if(ligne[0]=='j')
            this->currentPlayer=this->player2;
        else
            this->currentPlayer=this->player1;

        fichier.close();
    }catch(QException e){
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Jeu impossible");
        msg->exec();

        //Initialisation de l'échiquier
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                this->chessBoard[i][j] = '0';

        this->chessBoard[0][0] = '3';
        this->chessBoard[0][1] = '2';
        this->chessBoard[0][2] = '4';
        this->chessBoard[0][3] = '6';
        this->chessBoard[0][4] = '5';
        this->chessBoard[0][5] = '4';
        this->chessBoard[0][6] = '2';
        this->chessBoard[0][7] = '3';

        this->chessBoard[7][0] = 't';
        this->chessBoard[7][1] = 'c';
        this->chessBoard[7][2] = 'f';
        this->chessBoard[7][3] = 'k';
        this->chessBoard[7][4] = 'q';
        this->chessBoard[7][5] = 'f';
        this->chessBoard[7][6] = 'c';
        this->chessBoard[7][7] = 't';


        for(int i=0;i<8;i++)
        {
            this->chessBoard[1][i] = '1';
            this->chessBoard[6][i] = 'p';
        }

        //Ecriture du fichier d'initialisation
        this->ecritureFichierSauvegarde("initialisation.txt");


    }
}



//Ecriture fichier sauvegarde
void ChessBoard::ecritureFichierSauvegarde(QString fileName)
{
    try{
        ofstream fichier(fileName.toStdString(), ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    if(!fichier)
        throw QException();

    for (int cpt1=0; cpt1<8 ;cpt1++ )
    {
        for (int cpt2=0; cpt2<8 ;cpt2++ )
        {
            fichier<<chessBoard[cpt1][cpt2];
        }

        fichier<<endl;
    }
    if(this->currentPlayer==this->player1)
        fichier<<'9';
    else
        fichier<<'j';
    fichier.close();
    }catch (QException e){
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Impossible de trouver le fichier sauvegarde");
        msg->exec();
    }
}


//Appui du bouton sauvegarde
void ChessBoard::on_boutonSauvegarder_clicked()
{
    this->ecritureFichierSauvegarde("sauvegarde.txt");
}


//Gestion du bouton quitter
void ChessBoard::on_pushButton_clicked()
{
    this->close();
    MainMenu menu;
    menu.exec();
}


//__________________________________CENTRER CASE___________________________________

void ChessBoard::initPlayers(){
    for(unsigned int i=0;i<this->pieces.size();i++){
        if(this->pieces[i]->getOwner()==this->player1){
            this->player1->addPiece(this->pieces[i]);
        }else{
            this->player2->addPiece(this->pieces[i]);
        }
    }
}

Piece * ChessBoard::getPieceAt(int x, int y){
    for(unsigned int i=0;i<this->pieces.size();i++)
    {
        if(x==this->pieces[i]->getTabPosX() && y==this->pieces[i]->getTabPosY())
        {
            return this->pieces[i];
        }
    }
    return 0;
}

int ChessBoard::operator +(int a){
    int res = a+a;
    cout << "a : "<< a  << ", res : " << res << endl;
    return res;
}

void ChessBoard::removePiece(Piece *piece){
    for(std::vector<Piece *>::iterator it = pieces.begin() ; it < pieces.end(); it++)
        if(piece==*it){
            this->pieces.erase(it);
        }
}
