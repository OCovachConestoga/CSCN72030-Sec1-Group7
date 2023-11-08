#include "JurassicSCADA.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JurassicSCADA w;
    w.show();
    return a.exec();
}
