#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QTimer>
#include<QVector>
#include<QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

private:
    void initSerialPort();
    void signalsAndSlots();

private:
    Ui::MainWindow *ui;
    static const int maxSerial = 32;
    QVector<QString> serialNameList;
    QVector<QSerialPort*> aliveSerialPortList;
    QTimer* timer;
};

#endif // MAINWINDOW_H