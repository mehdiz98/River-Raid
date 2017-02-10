#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "plane.h"
#include "enemy.h"
#include "missle.h"
#include "feul.h"
#include "score.h"
#include <typeinfo>
#include <QList>
#include "form.h"


class GamePlay:public QGraphicsView
{
    Q_OBJECT
private:
    QTimer * timer;
    Form finish;
    QList <GameObjects *> objects;
public:
    GamePlay();

    QGraphicsScene * scene;
    Plane * plane;
    Score * score;
    Feul * feul;

    void gameover();

  //  ~GamePlay();
public slots:
    void spawn_object();
signals:
    void over();
};

#endif // GAMEPLAY_H
