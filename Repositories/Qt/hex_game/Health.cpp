#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));
}

void Health::decrease(int amount)
{
    health-=amount;
    setPlainText(QString("Health: ")+QString::number(health));
}

int Health::getHealth()
{
    return health;
}
