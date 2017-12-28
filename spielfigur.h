#ifndef SPIELFIGUR_H
#define SPIELFIGUR_H

#include <QString>

class Spielfigur
{
public:
    virtual const QString& getSpielFigurZeichen() const = 0;

protected:
    const QString spielFigurZeichen;

    Spielfigur( const QString &spielFigurZeichen );
    virtual ~Spielfigur();
};

#endif // SPIELFIGUR_H
