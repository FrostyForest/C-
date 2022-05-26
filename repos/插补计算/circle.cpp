#include "circle.h"

Circle::Circle(int xs,int ys,int xe,int ye,int r,int step)

{
    Circle::xs=xs;
    Circle::ys=ys;
    Circle::xe=xe;
    Circle::ye=ye;
    Circle::radius=r;
    Circle::step=step;

    double c1=(xe*xe-xs*xs+ye*ye-ys*ys);
    double c2=(ye-ys)/(xe-xs);
    double A=1+c2*c2;
    double B=2*(xs-c1)*c2-2*ys;
    double C=xs*xs-2*xs*c1+c1*c1+ys*ys-radius*radius;
    yc= (-B+sqrt(B*B-4*A*C))/(2*A);
    xc=c1-c2*yc;

}
