#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "chessboard.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_newGameButton_clicked();
    void on_loadGameButton_clicked();
    void lectureFichierInitialisation();
    void ecritureFichierSauvegarde();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
