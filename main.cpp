#include "QtQtimer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtQtimer w;
    w.show();
    return a.exec();
}
