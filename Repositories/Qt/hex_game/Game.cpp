#include "Game.h"
#include <QDebug>
#include <QPushButton>

void Game::new_game() {
    // create scene for game
    scene = new QGraphicsScene();

    // create rectangle, resize it and add to the scene
    player = new Player();
    scene->addItem(player);

    // make focus flag on rectangle
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create view for scene and show it
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    scene->setBackgroundBrush(QImage(":/images/background.png"));
    player->setPos((view->width()-player->sizeX())/2, view->height() - player->sizeY());

    score_rect = new QGraphicsRectItem();
    score_rect->setPos(0, 0);
    score_rect->setBrush(Qt::white);
    score_rect->setRect(0, 0, 200, 100);
    scene->addItem(score_rect);

    score = new Score();
    scene->addItem(score);

    health = new Health;
    scene->addItem(health);
    health->setPos(health->x(), health->y()+30);

    enemies = {};
    bullets = {};

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(2000);
}

void Game::game_over() {
    for (Enemy * enemy: enemies){
        enemy->getTimer()->stop();
    }
    for (Bullet * bullet: bullets){
        bullet->getTimer()->stop();
    }
    delete score;
    delete health;
    delete score_rect;
    timer->stop();
    msgBox = new QMessageBox();
    msgBox->setText("Continue?");
    QPushButton *acceptButton = new QPushButton();
    QPushButton *rejectButton = new QPushButton();
    acceptButton->setText("Try again");
    rejectButton->setText("Exit");
    msgBox->addButton(acceptButton, QMessageBox::AcceptRole);
    msgBox->addButton(rejectButton, QMessageBox::RejectRole);
    int ret = msgBox->exec();
    delete view;
    delete scene;
    switch (ret) {
    case 0:
        this->new_game();
        break;
    case 1:
        break;
    default:
        break;
    }
}

void Game::addBullet()
{
    if (this->getHealth()->getHealth() > 0) {
        Bullet * new_bullet = new Bullet();
        bullets.append(new_bullet);
        new_bullet->setPos(player->x()+(player->sizeX()-new_bullet->pixmap().width())/2, player->y());
        scene->addItem(new_bullet);
    }
}

void Game::removeEnemy(Enemy *enemy)
{
    scene->removeItem(enemy);
    enemies.removeOne(enemy);
    delete enemy;
}

void Game::removeBullet(Bullet *bullet)
{
    scene->removeItem(bullet);
    bullets.removeOne(bullet);
    delete bullet;
}

Score * Game::getScore()
{
    return score;
}

Health * Game::getHealth()
{
    return health;
}

QList<Enemy *> Game::getEnemies()
{
    return enemies;
}

void Game::spawn()
{
    if (this->getHealth()->getHealth() > 0) {
        Enemy * new_enemy = new Enemy();
        enemies.append(new_enemy);
        scene->addItem(new_enemy);
    }
}
