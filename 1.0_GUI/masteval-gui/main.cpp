#include "mastevalgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mastevalGUI w;
    w.show();

    return a.exec();
}
