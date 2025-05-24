#ifndef SHOWUS_H
#define SHOWUS_H

#include <QMainWindow>
#include "arcpaint.h"
#include <QMediaPlayer>
#include <QMediaPlaylist> 

namespace Ui {
class showus;
}

class showus : public QMainWindow
{
    Q_OBJECT

public:
    explicit showus(QWidget *parent = nullptr);
    ~showus();
protected:
     void paintEvent(QPaintEvent *);
private:
    Ui::showus *ui;
};

#endif // SHOWUS_H
