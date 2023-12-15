#include "Bullet.h"
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "Enemy.h"
#include "Game.h"

extern Game * game;

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

QTimer *Bullet::getTimer()
{
    return timer;
}

void Bullet::move()
{
    QList<Enemy *> all_enemies = game->getEnemies();
    for (int i=0, n=all_enemies.size(); i<n; i++) {
        if (this->collidesWithItem(all_enemies[i])) {
            game->getScore()->increase(all_enemies[i]->getCost());
            game->removeEnemy(all_enemies[i]);
            game->removeBullet(this);
            return;
        }
    }

    setPos(x(), y()-10);
    if (pos().y() + rect().height() < 0) {
        game->removeBullet(this);
    }
}
