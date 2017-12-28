#ifndef X_SPIELFIGUR_H
#define X_SPIELFIGUR_H

#include "spielfigur.h"

class X_Spielfigur : public Spielfigur
{
public:
    X_Spielfigur( const QString &spielFigurZeichen );
    virtual ~X_Spielfigur() override;

    const QString& getSpielFigurZeichen() const override;
};

#endif // X_SPIELFIGUR_H
