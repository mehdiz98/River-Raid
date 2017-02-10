#ifndef ROCKET_H
#define ROCKET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
//#include <QMediaPlayer>
#include "missle.h"
#include "gameobjects.h"

class Plane:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Plane();
    void keyPressEvent(QKeyEvent * event);
    bool flag;
private:

signals:
    void over();
};

#endif // ROCKET_H
