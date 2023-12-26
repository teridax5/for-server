#ifndef HEALTH_H
#define HEALTH_H
#include "QGraphicsTextItem"

class Health : public QGraphicsTextItem {
    int health;
public:
    Health(QGraphicsItem * parent=0);
    void decrease(int amount);
    int getHealth();
};

#endif // HEALTH_H
