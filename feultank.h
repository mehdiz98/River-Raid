#ifndef FEULTANK_H
#define FEULTANK_H

#include "gameobjects.h"

class FeulTank: public GameObjects{
private:
    bool flag;

public:
    FeulTank();
    void smash(QList<QGraphicsItem *> colliding_items);

public slots:
    void move();
};

#endif // FEULTANK_H
