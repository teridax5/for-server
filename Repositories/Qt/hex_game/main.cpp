#include <QApplication>
#include "Game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->new_game();

    return a.exec();
}
