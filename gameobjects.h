#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class GameObjects: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
protected:
    QTimer *timer;
public:
    GameObjects();
//    virtual void smash(QList<QGraphicsItem *> colliding_items) = 0;

    //~GameObjects();
public slots:
    void stop();
    virtual void move() = 0;
};

#endif // GAMEOBJECTS_H
