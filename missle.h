#ifndef MISSLE_H
#define MISSLE_H
#include "gameobjects.h"
#include "enemy.h"
#include "feultank.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
class Missle: public GameObjects
{
public:
    Missle();
    bool smash(QList<QGraphicsItem *> colliding_items);

public slots:
    void move();
};

#endif // MISSLE_H
