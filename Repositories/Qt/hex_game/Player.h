#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>

class Player : public QGraphicsPolygonItem {
public:
    void keyPressEvent(QKeyEvent * event);
    void loadPolygon();
    QPolygonF getPolygon();
    double sizeX();
    double sizeY();
private:
    double scale = 3;
    const QPointF points[6] = {
        QPointF(0, 0),
        QPointF(0, 20),
        QPointF(20, 30),
        QPointF(40, 20),
        QPointF(40, 0),
        QPointF(20, -10)
    };
    QPolygonF polygon;
};

#endif // PLAYER_H
