#include "guize.h"
#include "ui_guize.h"

guize::guize(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::guize)
{
    ui->setupUi(this);
}

guize::~guize()
{
    delete ui;
}
