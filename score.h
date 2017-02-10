#ifndef SCORE_H
#define SCORE_H


#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score();
    void increase(int value);
    unsigned int getScore();
private:
    unsigned int score;
};


#endif // SCORE_H
