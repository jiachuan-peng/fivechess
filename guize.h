#ifndef GUIZE_H
#define GUIZE_H

#include <QMainWindow>

namespace Ui {
class guize;
}

class guize : public QMainWindow
{
    Q_OBJECT

public:
    explicit guize(QWidget *parent = nullptr);
    ~guize(); 

private:
    Ui::guize *ui;
};

#endif // GUIZE_H
