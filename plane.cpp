#include "plane.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "missle.h"
#include "enemy.h"


Plane::Plane(){
    flag = false;
    setPixmap(QPixmap("Player.png"));
}

void Plane::keyPressEvent(QKeyEvent *event){
    // move the Plane left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 170)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() < 600)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        if(flag)return;
        flag = true;
        Missle * missle = new Missle();
        missle->setPos(x()-85,y());
        scene()->addItem(missle);
    }


}
