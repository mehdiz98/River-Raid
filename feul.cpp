#include "feul.h"
#include <QFont>
#include <QTimer>
#include "gameplay.h"
extern GamePlay * game;
Feul::Feul()
{
    feul = 100;
    setPlainText(QString("FEUL: ") + QString::number(feul) + "%");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

    // make/connect a timer to move() the enemy every so often
    timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);
    connect(timer,SIGNAL(timeout()),this,SLOT(decrease()));

    // start the timer
    timer->start(300);
}

void Feul::increase()
{
    feul+= 33;
    feul = feul > 100 ? 100 : feul;
    setPlainText(QString("FEUL: ") + QString::number(feul) + "%");
}

int Feul::getFeul()
{
    return feul;
}

void Feul::stop()
{
    timer->stop();
}

void Feul::decrease()
{
    feul--;
    if(feul < 0){
        game -> gameover();
        return;
    }
    setPlainText(QString("FEUL: ") + QString::number(feul) + "%");
}
