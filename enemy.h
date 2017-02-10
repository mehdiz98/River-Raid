#ifndef ENEMY_H
#define ENEMY_H
#include "gameobjects.h"
#include "plane.h"
#include <QTimer>

class Enemy: public GameObjects {
    Q_OBJECT

public:
    Enemy();
    bool smash(QList<QGraphicsItem *> colliding_items);
//    virtual int getvalue();
public slots:
    void move();
};

#endif // ENEMY_H
