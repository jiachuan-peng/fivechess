#ifndef FIVECHESS_H
#define FIVECHESS_H

#include <QWidget>
#include <QStyle>
#include <QThread>
#include <QTime>
#include "chessboard.h"
#include "arcpaint.h"
#include "exitshow.h"
#include "guize.h"
#include "welcome.h"
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <queue>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class FiveChess; }
QT_END_NAMESPACE

class FiveChess : public QWidget
{
    Q_OBJECT
public:
    struct DropPointInfo {
        //[15:12]:4
        //[11:8]:3
        //[7:4]:4h
        //[3:0]:3h
        short blackFlags;
        short whiteFlags;
    };
enum CurrentRound {computer, player};
enum RunState {NO_RUNNING, START, RUNNING, GAME_OVER,RESTART,EXIT};
public:
    FiveChess(QWidget *parent = nullptr);
    ~FiveChess();
  QVector <DropPointInfo> v; //创建vector
  QVector <DropPointInfo>::iterator beginin = v.begin();
  QVector <DropPointInfo>::iterator endit = v.end();
  void  review();
    //下棋时候
    void startGame();//游戏开始
    void init();
    void running();//游戏运行
    void reStartGame();//游戏重开
protected:
    void paintEvent(QPaintEvent *);//绘制棋盘
    void mousePressEvent(QMouseEvent *e);//鼠标点击
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void updateComputerStep(int num);
    void updatePlayerStep(int num);
private slots:
    void on_startBtn_clicked();
    void on_reStartBtn_clicked();
    void GameOver();
    void GameOverPrompt(CurrentRound win);
    void playerDropPos(int x, int y);  // 接收玩家落子位域下标
    // timeLine
    void updateFrame(int frame);
    void timeValueChanged(qreal value);
    void timefinished();
    void on_reDropBtn_clicked();
    void on_exitBtn_clicked();
    void on_pushButton_clicked();

private:
    bool computerDropAI(); // 电脑下棋，返回下棋结果（是否）
    bool computerDropAI2();//判断是否胜利
    DropPointInfo dropOneInfo(int x, int y);
    char dropInfoOneLinePartValue(ChessBoard::ChessType type,int polarityX, int polarityY, int x, int y);
    short dropInfoOneLinePart(ChessBoard::ChessType type,int polarityX1, int polarityY1, int polarityX2, int polarityY2,int x, int y);//检测权重
    bool isDropAIOver(int x, int y);//电脑下子
    bool checkPointInfo(ChessBoard::ChessType type, char info1, int part1, char info2, int part2);//检测阈值
    void pregressPrompt();
    void myMSleep(unsigned int msec);
    bool findone(ChessBoard::ChessType type,int x,int y);
    bool findlineone(ChessBoard::ChessType type,int polarityX, int polarityY, int x, int y);

    bool gameOverFlag;
    bool gameOverPromptFlag;
    int computerStep;
    int playerStep;
    // 电脑下棋点
    int computerDropingX;
    int computerDropingY;
    bool computerdropedFlag;
    // 悔棋相关信息
    int lastChessX;
    int lastChessY;
    bool reDropenable;
    bool startLoop;
    bool runningFlag;
    RunState state;

    QPoint lastPos;

    Ui::FiveChess *ui;

    ChessBoard *chessboard;
    ArcPaint * progressStepPrompt;
    ChessBoard::ChessType computerChess;
    ChessBoard::ChessType playerChess;
    CurrentRound currentRound;
    CurrentRound winner;

    QLabel * resultLabel;
    QTimeLine * timeLine;
    QMediaPlayer * music;
    QMediaPlaylist * soundList;
    DropPointInfo dropPointInfo[CHEQUER_NUM][CHEQUER_NUM];

};
#endif // FIVECHESS_H
