#include "showus.h"
#include "ui_showus.h"
#include "welcome.h"
#include "fivechess.h"
#include "chessboard.h"
#include "ui_welcome.h"

showus::showus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showus)
{
    ui->setupUi(this); 
}
void showus::paintEvent(QPaintEvent *) //给界面插入图片
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
//    ui->happy->setScaledContents(true);
//    ui->happy->setPixmap(playerPhoto);


}
showus::~showus()
{
    delete ui;
}
