#include "tictactoe_mainwindow.h"
#include "ui_tictactoe_mainwindow.h"

#include <QDebug>
#include <QMessageBox>

TicTacToe_MainWindow::TicTacToe_MainWindow(
        const QVector<Spielfigur*> &spielfiguren,
        QWidget *parent )
: QMainWindow{ parent }
, spielfeld{ nullptr }
, ui{ new Ui::TicTacToe_MainWindow }
, nextSpielerIndex{ 0 }
, placedCounter{ 0 }
, hasWinner{ false }
, gameFinished{ false }
, computerFirst{ true }
, versusComputer{ false }
{
    qDebug() << "Anzahl der Spieler: " << spielfiguren.size();

    ui->setupUi(this);

    this->fieldButtons.resize( Frame_Spielfeld::ANZAHL_FELDER );

    this->spielfeld = new Frame_Spielfeld( this );

    for( auto &spielfigur : spielfiguren )
    {
        this->spielfiguren.push_back( spielfigur );
    }

    this->setFixedSize( this->spielfeld->size() );

    if( this->versusComputer &&
        this->computerFirst )
    {
        this->computerMove();
    }
}

TicTacToe_MainWindow::~TicTacToe_MainWindow()
{
    delete ui;
}

uint TicTacToe_MainWindow::getFieldIndex( const uint &x, const uint &y ) const
{
    const uint anzahlFelderProReihe = 3;
    return ((x-1) * anzahlFelderProReihe + y) - 1;
}

void TicTacToe_MainWindow::addButton( QPushButton *button, uint x, uint y )
{
    const uint index = this->getFieldIndex( x, y );

    this->fieldButtons[index] = button;
}

void TicTacToe_MainWindow::moveTo( const uint  &x, const uint  &y )
{
    if( !this->hasWinner && !this->gameFinished )
    {
        const int actualSpielerIndex = this->nextSpielerIndex;

qDebug() << "move to " << x << ":" << y;

        const uint index = this->getFieldIndex( x, y );

        const QString spielFigurZeichen = this->spielfiguren.at( this->nextSpielerIndex)->getSpielFigurZeichen();
qDebug() << "Spielfigur: " << spielFigurZeichen;

        if( this->fieldButtons.at(index)->text().isEmpty() )
        {
            this->fieldButtons.at(index)->setText( spielFigurZeichen );

qDebug() << "aktueller Spieler: " << this->nextSpielerIndex ;
            this->nextSpielerIndex = (nextSpielerIndex+1) % this->spielfiguren.size();
qDebug() << "nächster Spieler: " << this->nextSpielerIndex;

            ++this->placedCounter;

            this->checkWinner();
qDebug() << "placed counter " << this->placedCounter;
            if( this->placedCounter > 8 || this->hasWinner )
            {
                this->gameFinished = true;

                QString winnerText = "";

                if( this->hasWinner )
                {
                    winnerText = "\n\nGewonnen hat Spieler: "
                            + QString::number( actualSpielerIndex );
                }

                QMessageBox::information( this, "Finished",
                      "Das Spiel ist vorbei." + winnerText );
            }


            if( this->versusComputer )
            {
                if( !this->hasWinner &&
                    !this->gameFinished )
                {
                    int rest = 0;
                    if(this->computerFirst)
                    {
                        rest = 1;
                    }

                    if( this->placedCounter % 2 != rest )
                    {
                        this->computerMove();
                    }
                }
            }
        }
    }
}

