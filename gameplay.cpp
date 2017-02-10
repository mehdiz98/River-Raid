#include "gameplay.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>
#include "score.h"
#include "feul.h"
#include "feultank.h"
#include <QDebug>
#include <QObject>
#include "heli.h"
#include "ship.h"
#include "baloon.h"
#include "jet.h"
#include "form.h"

GamePlay::GamePlay() {
    // creat scene and set background
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage("map.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    // create the plain
    plane = new Plane();
    plane->setPos(400,570);
    plane->setFlag(QGraphicsItem::ItemIsFocusable);
    plane->setFocus();
    // add the player to the scene
    scene->addItem(plane);

    // create the score/Feul
    score = new Score();
    scene->addItem(score);
    feul = new Feul();
    feul->setPos(feul->x(),feul->y()+25);
    scene->addItem(feul);


    // enemis
    timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn_object()));
    timer->start(2000);


    FeulTank * feultank = new FeulTank();
    scene->addItem(feultank);
    show();
    return;
}

void GamePlay::gameover()
{
    timer->stop();
    feul->stop();
//    scene->clear();
    emit over();
    QGraphicsTextItem *over;
    over = new QGraphicsTextItem();

    over->setDefaultTextColor(Qt::red);
    over->setFont(QFont("times",16));
    over->setPlainText(QString("!!GAMEOVER!!\n   ur score:") + QString::number(score->getScore())); // Score: 0
    over->setPos(300,300);
    scene->addItem(over);

}

void GamePlay::spawn_object() {
    qDebug()<<"dfasf";
    // create an enemy
    int random_number = rand() % 15;

    // random creat an enemy or a feultank
    if (random_number < 3) {
        FeulTank * feultank = new FeulTank();
        connect(this,SIGNAL(over()),feultank,SLOT(stop()));
        scene->addItem(feultank);
        return;
    }
    else if (random_number < 7) {
        Heli * enemy = new Heli();
        connect(this,SIGNAL(over()),enemy,SLOT(stop()));
        scene->addItem(enemy);
        return;
    }

    else if (random_number < 12) {
        Ship * enemy = new Ship();
        connect(this,SIGNAL(over()),enemy,SLOT(stop()));
        scene->addItem(enemy);
        return;
    }
    else if (random_number < 14) {
        Baloon * enemy = new Baloon();
        connect(this,SIGNAL(over()),enemy,SLOT(stop()));
        scene->addItem(enemy);
        return;
    }
    else if (random_number == 14) {
        Jet * enemy = new Jet();
        connect(this,SIGNAL(over()),enemy,SLOT(stop()));
        scene->addItem(enemy);
        return;
    }
}
