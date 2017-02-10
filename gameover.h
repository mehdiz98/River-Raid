#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = 0);
    ~GameOver();
    void setlcd(int t);

private:
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
