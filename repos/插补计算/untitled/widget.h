#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPair>
#include <QDebug>
#include <QIntValidator>
#include <QMessageBox>
#include <QtMath>
#include "circle.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void LineInterpolation(int x0,int y0,int x1,int y1,int step);
    void ArcInterpolationClockwise(int x0,int y0,int x1,int y1,int r,double xc,double yc,int step);
    void ArcInterpolationCounterclock(int x0,int y0,int x1,int y1,int r,double xc,double yc,int step);
    void paintExis();


public slots:
    void out_step();
protected:
    void Widget::paintEvent(QPaintEvent*event);


public slots:
    void on_lineEdit_2_editingFinished();
    void on_lineEdit_3_editingFinished();
    void on_lineEdit_4_editingFinished();
    void on_lineEdit_5_editingFinished();




public slots:
    void slot1();

private slots:
    void on_lineEdit_6_editingFinished();



    void on_radioButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::Widget *ui;
    int step=10;
    int xs{0},ys{200};
    int xe{200},ye{200};
    int r{100};
    double xc{100.0},yc{200.0};
    bool switcher=0;

};
#endif // WIDGET_H


