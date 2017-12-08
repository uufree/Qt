#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPainter>
#include<QWidget>
#include<QEvent>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    PaintedWidget(QWidget* widget = 0);
protected:
    void paintEvent(QPaintEvent*);
};

#endif // MAINWINDOW_H
