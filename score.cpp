#include "score.h"
#include <QFont>

Score::Score(){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase(int value){
    score+= value;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

unsigned int Score::getScore(){
    return score;
}
