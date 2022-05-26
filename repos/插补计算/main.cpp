#include "widget.h"

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Widget w;
    w.setFixedSize(700,600);
    w.show();


    return a.exec();
}
