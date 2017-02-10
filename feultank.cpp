#include "feultank.h"
#include "plane.h"
#include <QTimer>
#include "gameplay.h"
#include <typeinfo>
extern GamePlay * game;

FeulTank::FeulTank()
{
    // empty or full
    flag = 1;
    // set the pic
    setPixmap(QPixmap("FeulTank.png"));
    setTransformOriginPoint(50,50);


    // make/connect a timer to move() the enemy every so often
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);

}

void FeulTank::smash(QList<QGraphicsItem *> colliding_items)
{
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Plane) && flag){
            game -> feul -> increase();
            flag = 0;
            return;
        }
    }
}

void FeulTank::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    // move down
    setPos(x(),y()+5);
    smash(colliding_items);

    // destroy when it goes out of the screen
    if (pos().y() > 600){
        // delete the object

        scene()->removeItem(this);
        delete this;
    }
}
