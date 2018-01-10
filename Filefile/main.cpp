#include "Filefile.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Filefile w;
    w.show();
    return a.exec();
}
