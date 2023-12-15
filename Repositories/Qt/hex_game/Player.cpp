#include "Player.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Game.h"

extern Game * game;

void Player::keyPressEvent(QKeyEvent *event)
{
    //QString key_info;
    switch (event->key()) {
    case Qt::Key_Left:
        if ((this->x() > 0)&&(game->getHealth()->getHealth()>0)) {
            setPos(x()-10, y());
        }
        //key_info = "Left";
        break;
    case Qt::Key_Right:
        if ((this->x()+this->sizeX() < 800)&&(game->getHealth()->getHealth()>0)){
            setPos(x()+10, y());
        }
        //key_info = "Right";
        break;
    case Qt::Key_Space:
        game->addBullet();
        //qDebug() << "Bullet was created!";
        break;
    /*default:
        //key_info = "Undefined";
        break;*/
    }
    //qDebug() << key_info << "button was pressed!";
}

void Player::loadPolygon()
{
    for (QPointF p : points) {
        p.setX(p.x()*scale);
        p.setY(p.y()*scale);
        polygon << p;
    }
}

QPolygonF Player::getPolygon()
{
    this->loadPolygon();
    return polygon;
}

double Player::sizeX()
{
    return points[3].x() * scale;
}

double Player::sizeY()
{
    return points[2].y() * scale;
}
