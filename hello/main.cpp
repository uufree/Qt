#include<QApplication>
#include"newspaper.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Button button;
    button.display();

    return app.exec();
}
