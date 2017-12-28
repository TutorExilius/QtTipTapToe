#ifndef FRAME_SPIELFELD_H
#define FRAME_SPIELFELD_H

#include <QFrame>

namespace Ui {
class Frame_Spielfeld;
}

class Frame_Spielfeld : public QFrame
{
    Q_OBJECT

public:
    static const uint ANZAHL_FELDER = 9;

    explicit Frame_Spielfeld(QWidget *parent = 0);
    ~Frame_Spielfeld();

private:
    Ui::Frame_Spielfeld *ui;
};

#endif // FRAME_SPIELFELD_H
