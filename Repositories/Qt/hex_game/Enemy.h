#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    int cost = 30;
    QTimer * timer;
public:
    Enemy();
    int getCost();
    QTimer * getTimer();
public slots:
    void move();
};
#endif // ENEMY_H
