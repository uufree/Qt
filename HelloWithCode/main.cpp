#include<QApplication>
#include<QDialog>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog log;
    QLabel label(&log);
    label.setTest("Hello,wrold!");
    log.show();

    return a.exec();
}
