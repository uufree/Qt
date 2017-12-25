#include<QApplication>
#include<QFileDialog>
#include<QString>
#include<QDebug>
#include<QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    QFileDialog* dialog = new QFileDialog;
    dialog->setWindowTitle("打开历史数据");
    dialog->setDirectory("/home/uuchen/WindCup/");
    if(dialog->exec() == QDialog::Accepted)
        qDebug() << dialog->selectedFiles()[0];
*/
    return a.exec();
}
