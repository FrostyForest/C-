#include "circle.h"

Circle::Circle(int xs,int ys,int xe,int ye,int r)

{
    Circle::xs=xs;
    Circle::ys=ys;
    Circle::xe=xe;
    Circle::ye=ye;
    Circle::radius=r;

    if(xe!=xs){
        double c1=(xe*xe-xs*xs+ye*ye-ys*ys)/(2*(xe-xs));
        double c2=((double)(ye-ys))/((double)(xe-xs));
        double A=1+c2*c2;
        double B=2*(xs-c1)*c2-2*ys;
        double C=xs*xs-2*xs*c1+c1*c1+ys*ys-radius*radius;
        if(B*B-4*A*C<0){//判断是否为圆
            isCircle=0;
        }
        else{
            yc=(-B-sqrt(B*B-4*A*C))/(2*A);
            xc=c1-c2*yc;
        }
    }
    else{

        double d1=qPow(r,2);
        double d2=qPow(((double)(ys-ye))/2,2);
        if(d1>d2){
        xc=xe+qPow(d1-d2,0.5);
        yc=((double)(ys+ye))/2;
        }
        else{
            isCircle=0;
        }
    }

}


