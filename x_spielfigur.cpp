#include "x_spielfigur.h"

X_Spielfigur::X_Spielfigur( const QString &spielFigurZeichen )
: Spielfigur{ spielFigurZeichen }
{

}

X_Spielfigur::~X_Spielfigur()
{

}

const QString& X_Spielfigur::getSpielFigurZeichen() const
{
    return this->spielFigurZeichen;
}
