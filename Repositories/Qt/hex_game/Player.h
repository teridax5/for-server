#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Player : public QGraphicsPixmapItem {
    QMediaPlayer * bulletsound;
public:
    void keyPressEvent(QKeyEvent * event);
    void loadPolygon();
    double sizeX();
    double sizeY();
    Player();
};

#endif // PLAYER_H
