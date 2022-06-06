#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QIntValidator(0,1000,this));//步长范围控制
    ui->lineEdit_2->setValidator(new QIntValidator(0,1000,this));//坐标范围控制
    ui->lineEdit_3->setValidator(new QIntValidator(0,1000,this));
    ui->lineEdit_4->setValidator(new QIntValidator(0,1000,this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,1000,this));
    ui->lineEdit_6->setValidator(new QIntValidator(0,1000,this));//半径输入控制

}

Widget::~Widget()
{
    delete ui;
}

void Widget::out_step(){//更新步长
    QString a=ui->lineEdit->text();
    step=a.toInt();
    if(step>100||step<1){
        ui->lineEdit->clear();
        QMessageBox::warning(this,QString::fromLocal8Bit("步长输入错误"),QString::fromLocal8Bit("请输入1~100内的整数"),QMessageBox::Ok);
    }
    //update();
}
void Widget::paintEvent(QPaintEvent *event){

   QPainter painter(this);
   painter.setWindow(0,this->height(),this->width(),-(this->height()));//重新设置坐标系
   paintExis();
   if(ui->radioButton->isChecked()==1&&switcher==1){//直线插补
       LineInterpolation(xs,ys,xe,ye,step);
   }

   if(ui->radioButton_3->isChecked()==1&&switcher==1&&isCircle==1){//顺时针插补
       ArcInterpolationClockwise(xs,ys,xe,ye,r,xc,yc,step);
   }

   if(ui->radioButton_4->isChecked()==1&&switcher==1&&isCircle==1){//逆时针插补
       ArcInterpolationCounterclock(xs,ys,xe,ye,r,xc,yc,step);
   }

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
    painter.setWindow(0,this->height(),this->width(),-(this->height()));//重新设置坐标系
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



void Widget::on_lineEdit_2_editingFinished()//输入转换并更新参数
{
    QString a=ui->lineEdit_2->text();
    xs=a.toInt();
    if(xs>500){
        ui->lineEdit_2->clear();
        QMessageBox::warning(this,QString::fromLocal8Bit("坐标输入错误"),QString::fromLocal8Bit("请输入0~500内的整数"),QMessageBox::Ok);
        xs=0;
    }
    //update();
}
void Widget::on_lineEdit_3_editingFinished()
{
    QString a=ui->lineEdit_3->text();
    ys=a.toInt();
    if(ys>500){
        ui->lineEdit_3->clear();
        QMessageBox::warning(this,QString::fromLocal8Bit("坐标输入错误"),QString::fromLocal8Bit("请输入0~500内的整数"),QMessageBox::Ok);
    }
    //update();
}
void Widget::on_lineEdit_4_editingFinished()
{
    QString a=ui->lineEdit_4->text();
    xe=a.toInt();
    if(xe>500){
        ui->lineEdit_4->clear();
        QMessageBox::warning(this,QString::fromLocal8Bit("坐标输入错误"),QString::fromLocal8Bit("请输入0~500内的整数"),QMessageBox::Ok);
    }
    //update();
}
void Widget::on_lineEdit_5_editingFinished()
{
    QString a=ui->lineEdit_5->text();
    ye=a.toInt();
    if(ye>500){
        ui->lineEdit_5->clear();
        QMessageBox::warning(this,QString::fromLocal8Bit("坐标输入错误"),QString::fromLocal8Bit("请输入0~500内的整数"),QMessageBox::Ok);
    }
   // update();
}




void Widget::slot1()//插补方式选择导致输入参数改变
{

    ui->groupBox_2->setEnabled(1);//能够设置插补方向
    ui->lineEdit_6->setEnabled(1);//能够输入半径
    ui->radioButton_3->setCheckable(1);
    ui->radioButton_4->setCheckable(1);

}



void Widget::paintExis(){
    QPainter painter(this);
    QFont font;//字体类属性对象
    font.setPixelSize(11);//设置字体大小
    painter.setFont(font);
    QString str;
    for(int x=20;x<=500;x=x+20){
    str=QString::number(x);
    painter.drawText(x-5,height()-9,str);
    painter.drawLine(x,height(),x,height()-8);
    }

    for(int y=20;y<=500;y=y+20){
    str=QString::number(y);//数字转字符串
    painter.drawText(9,height()-y+2,str);
    painter.drawLine(0,height()-y,8,height()-y);
    }
    font.setPixelSize(20);//设置字体大小
    painter.setFont(font);
    painter.drawText(520,height()-5,"x");
    painter.drawText(5,180,"y");

}

void Widget::on_lineEdit_6_editingFinished()//构造圆
{
    QString a=ui->lineEdit_6->text();
    r=a.toInt();
    if(r>500||r<1){
        ui->lineEdit_6->clear();
        QMessageBox::warning(this,QString::fromLocal8Bit("半径长度输入错误"),QString::fromLocal8Bit("请输入1~500内的整数"),QMessageBox::Ok);
    }
    /*Circle c(xs,ys,xe,ye,r);
    if(c.isCircle==0){
        ui->lineEdit_6->clear();
        QMessageBox::warning(this,QString::fromLocal8Bit("半径长度输入错误"),QString::fromLocal8Bit("请输入合理长度的半径"),QMessageBox::Ok);
    }
    xc=c.xc;yc=c.yc;*/

    //update();
}

void Widget::ArcInterpolationClockwise(int x0,int y0,int x1,int y1,int r,double xc,double yc,int step){//圆弧顺时针插补
    QPainter painter(this);
    painter.setWindow(0,this->height(),this->width(),-(this->height()));//重新设置坐标系
    int nx=(x1-x0)/step;int ny=(y1-y0)/step;int n=qAbs(nx)+qAbs(ny);
    int dircx;int dircy;
    if(x1>x0) {dircx=1;}else if(x1<x0) {dircx=-1;}else  {dircx=0;}
    if(y1>y0) dircy=1;else if(y1<y0)dircy=-1;else { dircy=0;}
    int x=x0,y=y0;
    int xb,yb;
//    double xm=(x0+x1)/2; double ym=(y0+y1)/2;//另一种计算圆心方法*************
//    double dx2=qPow(qAbs(x1-x0)/2,2)+qPow(qAbs(y1-y0)/2,2);
//    double dml=qPow(qPow(r,2)-dx2,0.5);
//    double k=((double)(y1-y0))/((double)(x1-x0));
//    double k1=-1/k;
//    double xc1=xm-dml/(qPow(qPow(k1,2)+1,0.5));
//    double yc1=ym-dml/(qPow(qPow(k1,2)+1,0.5))*k1;
//    int count=0;
//    qDebug()<<"k"<<k;
//    qDebug()<<"k1"<<k1;
//    qDebug()<<"dx2"<<dx2;
//    qDebug()<<"dml"<<dml;
//    qDebug()<<"xc1"<<xc1<<"yc1"<<yc1;
//    qDebug()<<"xc"<<xc<<"yc"<<yc;
    while(n>0||qAbs(y-y1)>step||qAbs(x-x1)>step){
        if(n==0){
            qDebug()<<"x"<<x<<"y"<<y;
        }
        xb=x;yb=y;
        if(x>xc&&y>=yc){
            if(qPow(x-xc,2)+qPow(y-yc,2)>=qPow(r,2)){
                y=y-step;
                n=n+dircy;
            }
            else if(qPow(x-xc,2)+qPow(y-yc,2)<qPow(r,2)){
                x=x+step;
                n=n-dircx;
            }
        }
        else if(x>=xc&&y<yc){
            if(qPow(x-xc,2)+qPow(y-yc,2)>=qPow(r,2)){
                x=x-step;
                n=n+dircx;
            }
            else if(qPow(x-xc,2)+qPow(y-yc,2)<qPow(r,2)){
                y=y-step;
                n=n+dircy;

            }
        }
        else if(x<xc&&y<=yc){
            if(qPow(x-xc,2)+qPow(y-yc,2)>=qPow(r,2)){
                y=y+step;
                n=n-dircy;

            }
            else if(qPow(x-xc,2)+qPow(y-yc,2)<qPow(r,2)){
                x=x-step;
                n=n+dircx;

            }
        }
        else if(x<=xc&&y>yc){
            if(qPow(x-xc,2)+qPow(y-yc,2)>=qPow(r,2)){
                x=x+step;
                n=n-dircx;
            }
            else if(qPow(x-xc,2)+qPow(y-yc,2)<qPow(r,2)){
                y=y+step;
                n=n-dircy;

            }
        }
        painter.drawLine(xb,yb,x,y);
    }

}




void Widget::on_radioButton_clicked()
{
    ui->groupBox_2->setEnabled(1);
    ui->radioButton_3->setCheckable(0);
    ui->radioButton_4->setCheckable(0);
    ui->lineEdit_6->clear();
    ui->lineEdit_6->setEnabled(0);
    ui->groupBox_2->setEnabled(0);

}


void Widget::on_pushButton_pressed()
{
    switcher=1;
    if(ui->radioButton_2->isChecked()==1){
        Circle c(xs,ys,xe,ye,r);//构造圆
        if(c.isCircle==0){
           isCircle=0;
           ui->lineEdit_6->clear();
            QMessageBox::warning(this,QString::fromLocal8Bit("半径长度输入错误"),QString::fromLocal8Bit("请输入合理长度的半径"),QMessageBox::Ok);
        }
        else{
        isCircle=1;
        xc=c.xc;yc=c.yc;
        update();
        }
    }


}


void Widget::on_pushButton_released()
{

    switcher=0;
}

void Widget::ArcInterpolationCounterclock(int x0,int y0,int x1,int y1,int r,double xc,double yc,int step){//逆时针插补
    QPainter painter(this);
    painter.setWindow(0,this->height(),this->width(),-(this->height()));//重新设置坐标系
    int nx=(x1-x0)/step;int ny=(y1-y0)/step;int n=qAbs(nx)+qAbs(ny);
    int dircx;int dircy;
    if(x1>x0) {dircx=1;}else if(x1<x0) {dircx=-1;}else  {dircx=0;}
    if(y1>y0) dircy=1;else if(y1<y0)dircy=-1;else { dircy=0;}
    int x=x0,y=y0;
    int xb,yb;
    qDebug()<<"xc"<<xc<<"yc"<<yc<<"dircx"<<dircx<<"dircy"<<dircy;
    while(n>0||qAbs(y-y1)>step||qAbs(x-x1)>step){//判定终点条件
        qDebug()<<n;
        qDebug()<<"x"<<x<<"y"<<y;
        xb=x;yb=y;
        if(x>=xc&&y>yc){
            if(qPow(x-xc,2)+qPow(y-yc,2)>=qPow(r,2)){
                x=x-step;
                n=n+dircx;
            }
            else if(qPow(x-xc,2)+qPow(y-yc,2)<qPow(r,2)){
                y=y+step;
                n=n-dircy;
            }
        }
        else if(x>xc&&y<=yc){
            if(qPow(x-xc,2)+qPow(y-yc,2)>=qPow(r,2)){
                y=y+step;
                n=n-dircy;
            }
            else if(qPow(x-xc,2)+qPow(y-yc,2)<qPow(r,2)){
                x=x+step;
                n=n-dircx;

            }
        }
        else if(x<=xc&&y<yc){
            if(qPow(x-xc,2)+qPow(y-yc,2)>=qPow(r,2)){
                x=x+step;
                n=n-dircx;

            }
            else if(qPow(x-xc,2)+qPow(y-yc,2)<qPow(r,2)){
                y=y-step;
                n=n+dircy;

            }
        }
        else if(x<xc&&y>=yc){
            if(qPow(x-xc,2)+qPow(y-yc,2)>=qPow(r,2)){
                y=y-step;
                n=n+dircy;
            }
            else if(qPow(x-xc,2)+qPow(y-yc,2)<qPow(r,2)){
                x=x-step;
                n=n+dircx;

            }
        }
        painter.drawLine(xb,yb,x,y);
    }
}

