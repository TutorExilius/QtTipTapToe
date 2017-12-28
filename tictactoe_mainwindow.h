#ifndef TICTACTOE_MAINWINDOW_H
#define TICTACTOE_MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>

#include "frame_spielfeld.h"
#include "spielfigur.h"

namespace Ui
{
    class TicTacToe_MainWindow;
}

class TicTacToe_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    struct Position
    {
        Position( const int &x = -1, const int &y = -1 )
        : x{ x }
        , y{ y }
        {
        }

        int x;
        int y;
    };

    explicit TicTacToe_MainWindow(
            const QVector<Spielfigur*> &spielfiguren,
            QWidget *parent = nullptr );

    ~TicTacToe_MainWindow();

    void addButton( QPushButton *button, uint x, uint y );
    void moveTo( const uint &x, const uint &y );
    void computerMove();
    int nextBlockPosition( const uint &aktuellerSpielerIndex ) const;

private:
    uint getFieldIndex( const uint &x, const uint &y ) const;
    Position getFieldCoordinate( const uint &index ) const;
    void checkWinner();

    Ui::TicTacToe_MainWindow *ui;

    Frame_Spielfeld *spielfeld;

    uint nextSpielerIndex;
    QVector<Spielfigur*> spielfiguren;
    QVector<QPushButton*> fieldButtons;

    uint placedCounter;
    bool hasWinner;
    bool gameFinished;
    bool computerFirst;
    bool versusComputer;
};

#endif // TICTACTOE_MAINWINDOW_H
