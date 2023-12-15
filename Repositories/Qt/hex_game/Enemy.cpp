#include "Enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <stdlib.h>
#include "Player.h"
#include "Game.h"

extern Game * game;

Enemy::Enemy()
{
    int random_number = rand() % 700;
    setPos(random_number, 0);
    setRect(0, 0, 100, 100);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

int Enemy::getCost()
{
    return cost;
}

QTimer *Enemy::getTimer()
{
    return timer;
}

void Enemy::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n=colliding_items.size(); i<n; i++) {
        if (typeid(*(colliding_items[i])) ==  typeid(Player)) {
            game->getHealth()->decrease(1);
            switch (game->getHealth()->getHealth()) {
            case 0:
                game->game_over();
                return;
            }
            game->removeEnemy(this);
            return;
        }
    }

    setPos(x(), y()+5);
    if (pos().y() > 600) {
        game->removeEnemy(this);
    }
}
