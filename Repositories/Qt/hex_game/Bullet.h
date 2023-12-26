#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    QTimer * timer;
public:
    Bullet();
    QTimer * getTimer();
public slots:
    void move();
};

#endif // BULLET_H
