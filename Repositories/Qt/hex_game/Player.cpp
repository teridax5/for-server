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
        if (bulletsound->state() == QMediaPlayer::PlayingState) {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState) {
            bulletsound->play();
        }
        //qDebug() << "Bullet was created!";
        break;
    /*default:
        //key_info = "Undefined";
        break;*/
    }
    //qDebug() << key_info << "button was pressed!";
}

double Player::sizeX()
{
    return this->pixmap().width();
}

double Player::sizeY()
{
    return this->pixmap().height();
}

Player::Player()
{
    setPixmap(QPixmap(":/images/player.png"));
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/beam.wav"));
}
