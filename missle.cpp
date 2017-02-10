#include "missle.h"
#include <QTimer>
#include "gameplay.h"
#include <QDebug>
#include "heli.h"
#include "ship.h"
#include "baloon.h"
#include "jet.h"
extern GamePlay * game;

Missle::Missle()
{
    // set the pic
    setPixmap(QPixmap("bullet.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    // make/connect a timer to move() the enemy every so often
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(15);
}

bool Missle::smash(QList<QGraphicsItem *> colliding_items)
{

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Heli)){
            // increase the score
            game->score->increase(60);
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);

            scene()->removeItem(this);
            game -> plane -> flag = false;

            // delete them from the heap to save memory
            qDebug()<<"dasdasddsf";
            delete colliding_items[i];
            delete timer;
            delete this;

            return true;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Ship)){
            // increase the score
            game->score->increase(30);
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            game -> plane -> flag = false;
            // delete them from the heap to save memory
            qDebug()<<"dasdasddsf";
            delete colliding_items[i];
            delete timer;
            delete this;

            return true;
        }else if (typeid(*(colliding_items[i])) == typeid(Baloon)){
            // increase the score
            game->score->increase(60);
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            game -> plane -> flag = false;

            // delete them from the heap to save memory
            qDebug()<<"dasdasddsf";
            delete colliding_items[i];
            delete timer;
            delete this;

            return true;
        }else if (typeid(*(colliding_items[i])) == typeid(Jet)){
            // increase the score
            game->score->increase(100);
            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            game -> plane -> flag = false;

            // delete them from the heap to save memory
            qDebug()<<"dasdasddsf";
            delete colliding_items[i];
            delete timer;
            delete this;

            return true;
        }
        else if(typeid(*(colliding_items[i])) == typeid(FeulTank)){
            // increase the score
            game->score->increase(150);

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            game -> plane -> flag = false;

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;
            return true;
        }
    }
    return false;
}

void Missle::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    // move down
    setPos(x(),y()-5);
    if(smash(colliding_items))return;
    qDebug()<<"dsf";

    // destroy when it goes out of the screen
    if (pos().y() < -100){
        // delete the object
        game -> plane -> flag = false;
        scene()->removeItem(this);
        delete this;
        return;
    }
}
