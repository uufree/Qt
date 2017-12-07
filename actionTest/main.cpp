#include "mainwindow.h"
#include<QApplication>
#include<QWidget>
#include<QSpinBox>
#include<QSlider>
#include<QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/*
    QWidget window;
    window.setWindowTitle("Enter your age: ");
    QSpinBox* spinBox = new QSpinBox(&window);
    QSlider* slider = new QSlider(&window);

    spinBox->setRange(0,130);
    slider->setRange(0,130);

    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));

    spinBox->setValue(35);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);

    window.setLayout(layout);
    window.show();
*/
    return a.exec();
}
