#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QPaintEvent>
#include<QImage>
#include<QPainter>
#include<QColor>
#include<QPen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initPainter();

protected:
    void paintEvent(QPaintEvent*)
    {
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

private:
    Ui::MainWindow *ui;
    QImage image;
    static int const X = 600;
    static int const Y = 300;
};

#endif // MAINWINDOW_H
