#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QLineEdit>
#include<QPushButton>
#include<QTableWidget>
#include<QComboBox>
#include<QDebug>
#include<QFile>
#include<QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentCups(9),
    seconds(0),
    currentSerialPort(new QSerialPort),
    serialTimer(new QTimer),
    timeTimer(new QTimer),
    dateTime(new QTime),
    widget(new QTableWidget)
{
    ui->setupUi(this);

    QFile qss(":/qss/uuchen.qss");
    if(!qss.open(QIODevice::ReadOnly))
        qDebug() << "qss: open file error!";
    QTextStream in(&qss);
    QString styleSheet = in.readAll();
    this->setStyleSheet(styleSheet);

    char ch = 0x31;
    for(int i=0;i<32;i++)
    {
        addrList.append(ch);
        ++ch;
    }
    cupNameList = {"表1：","表2：","表3：","表4：","表5：","表6：","表7：","表8：","表9：","表10：","表11：","表12：","表13：","表14：","表15：","表16：","表17：","表18：","表19：","表20：","表21：","表22：","表23：","表24：","表25：","表26：","表27：","表28：","表29：","表30：","表31：","表32："};
    tableGroupList = {"第一组：","第二组：","第三组：","第四组：","第五组：","第六组：","第七组：","第八组：","第九组：","第十组：","第十一组：","第十二组：","第十三组：","第十四组：","第十五组：","第十六组：","第十七组：","第十八组：","第十九组：","第二十组：","第二十一组：","第二十二组：","第二十三组：","第二十四组：","第二十五组：","第二十六组：","第二十七组：","第二十八组：","第二十九组：","第三十组：","第三十一组：","第三十二组："};

    for(int i=0;i<32;i++)
    {
        currentSpeed[i] = 0;
        currentVolume[i] = 0;
        currentSpeed[i] = 0;
        currentVolume[i] = 0;
    }

    //new position ways

    initAll();
    widget->resize(1,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startClicked()
{
    if(ui->startBtton->text() == tr("开始"))
    {
        exportDataList.clear();
        clearAll();//清理掉已有的信息
        collectSettingMessage();//收集设置区的信息
        start();//根据设置区的信息建立串口，启动定时器
        ui->startBtton->setText(tr("停止"));
        ui->flushButton->setEnabled(false);
        ui->saveDataButton->setText(tr("保存数据"));
    }
    else
    {
        serialTimer->stop();
        if(!exportDataList.empty())
            writeDataInFile();
        ui->startBtton->setText(tr("开始"));
        ui->flushButton->setEnabled(true);
        ui->saveDataButton->setText(tr("历史数据"));
    }
}

void MainWindow::flushClicked()
{
    clearAll();//清理数据区的所有信息
    ui->settingPort->clear();
    foreach(const QSerialPortInfo& info,QSerialPortInfo::availablePorts())
        ui->settingPort->addItem(info.portName());
}

void MainWindow::exportDataClicked()//保存数据信息
{
    if(ui->saveDataButton->text() == tr("保存数据"))
    {
        for(int i=0;i<currentCups;i++)
        {
            exportDataList.push_back(currentSpeed[i]);
            exportDataList.push_back(averageSpeed[i]);
            exportDataList.push_back(currentVolume[i]);
            exportDataList.push_back(averageVolume[i]);
        }
    }
    else
    {//读取数据，并且显示数据
        //读取数据
        readDataInFile();
        //显示数据
            //表格初始化过程
        int rowCount = (exportDataList.size() / 4 / currentCups) * (currentCups + 1);
        int countInGroup = currentCups + 1;
        widget->setColumnCount(4);
        widget->setRowCount(rowCount);
        QTableWidgetItem* item1 = new QTableWidgetItem;
        item1->setText("当前风速");
        widget->setHorizontalHeaderItem(0,item1);
        QTableWidgetItem* item2 = new QTableWidgetItem;
        item2->setText("平均风速");
        widget->setHorizontalHeaderItem(1,item2);
        QTableWidgetItem* item3 = new QTableWidgetItem;
        item3->setText("当前风量");
        widget->setHorizontalHeaderItem(2,item3);
        QTableWidgetItem* item4 = new QTableWidgetItem;
        item4->setText("平均风量");
        widget->setHorizontalHeaderItem(3,item4);

        for(int i=0;i<rowCount/countInGroup;i++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(tableGroupList[i]);
            widget->setVerticalHeaderItem(i * countInGroup,item);

            for(int j = 1;j < countInGroup;j++)
            {
                QTableWidgetItem* item = new QTableWidgetItem;
                if(j < countInGroup)
                    item->setText(cupNameList[j-1]);
                else
                    item->setText("");
                widget->setVerticalHeaderItem(i * countInGroup + j,item);
            }
        }

            //填充表格
        for(int i=0;i<rowCount/countInGroup;i++)
        {
            for(int j = 1;j < countInGroup;j++)
            {
                for(int k = 0;k < 4;k++)
                {
                    widget->setItem(i * countInGroup + j,k,new QTableWidgetItem(QString::number(exportDataList.front())));
                    exportDataList.pop_front();
                }
            }
        }

        widget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        widget->resize(480,500);
        widget->setWindowTitle(currentFile);
        widget->setWindowModality(Qt::ApplicationModal);
        widget->show();
    }
}

void MainWindow::writeDataInFile()
{
    currentFile.clear();
    currentFile = dateTimeStr + ".dat";
    currentFile = "/home/uuchen/" + currentFile;
    QFile current(currentFile);
    if(current.exists())
        current.remove();
    if(!current.open(QIODevice::ReadWrite))
        qDebug() << "writeDataInFile: open file error!";
    QDataStream out(&current);
    out << exportDataList;
    exportDataList.clear();
    current.close();
}

void MainWindow::readDataInFile()
{
    exportDataList.clear();
    QFile current(currentFile);
    if(!current.open(QIODevice::ReadWrite))
        qDebug() << "readDataInFile: open file error!";
    QDataStream in(&current);
    in >> exportDataList;
    current.close();
}

void MainWindow::handleTimeout()
{
    //串口数据写发送的时候会默认加上\r\n
    for(int i=0;i<currentCups;i++)
    {
        char ch = addrList[i];
        currentSerialPort->write(&ch);
        qDebug() << "write: " << (uint8_t)ch;
        char in = '1';
//        currentSerialPort->read(&in,1);
//        qDebug() << "read: " << (uint8_t)in;
        QByteArray buf = currentSerialPort->readAll();
        qDebug() << buf.data();

        currentSpeed[i] = (uint8_t)in * settingData.cupSpeed.toInt();
        currentVolume[i] = currentSpeed[i] * settingData.testArea.toInt();
        averageSpeed[i] = (averageSpeed[i] + currentSpeed[i]) / 2;
        averageVolume[i] = (averageVolume[i] + currentVolume[i]) / 2;
    }

}

void MainWindow::updateTime()
{
    dateTimeStr = dateTime->currentTime().toString();
    ui->currentTime->setText(dateTimeStr);

    //记录当前运行的总时间
    ++seconds;

    int average = 0;
    if(ui->startBtton->text() == tr("停止"))
    {
        QString str;
        //更新cups speed
        for(int i=0;i<currentCups;i++)
        {
            str = cupNameList[i] + QString::number(currentSpeed[i]);
            cupList[i]->setText(str);
            average += currentSpeed[i];
        }

        //更新currrent cup数据
        if(ui->currentCup->text() != "")
        {
            int index = ui->currentCup->text().toInt() - 1;
            ui->currentSpeed->setText(QString::number(currentSpeed[index]));
            ui->currentVolume->setText(QString::number(currentVolume[index]));
            ui->currentAverageSpeed->setText(QString::number(averageSpeed[index]));
            ui->currentAverageVolume->setText(QString::number(averageVolume[index]));
        }

        //更新画折线图需要的数据
        average = average / currentCups;
        lineChartMessage.push_front(average);
        if(lineChartMessage.size() > 10)
            lineChartMessage.pop_back();

        Point2 = QPoint(0.47 * this->width(),0.65 * this->height());
        Point1 = QPoint(0.47 * this->width(),30);
        Point3 = QPoint(this->width()-30,0.65 * this->height());

        SizeX = (Point3.rx() - Point2.rx()) / 10;
        SizeY = (Point2.ry() - Point1.ry()) / 10;
        //更新折线图
        update();
    }

}

void MainWindow::cupButtonClicked0()
{
    ui->currentCup->setText(QString::number(0+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[0]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[0]));
    ui->currentSpeed->setText(QString::number(currentSpeed[0]));
    ui->currentVolume->setText(QString::number(currentVolume[0]));
}
void MainWindow::cupButtonClicked1()
{
    ui->currentCup->setText(QString::number(1+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[1]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[1]));
    ui->currentSpeed->setText(QString::number(currentSpeed[1]));
    ui->currentVolume->setText(QString::number(currentVolume[1]));
}
void MainWindow::cupButtonClicked2()
{
    ui->currentCup->setText(QString::number(2+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[2]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[2]));
    ui->currentSpeed->setText(QString::number(currentSpeed[2]));
    ui->currentVolume->setText(QString::number(currentVolume[2]));
}
void MainWindow::cupButtonClicked3()
{
    ui->currentCup->setText(QString::number(3+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[3]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[3]));
    ui->currentSpeed->setText(QString::number(currentSpeed[3]));
    ui->currentVolume->setText(QString::number(currentVolume[3]));
}
void MainWindow::cupButtonClicked4()
{
    ui->currentCup->setText(QString::number(4+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[4]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[4]));
    ui->currentSpeed->setText(QString::number(currentSpeed[4]));
    ui->currentVolume->setText(QString::number(currentVolume[4]));
}
void MainWindow::cupButtonClicked5()
{
    ui->currentCup->setText(QString::number(5+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[5]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[5]));
    ui->currentSpeed->setText(QString::number(currentSpeed[5]));
    ui->currentVolume->setText(QString::number(currentVolume[5]));
}
void MainWindow::cupButtonClicked6()
{
    ui->currentCup->setText(QString::number(6+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[6]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[6]));
    ui->currentSpeed->setText(QString::number(currentSpeed[6]));
    ui->currentVolume->setText(QString::number(currentVolume[6]));
}
void MainWindow::cupButtonClicked7()
{
    ui->currentCup->setText(QString::number(7+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[7]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[7]));
    ui->currentSpeed->setText(QString::number(currentSpeed[7]));
    ui->currentVolume->setText(QString::number(currentVolume[7]));
}

void MainWindow::cupButtonClicked8()
{
    ui->currentCup->setText(QString::number(8+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[8]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[8]));
    ui->currentSpeed->setText(QString::number(currentSpeed[8]));
    ui->currentVolume->setText(QString::number(currentVolume[8]));
}
void MainWindow::cupButtonClicked9()
{
    ui->currentCup->setText(QString::number(9+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[9]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[9]));
    ui->currentSpeed->setText(QString::number(currentSpeed[9]));
    ui->currentVolume->setText(QString::number(currentVolume[9]));
}
void MainWindow::cupButtonClicked10()
{
    ui->currentCup->setText(QString::number(10+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[10]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[10]));
    ui->currentSpeed->setText(QString::number(currentSpeed[10]));
    ui->currentVolume->setText(QString::number(currentVolume[10]));
}
void MainWindow::cupButtonClicked11()
{
    ui->currentCup->setText(QString::number(11+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[11]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[11]));
    ui->currentSpeed->setText(QString::number(currentSpeed[11]));
    ui->currentVolume->setText(QString::number(currentVolume[11]));
}

void MainWindow::cupButtonClicked12()
{
    ui->currentCup->setText(QString::number(12+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[12]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[12]));
    ui->currentSpeed->setText(QString::number(currentSpeed[12]));
    ui->currentVolume->setText(QString::number(currentVolume[12]));
}
void MainWindow::cupButtonClicked13()
{
    ui->currentCup->setText(QString::number(13+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[13]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[13]));
    ui->currentSpeed->setText(QString::number(currentSpeed[13]));
    ui->currentVolume->setText(QString::number(currentVolume[13]));
}
void MainWindow::cupButtonClicked14()
{
    ui->currentCup->setText(QString::number(14+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[14]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[14]));
    ui->currentSpeed->setText(QString::number(currentSpeed[14]));
    ui->currentVolume->setText(QString::number(currentVolume[14]));
}
void MainWindow::cupButtonClicked15()
{
    ui->currentCup->setText(QString::number(15+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[15]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[15]));
    ui->currentSpeed->setText(QString::number(currentSpeed[15]));
    ui->currentVolume->setText(QString::number(currentVolume[15]));
}

void MainWindow::cupButtonClicked16()
{
    ui->currentCup->setText(QString::number(16+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[16]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[16]));
    ui->currentSpeed->setText(QString::number(currentSpeed[16]));
    ui->currentVolume->setText(QString::number(currentVolume[16]));
}
void MainWindow::cupButtonClicked17()
{
    ui->currentCup->setText(QString::number(17+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[17]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[17]));
    ui->currentSpeed->setText(QString::number(currentSpeed[17]));
    ui->currentVolume->setText(QString::number(currentVolume[17]));
}
void MainWindow::cupButtonClicked18()
{
    ui->currentCup->setText(QString::number(18+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[18]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[18]));
    ui->currentSpeed->setText(QString::number(currentSpeed[18]));
    ui->currentVolume->setText(QString::number(currentVolume[18]));
}
void MainWindow::cupButtonClicked19()
{
    ui->currentCup->setText(QString::number(19+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[19]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[19]));
    ui->currentSpeed->setText(QString::number(currentSpeed[19]));
    ui->currentVolume->setText(QString::number(currentVolume[19]));
}

void MainWindow::cupButtonClicked20()
{
    ui->currentCup->setText(QString::number(20+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[20]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[20]));
    ui->currentSpeed->setText(QString::number(currentSpeed[20]));
    ui->currentVolume->setText(QString::number(currentVolume[20]));
}
void MainWindow::cupButtonClicked21()
{
    ui->currentCup->setText(QString::number(21+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[21]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[21]));
    ui->currentSpeed->setText(QString::number(currentSpeed[21]));
    ui->currentVolume->setText(QString::number(currentVolume[21]));
}
void MainWindow::cupButtonClicked22()
{
    ui->currentCup->setText(QString::number(22+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[22]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[22]));
    ui->currentSpeed->setText(QString::number(currentSpeed[22]));
    ui->currentVolume->setText(QString::number(currentVolume[22]));
}
void MainWindow::cupButtonClicked23()
{
    ui->currentCup->setText(QString::number(23+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[23]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[23]));
    ui->currentSpeed->setText(QString::number(currentSpeed[23]));
    ui->currentVolume->setText(QString::number(currentVolume[23]));
}

void MainWindow::cupButtonClicked24()
{
    ui->currentCup->setText(QString::number(24+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[24]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[24]));
    ui->currentSpeed->setText(QString::number(currentSpeed[24]));
    ui->currentVolume->setText(QString::number(currentVolume[24]));
}
void MainWindow::cupButtonClicked25()
{
    ui->currentCup->setText(QString::number(25+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[25]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[25]));
    ui->currentSpeed->setText(QString::number(currentSpeed[25]));
    ui->currentVolume->setText(QString::number(currentVolume[25]));
}
void MainWindow::cupButtonClicked26()
{
    ui->currentCup->setText(QString::number(26+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[26]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[26]));
    ui->currentSpeed->setText(QString::number(currentSpeed[26]));
    ui->currentVolume->setText(QString::number(currentVolume[26]));
}
void MainWindow::cupButtonClicked27()
{
    ui->currentCup->setText(QString::number(27+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[27]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[27]));
    ui->currentSpeed->setText(QString::number(currentSpeed[27]));
    ui->currentVolume->setText(QString::number(currentVolume[27]));
}

void MainWindow::cupButtonClicked28()
{
    ui->currentCup->setText(QString::number(28+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[28]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[28]));
    ui->currentSpeed->setText(QString::number(currentSpeed[28]));
    ui->currentVolume->setText(QString::number(currentVolume[28]));
}
void MainWindow::cupButtonClicked29()
{
    ui->currentCup->setText(QString::number(29+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[29]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[29]));
    ui->currentSpeed->setText(QString::number(currentSpeed[29]));
    ui->currentVolume->setText(QString::number(currentVolume[29]));
}
void MainWindow::cupButtonClicked30()
{
    ui->currentCup->setText(QString::number(30+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[30]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[30]));
    ui->currentSpeed->setText(QString::number(currentSpeed[30]));
    ui->currentVolume->setText(QString::number(currentVolume[30]));
}
void MainWindow::cupButtonClicked31()
{
    ui->currentCup->setText(QString::number(31+1));
    ui->currentAverageSpeed->setText(QString::number(averageSpeed[31]));
    ui->currentAverageVolume->setText(QString::number(averageVolume[31]));
    ui->currentSpeed->setText(QString::number(currentSpeed[31]));
    ui->currentVolume->setText(QString::number(currentVolume[31]));
}

void MainWindow::initSettingArea()
{
//init settingSerialPortBox
    foreach(const QSerialPortInfo& info,QSerialPortInfo::availablePorts())
        ui->settingPort->addItem(info.portName());

    ui->settingPort->setCurrentIndex(0);
    settingData.portName = ui->settingPort->currentText();

//init settingSpeed
    ui->settingSpeed->setText("1");
    settingData.cupSpeed = "1";

//init baud
    ui->settingBaudBox->setCurrentText("9600");
    settingData.baud = "9600";

//init testArea
    ui->settingTestArea->setText("1");
    settingData.testArea = "1";

//init pollTime
    ui->settingPoll->setCurrentIndex(2);
    settingData.pollTime = ui->settingPoll->currentText();

//init cups
    ui->settingCups->setCurrentText("9");
    settingData.cupCount = "9";

    QObject::connect(ui->startBtton,SIGNAL(clicked()),this,SLOT(startClicked()));
    QObject::connect(ui->flushButton,SIGNAL(clicked()),this,SLOT(flushClicked()));
    QObject::connect(ui->saveDataButton,SIGNAL(clicked()),this,SLOT(exportDataClicked()));
}

//初始化左下的时间显示模块
//稍后处理计算能力之后加上其他的模块
void MainWindow::initCurrentDisplayArea()
{
    dateTimeStr = dateTime->currentTime().toString();
    ui->currentTime->setText(dateTimeStr);
    QObject::connect(timeTimer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timeTimer->start(1000);
}

//初始化折线图信息
void MainWindow::initLineChart()
{
    Point2 = QPoint(0.47 * this->width(),0.65 * this->height());
    Point1 = QPoint(0.47 * this->width(),30);
    Point3 = QPoint(this->width()-30,0.65 * this->height());

    SizeX = (Point3.rx() - Point2.rx()) / 10;
    SizeY = (Point2.ry() - Point1.ry()) / 10;
}

void MainWindow::initSpeed()
{
    QObject::connect(ui->E0,SIGNAL(clicked()),this,SLOT(cupButtonClicked0()));
    cupList.append(ui->E0);
    QObject::connect(ui->E1,SIGNAL(clicked()),this,SLOT(cupButtonClicked1()));
    cupList.append(ui->E1);
    QObject::connect(ui->E2,SIGNAL(clicked()),this,SLOT(cupButtonClicked2()));
    cupList.append(ui->E2);
    QObject::connect(ui->E3,SIGNAL(clicked()),this,SLOT(cupButtonClicked3()));
    cupList.append(ui->E3);
    QObject::connect(ui->E4,SIGNAL(clicked()),this,SLOT(cupButtonClicked4()));
    cupList.append(ui->E4);
    QObject::connect(ui->E5,SIGNAL(clicked()),this,SLOT(cupButtonClicked5()));
    cupList.append(ui->E5);
    QObject::connect(ui->E6,SIGNAL(clicked()),this,SLOT(cupButtonClicked6()));
    cupList.append(ui->E6);
    QObject::connect(ui->E7,SIGNAL(clicked()),this,SLOT(cupButtonClicked7()));
    cupList.append(ui->E7);
    QObject::connect(ui->E8,SIGNAL(clicked()),this,SLOT(cupButtonClicked8()));
    cupList.append(ui->E8);
    QObject::connect(ui->E9,SIGNAL(clicked()),this,SLOT(cupButtonClicked9()));
    cupList.append(ui->E9);
    QObject::connect(ui->EA,SIGNAL(clicked()),this,SLOT(cupButtonClicked10()));
    cupList.append(ui->EA);
    QObject::connect(ui->EB,SIGNAL(clicked()),this,SLOT(cupButtonClicked11()));
    cupList.append(ui->EB);
    QObject::connect(ui->EC,SIGNAL(clicked()),this,SLOT(cupButtonClicked12()));
    cupList.append(ui->EC);
    QObject::connect(ui->ED,SIGNAL(clicked()),this,SLOT(cupButtonClicked13()));
    cupList.append(ui->ED);
    QObject::connect(ui->EE,SIGNAL(clicked()),this,SLOT(cupButtonClicked14()));
    cupList.append(ui->EE);
    QObject::connect(ui->EF,SIGNAL(clicked()),this,SLOT(cupButtonClicked15()));
    cupList.append(ui->EF);
    QObject::connect(ui->F0,SIGNAL(clicked()),this,SLOT(cupButtonClicked16()));
    cupList.append(ui->F0);
    QObject::connect(ui->F1,SIGNAL(clicked()),this,SLOT(cupButtonClicked17()));
    cupList.append(ui->F1);
    QObject::connect(ui->F2,SIGNAL(clicked()),this,SLOT(cupButtonClicked18()));
    cupList.append(ui->F2);
    QObject::connect(ui->F3,SIGNAL(clicked()),this,SLOT(cupButtonClicked19()));
    cupList.append(ui->F3);
    QObject::connect(ui->F4,SIGNAL(clicked()),this,SLOT(cupButtonClicked20()));
    cupList.append(ui->F4);
    QObject::connect(ui->F5,SIGNAL(clicked()),this,SLOT(cupButtonClicked21()));
    cupList.append(ui->F5);
    QObject::connect(ui->F6,SIGNAL(clicked()),this,SLOT(cupButtonClicked22()));
    cupList.append(ui->F6);
    QObject::connect(ui->F7,SIGNAL(clicked()),this,SLOT(cupButtonClicked23()));
    cupList.append(ui->F7);
    QObject::connect(ui->F8,SIGNAL(clicked()),this,SLOT(cupButtonClicked24()));
    cupList.append(ui->F8);
    QObject::connect(ui->F9,SIGNAL(clicked()),this,SLOT(cupButtonClicked25()));
    cupList.append(ui->F9);
    QObject::connect(ui->FA,SIGNAL(clicked()),this,SLOT(cupButtonClicked26()));
    cupList.append(ui->FA);
    QObject::connect(ui->FB,SIGNAL(clicked()),this,SLOT(cupButtonClicked27()));
    cupList.append(ui->FB);
    QObject::connect(ui->FC,SIGNAL(clicked()),this,SLOT(cupButtonClicked28()));
    cupList.append(ui->FC);
    QObject::connect(ui->FD,SIGNAL(clicked()),this,SLOT(cupButtonClicked29()));
    cupList.append(ui->FD);
    QObject::connect(ui->FE,SIGNAL(clicked()),this,SLOT(cupButtonClicked30()));
    cupList.append(ui->FE);
    QObject::connect(ui->FF,SIGNAL(clicked()),this,SLOT(cupButtonClicked31()));
    cupList.append(ui->FF);

    QObject::connect(serialTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
}

void MainWindow::initAll()
{
    initSettingArea();
    initCurrentDisplayArea();
    initLineChart();
    initSpeed();
}

void MainWindow::clearCurrentMessage()
{
    ui->currentCup->clear();
    ui->currentAverageSpeed->clear();
    ui->currentAverageVolume->clear();
    ui->currentSpeed->clear();
    ui->currentVolume->clear();
}

void MainWindow::clearLineChart()
{
    //清理折线图信息
}

void MainWindow::clearSpeed()
{
    for(int i=0;i<currentCups;++i)
        cupList[i]->setText(cupNameList[i]);
}

void MainWindow::clearAll()
{
    clearCurrentMessage();
    clearLineChart();
    clearSpeed();
}

void MainWindow::collectSettingMessage()
{
    settingData.baud = ui->settingBaudBox->currentText();
    settingData.cupCount = ui->settingCups->currentText();
    settingData.cupSpeed = ui->settingSpeed->text();
    settingData.pollTime = ui->settingPoll->currentText();
    settingData.portName = ui->settingPort->currentText();
    settingData.testArea = ui->settingTestArea->text();
}

void MainWindow::start()
{
    currentCups = settingData.cupCount.toInt();
    for(int i=0;i<maxCups;++i)
    {
        if(i < currentCups)
            cupList[i]->setEnabled(true);
        else
            cupList[i]->setEnabled(false);
    }

    if(currentSerialPort != NULL)
    {
        currentSerialPort->close();
        delete currentSerialPort;
    }

    //这块没有按照设置的方式来设置端口信息
    currentSerialPort = new QSerialPort;
    currentSerialPort->setPortName(ui->settingPort->currentText());
    currentSerialPort->open(QIODevice::ReadWrite);
    //设置波特率
    if(settingData.baud == "9600")
        currentSerialPort->setBaudRate(QSerialPort::Baud9600);
    else if(settingData.baud == "2400")
        currentSerialPort->setBaudRate(QSerialPort::Baud2400);
    else if(settingData.baud == "4800")
        currentSerialPort->setBaudRate(QSerialPort::Baud4800);
    else if(settingData.baud == "19200")
        currentSerialPort->setBaudRate(QSerialPort::Baud19200);
    else
        currentSerialPort->setBaudRate(QSerialPort::Baud9600);

    currentSerialPort->setDataBits(QSerialPort::Data8);
    currentSerialPort->setParity(QSerialPort::NoParity);
    currentSerialPort->setStopBits(QSerialPort::OneStop);
    currentSerialPort->setFlowControl(QSerialPort::NoFlowControl);

    serialTimer->start(settingData.pollTime.toInt());
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintSystem();
    paintLineChart();
}

void MainWindow::paintSystem()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawLine(Point1,Point2);
    painter.drawLine(Point2,Point3);

    int sizeY = (Point2.ry() - Point1.ry()) / 10;
    int sizeX = (Point3.rx() - Point2.rx()) / 10;
    for(int i=1;i<=10;++i)//y刻度线
    {
        painter.drawLine(Point2.rx(),Point2.ry() - sizeY * i,Point2.rx() - 5,Point2.ry() - sizeY * i);
        painter.drawText(Point2.rx() - 35,Point2.ry() - sizeY * i + 5,QString::number((i * systemSize)));
    }

    for(int i=1;i<=10;++i)//x刻度线
    {
        painter.drawLine(Point2.rx() + sizeX * i,Point2.ry(),Point2.rx() + sizeX * i,Point2.ry() + 5);
        painter.drawText(Point2.rx() + sizeX * i - 5 ,Point2.ry() + 20,QString::number((i)));
    }
    painter.drawText(Point2.rx() - 15,Point2.ry() + 15,QString::number(0));

    painter.drawText(Point2.rx() + 10 * SizeX + 10,Point2.ry() + 10,"秒");
    painter.drawText(Point2.rx() - 20,Point2.ry() - 10 * SizeY - 10,"风量");;

    QFont font;
    QPen pen;
    pen.setColor(Qt::gray);
    font.setPixelSize(20);
    painter.setFont(font);
    painter.setPen(pen);
    painter.drawText(Point2.rx() + 3.5 * SizeX,Point2.ry() - 9.5 * SizeY,"时间-风量变化图");
}

void MainWindow::paintLineChart()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    QPen penLine,penPoint,penText;
    penLine.setColor(Qt::black);
    penLine.setWidth(2);
    penPoint.setColor(Qt::blue);
    penPoint.setWidth(5);
    penText.setColor(Qt::red);
    penText.setWidth(2);

    QVector<QPoint> pointList;//获得10个坐标，在图中依次连起来
    for(int i=0;i<lineChartMessage.size();i++)
    {
        pointList.append(QPoint(Point2.rx() + (i+1) * SizeX,Point2.ry() - lineChartMessage[i] / systemSize * SizeY));
    }
    pointList.reserve(pointList.size());

    for(int i=0;i<lineChartMessage.size()-1;i++)
    {
        painter.setPen(penLine);
        painter.drawLine(pointList[i],pointList[i+1]);
        painter.setPen(penPoint);
        painter.drawPoint(pointList[i]);
        QFont font;
        font.setPixelSize(20);
        painter.setFont(font);
        painter.setPen(penText);
        painter.drawText(pointList[i].rx() - 10,pointList[i].ry() + 20,QString::number(lineChartMessage[i]));
    }

    if(lineChartMessage.size() > 0)
    {
        painter.setPen(penPoint);
        painter.drawPoint(pointList[pointList.size()- 1]);
        painter.setPen(penText);
        painter.drawText(pointList[pointList.size() - 1].rx() - 10,pointList[pointList.size() - 1].ry() + 20,QString::number(lineChartMessage[lineChartMessage.size()-1]));
    }
}
