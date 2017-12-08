#include "mainwindow.h"
#include<QDebug>

PaintedWidget::PaintedWidget(QWidget* widget) :
    QWidget(widget)
{
    resize(600,800);
    setWindowTitle(tr("Paint Demo"));
}

void PaintedWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawLine(0,0,650,500);
    painter.setPen(Qt::red);
    painter.drawRect(10,10,20,20);
    painter.setPen(QPen(Qt::green,5));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50,150,400,200);
}