void TicTacToe_MainWindow::checkWinner()
{
    const QString val_1_1 = this->fieldButtons.at( this->getFieldIndex( 1,1 ))->text();
    const QString val_1_2 = this->fieldButtons.at( this->getFieldIndex( 1,2 ))->text();
    const QString val_1_3 = this->fieldButtons.at( this->getFieldIndex( 1,3 ))->text();
    const QString val_2_1 = this->fieldButtons.at( this->getFieldIndex( 2,1 ))->text();
    const QString val_2_2 = this->fieldButtons.at( this->getFieldIndex( 2,2 ))->text();
    const QString val_2_3 = this->fieldButtons.at( this->getFieldIndex( 2,3 ))->text();
    const QString val_3_1 = this->fieldButtons.at( this->getFieldIndex( 3,1 ))->text();
    const QString val_3_2 = this->fieldButtons.at( this->getFieldIndex( 3,2 ))->text();
    const QString val_3_3 = this->fieldButtons.at( this->getFieldIndex( 3,3 ))->text();

    const QString styleSheet = "padding: 0px;\nmargin: 0px;\nborder: 1px solid black;\nbackground-color: gray;\nfont-size: 40pt;";

    if( !val_1_1.isEmpty() &&
        !val_1_2.isEmpty() &&
        !val_1_3.isEmpty() &&
        val_1_1 == val_1_2 && val_1_2 == val_1_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 1,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 1,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_2_1.isEmpty() &&
             !val_2_2.isEmpty() &&
             !val_2_3.isEmpty() &&
             val_2_1 == val_2_2 && val_2_2 == val_2_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 2,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_3_1.isEmpty() &&
             !val_3_2.isEmpty() &&
             !val_3_3.isEmpty() &&
             val_3_1 == val_3_2 && val_3_2 == val_3_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 3,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_1.isEmpty() &&
             !val_2_1.isEmpty() &&
             !val_3_1.isEmpty() &&
             val_1_1 == val_2_1 && val_2_1 == val_3_1 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,1 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,1 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_2.isEmpty() &&
             !val_2_2.isEmpty() &&
             !val_3_2.isEmpty() &&
             val_1_2 == val_2_2 && val_2_2 == val_3_2 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,2 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,2 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_3.isEmpty() &&
             !val_2_3.isEmpty() &&
             !val_3_3.isEmpty() &&
             val_1_3 == val_2_3 && val_2_3 == val_3_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,3 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,3 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_1.isEmpty() &&
             !val_2_2.isEmpty() &&
             !val_3_3.isEmpty() &&
             val_1_1 == val_2_2 && val_2_2 == val_3_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_3.isEmpty() &&
             !val_2_2.isEmpty() &&
             !val_3_1.isEmpty() &&
             val_1_3 == val_2_2 && val_2_2 == val_3_1 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,3 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,1 ))
                        ->setStyleSheet( styleSheet );
    }
}

void TicTacToe_MainWindow::computerMove()
{
    if( this->computerFirst )
    {
        if( this->fieldButtons.at( this->getFieldIndex( 2,2 ))->text().isEmpty() )
        {
            this->moveTo( 2, 2 );
        }
        else if( this->fieldButtons.at( this->getFieldIndex( 1,3 ))->text().isEmpty() )
        {
            this->moveTo( 1, 3 );
        }
        else if( this->fieldButtons.at( this->getFieldIndex( 2,3 ))->text().isEmpty() )
        {
            this->moveTo( 2, 3 );
        }
        else if( this->fieldButtons.at( this->getFieldIndex( 3,1 ))->text().isEmpty() )
        {
            this->moveTo( 3, 1 );
        }
        else if( this->fieldButtons.at( this->getFieldIndex( 3,3 ))->text().isEmpty() )
        {
            this->moveTo( 3, 3 );
        }
        else if( this->fieldButtons.at( this->getFieldIndex( 3,2 ))->text().isEmpty() )
        {
            this->moveTo( 3, 2 );
        }
        else if( this->fieldButtons.at( this->getFieldIndex( 1,2 ))->text().isEmpty() )
        {
            this->moveTo( 1, 2 );
        }
        else if( this->fieldButtons.at( this->getFieldIndex( 2,1 ))->text().isEmpty() )
        {
            this->moveTo( 2, 1 );
        }
        else if( this->fieldButtons.at( this->getFieldIndex( 1,1 ))->text().isEmpty() )
        {
            this->moveTo( 1, 1 );
        }

    }
}
