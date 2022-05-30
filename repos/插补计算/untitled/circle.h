#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QMessageBox>
#include <QtMath>
#

class Circle : public QObject
{
    Q_OBJECT
public:
    Circle(int xs,int ys,int xe,int ye,int r);


signals:

public:
    int xs{0},ys{100};
    int xe{100},ye{100};
    int radius{50};
    double xc{0.0},yc{0.0};
    bool isCircle{1};

};

#endif // CIRCLE_H
