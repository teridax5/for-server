#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <QMessageBox>
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Health.h"
#include "Bullet.h"

class Game : public QObject
{
    Q_OBJECT
    QGraphicsScene * scene;
    Player * player;
    QGraphicsView * view;
    QTimer * timer;
    Score * score;
    Health * health;
    QList<Enemy *> enemies;
    QList<Bullet *> bullets;
    QMessageBox * msgBox;
public:
    void new_game();
    Score * getScore();
    Health * getHealth();
    QList<Enemy *> getEnemies();
    void game_over();
    void addBullet();
    void removeEnemy(Enemy * enemy);
    void removeBullet(Bullet * bullet);
public slots:
    void spawn();
};

#endif // GAME_H
