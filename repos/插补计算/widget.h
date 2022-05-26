#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPair>
#include <QDebug>
#include <QIntValidator>
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
    void LineInterpolation(int x0,int y0,int x1,int y1,int step,QPainter &painter);
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





private slots:
    void slot1();

private:
    Ui::Widget *ui;
    int step=10;
    int xs{0},ys{0};
    int xe{0},ye{0};
};
#endif // WIDGET_H


