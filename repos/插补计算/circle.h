#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>

class Circle : public QObject
{
    Q_OBJECT
public:
    explicit Circle(int xs,int ys,int xe,int ye,int r,int step);

signals:

public:
    int xs{0},ys{0};
    int xe{0},ye{0};
    int radius{0};
    int xc{0},yc{0};
    int step{1};
};

#endif // CIRCLE_H
