#include "bzmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BzMainWindow w;
    w.show();

    return a.exec();
}
