#include "welcome.h"
#include "fivechess.h"
#include "chessboard.h"
#include "ui_welcome.h"
#include <QPaintEvent>
#include <QPainter>
#include "showus.h"
#include <QMovie>
#include "qmovie.h"
welcome::welcome(QWidget *parent) :
    QMainWindow(parent), 
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    setFixedSize(800,500);
    music = new QMediaPlayer;
    soundList = new QMediaPlaylist;
    soundList->addMedia(QMediaContent(QUrl("qrc:/sound/start.mp3")));   //声音在这里修改！！！！！！！！！！！！！！
    soundList->addMedia(QMediaContent(QUrl("qrc:/sound/playingbgm.mp3")));
    soundList->addMedia(QMediaContent(QUrl("qrc:/sound/clock.mp3")));    //声音在这里修改！！！！！！！！！
    soundList->addMedia(QMediaContent(QUrl("qrc:/sound/victory.mp3")));
     soundList->addMedia(QMediaContent(QUrl("qrc:/sound/gamestart.mp3")));
     //soundList->addMedia(QMediaContent(QUrl("qrc:/sound/defeated.mp3")));
    soundList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    music->setPlaylist(soundList);

   // ui->moving->setScaledContents(ture);
    QMovie * movie = new QMovie(":/images/wel.gif");
    ui->moving->setMovie(movie);
    movie->start();

}

void welcome::paintEvent(QPaintEvent *) //给界面插入图片
{
    QPainter painter(this);
    QPixmap backGroundPic(QString(":/images/beijing.png"));
    QPen pen;
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawPixmap(0,0,this->width(),this->height(),backGroundPic);
    painter.drawRect(0,0,this->width()-1,this->height()-1);
    QPixmap playerPhoto(QString(":/images/happydog.png"));
    QPixmap computerPhoto(QString(":/images/AI.png"));
    QPixmap titlePhoto(QString(":/images/title2.jpg"));
    QPixmap winPic(QString(":/images/winner.png"));
    QPixmap failPic(QString(":/images/lose.png"));
    ui->happy->setScaledContents(true);
    ui->happy->setPixmap(playerPhoto);


}


welcome::~welcome()
{
    delete ui;
    delete soundList;
    delete music;
}

void welcome::on_game_clicked() //跳转至游戏界面
{
    FiveChess *w = new FiveChess();
    soundList->setCurrentIndex(0);
    music->play();
    // w->running();
       w->init();
       w->show();
       this->hide();

}

void welcome::on_guize_clicked() //跳转至规则界面
{
    guize * gu = new guize;
    gu->show();
}



void welcome::on_us_clicked()
{
    showus *x =new showus();
    x->show();
}

void welcome::on_pushButton_clicked()
{
    showus *x =new showus();
    x->show();
}
