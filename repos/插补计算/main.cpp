#include "widget.h"

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Widget w;
    w.setFixedSize(600,700);
    w.show();


    return a.exec();
}
