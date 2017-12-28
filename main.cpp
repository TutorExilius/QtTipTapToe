#include "tictactoe_mainwindow.h"

#include <QApplication>

#include "spielfigur.h"
#include "o_spielfigur.h"
#include "x_spielfigur.h"

int main( int argc, char *argv[] )
{
    QApplication a(argc, argv);

    QVector<Spielfigur*> spieler {
        new X_Spielfigur{ "X" },
        new O_Spielfigur{ "O" },

    };

    TicTacToe_MainWindow w( spieler );
    w.show();

    return a.exec();
}
