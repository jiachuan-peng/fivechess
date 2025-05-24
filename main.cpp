#include "fivechess.h"
#include "chessboard.h"
#include "welcome.h"
#include "guize.h"

#include <QApplication>

int main(int argc, char *argv[])
{   //FiveChess *w = new FiveChess();
    QApplication a(argc, argv);
   welcome *n = new welcome();
 //  FiveChess *w = new FiveChess();
   // w->running();
     // w->init();
      n->show();
    //w->startGame();

    return a.exec();
}
