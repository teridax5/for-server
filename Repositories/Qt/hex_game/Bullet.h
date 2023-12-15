#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Bullet : public QObject, public QGraphicsRectItem {
    Q_OBJECT
    QTimer * timer;
public:
    Bullet();
    QTimer * getTimer();
public slots:
    void move();
};

#endif // BULLET_H
