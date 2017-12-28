#include "frame_spielfeld.h"
#include "ui_frame_spielfeld.h"

#include "tictactoe_mainwindow.h"

#include <QDebug>

Frame_Spielfeld::Frame_Spielfeld( QWidget *parent )
: QFrame{ parent }
, ui{ new Ui::Frame_Spielfeld }
{
    this->ui->setupUi( this );

    TicTacToe_MainWindow *parentWindow =
            dynamic_cast<TicTacToe_MainWindow *>( this->parent() );

    if( parentWindow == nullptr )
    {
        qDebug() << "parent ist nicht das wofür du es hälst";
    }

    this->ui->pushButton_1_1->setText( "" );
    QObject::connect( this->ui->pushButton_1_1,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 1,1 );
    });
    parentWindow->addButton( this->ui->pushButton_1_1, 1, 1 );

    this->ui->pushButton_1_2->setText( "" );
    QObject::connect( this->ui->pushButton_1_2,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 1,2 );
    });
    parentWindow->addButton( this->ui->pushButton_1_2, 1, 2 );

    this->ui->pushButton_1_3->setText( "" );
    QObject::connect( this->ui->pushButton_1_3,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 1,3 );
    });
    parentWindow->addButton( this->ui->pushButton_1_3, 1, 3 );

    this->ui->pushButton_2_1->setText( "" );
    QObject::connect( this->ui->pushButton_2_1,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 2,1 );
    });
    parentWindow->addButton( this->ui->pushButton_2_1, 2, 1 );

    this->ui->pushButton_2_2->setText( "" );
    QObject::connect( this->ui->pushButton_2_2,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 2,2 );
    });
    parentWindow->addButton( this->ui->pushButton_2_2, 2, 2 );

    this->ui->pushButton_2_3->setText( "" );
    QObject::connect( this->ui->pushButton_2_3,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 2,3 );
    });
    parentWindow->addButton( this->ui->pushButton_2_3, 2, 3 );

    this->ui->pushButton_3_1->setText( "" );
    QObject::connect( this->ui->pushButton_3_1,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 3,1 );
    });
    parentWindow->addButton( this->ui->pushButton_3_1, 3, 1 );

    this->ui->pushButton_3_2->setText( "" );
    QObject::connect( this->ui->pushButton_3_2,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 3,2 );
    });
    parentWindow->addButton( this->ui->pushButton_3_2, 3, 2 );

    this->ui->pushButton_3_3->setText( "" );
    QObject::connect( this->ui->pushButton_3_3,
                &QPushButton::clicked,
                [=](){ parentWindow->moveTo( 3,3 );
    });
    parentWindow->addButton( this->ui->pushButton_3_3, 3, 3 );
}

Frame_Spielfeld::~Frame_Spielfeld()
{
    delete ui;
}
