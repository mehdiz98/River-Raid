#include "enemy.h"
#include "plane.h"
#include <QTimer>
#include "gameplay.h"
#include <typeinfo>
extern GamePlay * game;

Enemy::Enemy(){}

bool Enemy::smash(QList<QGraphicsItem *> colliding_items)
{
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Plane)){
            delete this;
            game->gameover();
            return true;
        }
    }
    return false;
}


void Enemy::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    // move down
    setPos(x(),y()+5);
    if(smash(colliding_items)) return;

    // destroy when it goes out of the screen
    if (pos().y() > 600){
        // delete the object

        scene()->removeItem(this);
        delete this;
    }
}
