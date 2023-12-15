#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Enemy : public QObject, public QGraphicsRectItem {
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
