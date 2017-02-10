#ifndef FEUL_H
#define FEUL_H
#include <QGraphicsTextItem>
#include <QTimer>
class Feul : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Feul();
    void increase();
    int getFeul();
    void stop();
private:
    int feul;
    QTimer * timer;
public slots:
    void decrease();
};

#endif // FEUL_H
