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
    int xs{50},ys{100};
    int xe{100},ye{50};
    int radius{50};
    int xc{0},yc{0};
    int step{1};
};

#endif // CIRCLE_H
