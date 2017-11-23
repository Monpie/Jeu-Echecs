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
    //QLabel* testLbl = new QLabel(this);
    //testLbl->setPixmap(QPixmap("D:/Utilisateur/Documents/Ecole/ENSIBS-2/Semestre 3/C++/Projet/Jeu-Echecs/echiquier.jpg"));
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_newGameButton_clicked()
{
    ChessBoard board;
    this->hide();
    board.exec();
}

void MainMenu::on_loadGameButton_clicked()
{
    this->lectureFichierInitialisation();
    //this->ecritureFichierSauvegarde();
    //this->close();

}




void MainMenu::lectureFichierInitialisation(){
    using namespace std;

    //Variable
    char chessBoard[8][8];
    int cptLigne = 0;


    //QFile fichier("initialisation.txt");
    ifstream fichier(":/texte/initialisation.txt", ios::in);  // on ouvre le fichier en lecture
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

void MainMenu::ecritureFichierSauvegarde()
{
    using namespace std;
    ofstream fichier(":/texte/sauvegarde.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
            if(fichier)

            {

                    string nom = "Xav57";

                    int age = 60;

                    fichier << "Date de naissance : " << 24 << '/' << 3 << '/' << 1988 << endl;

                    fichier << "Bonjour, " << nom << ". Vous avez " << age << " ans.";



                    fichier.close();

            }

            else
                    cerr << "Impossible d'ouvrir le fichier !" << endl;
}
