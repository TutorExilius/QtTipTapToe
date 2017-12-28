#ifndef O_SPIELFIGUR_H
#define O_SPIELFIGUR_H

#include "spielfigur.h"

class O_Spielfigur : public Spielfigur
{
public:
    O_Spielfigur( const QString &spielFigurZeichen );
    virtual ~O_Spielfigur() override;

    const QString& getSpielFigurZeichen() const override;
};

#endif // O_SPIELFIGUR_H
