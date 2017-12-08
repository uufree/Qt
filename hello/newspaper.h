#ifndef NEWSPAPER_H
#define NEWSPAPER_H


#include<QPushButton>
#include<QMainWindow>
#include<QTimer>

class Button : public QMainWindow
{
    Q_OBJECT
public:
    Button() : button(new QPushButton("Quit")),timer(new QTimer(this)),number(1)
    {
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(changeButton()));
    }

    Button(const Button&) = delete;
    Button& operator=(const Button&) = delete;

    void display()
    {
        timer->start(3000);
        button->show();
    }

public slots:
    void changeButton()
    {
        if(number == 1)
        {
            button->setText("dog");
            number = 0;
        }
        else
        {
            button->setText("pig");
            number = 1;
        }
    }

private:
    QPushButton* button;
    QTimer* timer;
    int number;
};

#endif // NEWSPAPER_H
