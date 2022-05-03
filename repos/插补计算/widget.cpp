#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QIntValidator(1,100,this));
    ui->lineEdit_2->setValidator(new QIntValidator(0,500,this));
    ui->lineEdit_3->setValidator(new QIntValidator(0,500,this));
    ui->lineEdit_4->setValidator(new QIntValidator(0,500,this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,500,this));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::out_step(){
    QString a=ui->lineEdit->text();
    step=a.toInt();
    update();
}
void Widget::paintEvent(QPaintEvent *event){
   LineInterpolation(xs,ys,xe,ye,step);
   Circle a(250,500,500,250,250,10);
   QPainter painter(this);
   painter.drawLine(a.xc,a.yc,0,0);
   qDebug()<<a.xc;

}

void Widget::LineInterpolation(int x0,int y0,int x1,int y1,int step){
    int xs,ys;//起点
    int xe,ye;//终点
    int x_dirc;int y_dirc;
    xs=x0,ys=y0;//起点
    xe=x1,ye=y1;//终点

    if(xe>=xs){
        x_dirc=1;
    }
    else{
        x_dirc=-1;
    }
    if(ye>=ys){
        y_dirc=1;
    }
    else{
        y_dirc=-1;
    }
    QPainter painter(this);
    painter.setWindow(0,this->height(),this->width(),-(this->height()));
    int x=xs,y=ys;int i=0;
    int xb=xs,yb=ys;
    float k(fabs((float)(ye-ys)/(xe-xs)));
    painter.drawLine(xs,ys,xe,ye);
    while(qAbs(x-xs)<qAbs(xe-xs)||qAbs(y-ys)<qAbs(ye-ys)){
        if((y-(ys+qAbs(x-xs)*y_dirc*k))*y_dirc<0){
            y=y+step*y_dirc;
            painter.drawPoint(x,y);
            painter.drawLine(xb,yb,x,y);
            xb=x;yb=y;

        }
        else{
            x=x+step*x_dirc;
            painter.drawPoint(x,y);
            painter.drawLine(xb,yb,x,y);
            xb=x;yb=y;
            i++;
        }
    }
}



void Widget::on_lineEdit_2_editingFinished()
{
    QString a=ui->lineEdit_2->text();
    xs=a.toInt();
    update();
}
void Widget::on_lineEdit_3_editingFinished()
{
    QString a=ui->lineEdit_3->text();
    ys=a.toInt();
    update();
}
void Widget::on_lineEdit_4_editingFinished()
{
    QString a=ui->lineEdit_4->text();
    xe=a.toInt();
    update();
}
void Widget::on_lineEdit_5_editingFinished()
{
    QString a=ui->lineEdit_5->text();
    ye=a.toInt();
    update();
}

