#include "baloon.h"
#include <QTimer>

Baloon::Baloon()
{
    setPixmap(QPixmap("baloon.png"));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move() the enemy every so often
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}
