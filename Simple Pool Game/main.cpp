#include "QtGame.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtGame w;
    w.show();
    return a.exec();


}
