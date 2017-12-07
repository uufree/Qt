#include <QApplication>
#include"newspaper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NewsPaper* paper = new NewsPaper("paper");
    Reader* uuchen = new Reader;

    QObject::connect(paper,SIGNAL(newPaper(QString)),uuchen,SLOT(readNewsPaper(QString)));
    paper->send();


    return a.exec();
}
