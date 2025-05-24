#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>
#include "fivechess.h"
#include "chessboard.h"
#include "arcpaint.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "showus.h"
namespace Ui {
class welcome;
}

class welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();
protected:
     void paintEvent(QPaintEvent *);
private slots:
  //  void on_pushButton_2_clicked();

    //void on_pushButton_clicked();

    void on_game_clicked();

    void on_guize_clicked();

    void on_us_clicked();

    void on_pushButton_clicked();

private:
    Ui::welcome *ui;
    QMediaPlayer * music;
    QMediaPlaylist * soundList;
};

#endif // WELCOME_H
