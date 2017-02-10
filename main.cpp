#include "mainwindow.h"
#include <QApplication>
#include <stdlib.h>
#include <time.h>
#include "gameplay.h"
#include <QDebug>


GamePlay * game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand (time(NULL));
    game = new GamePlay();
    game -> show();
    return a.exec();
}
