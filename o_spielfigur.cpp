#include "o_spielfigur.h"

O_Spielfigur::O_Spielfigur( const QString &spielFigurZeichen )
: Spielfigur{ spielFigurZeichen }
{

}

O_Spielfigur::~O_Spielfigur()
{

}

const QString& O_Spielfigur::getSpielFigurZeichen() const
{
    return this->spielFigurZeichen;
}
