#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentCups(9),
    currentSerialPort(new QSerialPort),
    serialTimer(new QTimer),
    timeTimer(new QTimer),
    date(new QDate),
    time(new QTime),
    widget(new QTableWidget)
{
    ui->setupUi(this);
//加载QSS信息
    QFile qss(":/qss/uuchen.qss");
    if(!qss.open(QIODevice::ReadOnly))
        qDebug() << "qss: open file error!";
    QTextStream in(&qss);
    QString styleSheet = in.readAll();
    this->setStyleSheet(styleSheet);

//初始化地址信息以及其他必要的信息
    uint8_t ch = 0xe0;
    QVector<QString> cupNameList = {"表1：","表2：","表3：","表4：","表5：","表6：","表7：","表8：","表9：","表10：","表11：","表12：","表13：","表14：","表15：","表16：","表17：","表18：","表19：","表20：","表21：","表22：","表23：","表24：","表25：","表26：","表27：","表28：","表29：","表30：","表31：","表32："};
    nameList.insert(0xde,"负压：");
    nameList.insert(0xdf,"大气压：");
    speedList.insert(0xde,0);
    speedList.insert(0xdf,0);
    cupStatuList.insert(0xde,RUNING);
    cupStatuList.insert(0xdf,RUNING);
    for(int i=0;i<32;i++)
    {
        nameList.insert(ch,cupNameList[i]);
        speedList.insert(ch,0);
        cupStatuList.insert(ch,RUNING);
        ++ch;
    }

    for(int i=0;i<9;i++)
        electricalData.append(0);

    tableGroupList = {"第一组：","第二组：","第三组：","第四组：","第五组：","第六组：","第七组：","第八组：","第九组：","第十组：","第十一组：","第十二组：","第十三组：","第十四组：","第十五组：","第十六组：","第十七组：","第十八组：","第十九组：","第二十组：","第二十一组：","第二十二组：","第二十三组：","第二十四组：","第二十五组：","第二十六组：","第二十七组：","第二十八组：","第二十九组：","第三十组：","第三十一组：","第三十二组："};

//分四个区域分别初始化
    initAll();
    widget->resize(1,1);

    /*********在windows运行时需要修改文件路径**********/
    QDir dir("D:\\WindCupData");
    if(!dir.exists())
        dir.mkdir("D:\\WindCupData");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initSettingArea()
{
//init settingSerialPortBox
    foreach(const QSerialPortInfo& info,QSerialPortInfo::availablePorts())
        ui->settingPort->addItem(info.portName());

    ui->settingPort->setCurrentIndex(0);
    settingData.portName = ui->settingPort->currentText();

//init settingSpeed
    ui->settingSpeed->setText("1m/s");
    settingData.cupSpeed = "1";

//init baud
    ui->settingBaudBox->setCurrentText("9600");
    settingData.baud = "9600";

//init testArea
    ui->settingTestArea->setText("1㎡");
    settingData.testArea = "1";

//init pollTime
    ui->settingPoll->setCurrentIndex(2);
    settingData.pollTime = ui->settingPoll->currentText();

//init cups
    ui->settingCups->setCurrentText("9");
    settingData.cupCount = "9";

//init electric
    ui->settingElectric->setText("1");
    settingData.electric = "1";

//init voltage
    ui->settingVoltage->setText("1");
    settingData.voltage = "1";
}

//初始化左下的时间显示模块
//稍后处理计算能力之后加上其他的模块
void MainWindow::initCurrentDisplayArea()
{
    timeTimer->start(1000);
}

//初始化折线图信息
void MainWindow::initLineChart()
{
    Point2 = QPoint(0.55 * this->width(),0.70 * this->height());
    Point1 = QPoint(0.55 * this->width(),30);
    Point3 = QPoint(this->width()-30,0.70 * this->height());

    SizeX = (Point3.rx() - Point2.rx()) / 10;
    SizeY = (Point2.ry() - Point1.ry()) / 10;
}

void MainWindow::initSpeed()
{
    cupList.insert(0xe0,ui->E0);
    cupList.insert(0xe1,ui->E1);
    cupList.insert(0xe2,ui->E2);
    cupList.insert(0xe3,ui->E3);
    cupList.insert(0xe4,ui->E4);
    cupList.insert(0xe5,ui->E5);
    cupList.insert(0xe6,ui->E6);
    cupList.insert(0xe7,ui->E7);
    cupList.insert(0xe8,ui->E8);
    cupList.insert(0xe9,ui->E9);
    cupList.insert(0xea,ui->EA);
    cupList.insert(0xeb,ui->EB);
    cupList.insert(0xec,ui->EC);
    cupList.insert(0xed,ui->ED);
    cupList.insert(0xee,ui->EE);
    cupList.insert(0xef,ui->EF);
    cupList.insert(0xf0,ui->F0);
    cupList.insert(0xf1,ui->F1);
    cupList.insert(0xf2,ui->F2);
    cupList.insert(0xf3,ui->F3);
    cupList.insert(0xf4,ui->F4);
    cupList.insert(0xf5,ui->F5);
    cupList.insert(0xf6,ui->F6);
    cupList.insert(0xf7,ui->F7);
    cupList.insert(0xf8,ui->F8);
    cupList.insert(0xf9,ui->F9);
    cupList.insert(0xfa,ui->FA);
    cupList.insert(0xfb,ui->FB);
    cupList.insert(0xfc,ui->FC);
    cupList.insert(0xfd,ui->FD);
    cupList.insert(0xfe,ui->FE);
    cupList.insert(0xff,ui->FF);
}

void MainWindow::initAll()
{
    QObject::connect(serialTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    QObject::connect(timeTimer,SIGNAL(timeout()),this,SLOT(updateTime()));
    QObject::connect(ui->startBtton,SIGNAL(clicked()),this,SLOT(startClicked()));
    QObject::connect(ui->flushButton,SIGNAL(clicked()),this,SLOT(flushClicked()));
    QObject::connect(ui->saveDataButton,SIGNAL(clicked()),this,SLOT(exportDataClicked()));

    initSettingArea();
    initCurrentDisplayArea();
    initLineChart();
    initSpeed();
}

void MainWindow::clearCurrentMessage()
{
    ui->currentAverageSpeed->clear();
    ui->currentVolume->clear();
}

void MainWindow::clearLineChart()
{
    //清理折线图信息
}

void MainWindow::clearSpeed()
{
    for(int i=0xe0;i<=0xff;i++)
        cupList[i]->setText(nameList[i]);
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
    QString cupCount = ui->settingCups->currentText();
    cupCount.remove(cupCount.size()-1,1);
    settingData.cupCount = cupCount;
    settingData.cupSpeed = ui->settingSpeed->text();
    QString pollTime = ui->settingPoll->currentText();
    pollTime.remove(pollTime.size()-2,2);
    settingData.pollTime = pollTime;
    settingData.portName = ui->settingPort->currentText();
    QString testArea = ui->settingTestArea->text();
    testArea.remove(testArea.size()-1,1);
    settingData.testArea = ui->settingTestArea->text();
    settingData.voltage = ui->settingVoltage->text();
    settingData.electric = ui->settingElectric->text();
}

void MainWindow::start()
{
    currentCups = settingData.cupCount.toInt();
    char index = 0xe0;
    currentAddrList.clear();
    currentAddrList.append(0xde);
    currentAddrList.append(0xdf);
    for(int i=0;i<maxCups;i++)
    {
        if(i < currentCups)
        {
            currentAddrList.append(index);
            cupList[index]->setEnabled(true);
        }
        else
            cupList[index]->setEnabled(false);
        ++index;
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
    else if(settingData.baud == "1200")
        currentSerialPort->setBaudRate(QSerialPort::Baud1200);
    else if(settingData.baud == "2400")
        currentSerialPort->setBaudRate(QSerialPort::Baud2400);
    else if(settingData.baud == "4800")
        currentSerialPort->setBaudRate(QSerialPort::Baud4800);
    else if(settingData.baud == "19200")
        currentSerialPort->setBaudRate(QSerialPort::Baud19200);
    else if(settingData.baud == "38400")
        currentSerialPort->setBaudRate(QSerialPort::Baud38400);
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
    //每次绘制图形之前都会更新坐标位置信息
    Point2 = QPoint(0.55 * this->width(),0.70 * this->height());
    Point1 = QPoint(0.55 * this->width(),30);
    Point3 = QPoint(this->width()-30,0.70 * this->height());

    SizeX = (Point3.rx() - Point2.rx()) / 10;
    SizeY = (Point2.ry() - Point1.ry()) / 10;

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
        painter.drawText(Point2.rx() + sizeX * i - 5 ,Point2.ry() + 20,QString::number((i * 10)));
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
    QPen penLine(Qt::black,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(penLine);

    QVector<QPoint> pointList;//获得10个坐标，在图中依次连起来
    for(int i=0;i<lineChartMessage.size();i++)
    {
        pointList.append(QPoint(Point2.rx() + (i+1) * SizeX / 10,Point2.ry() - lineChartMessage[i] / systemSize * SizeY));
    }
    pointList.reserve(pointList.size());

    for(int i=0;i<lineChartMessage.size()-1;i++)
    {
        painter.drawLine(pointList[i],pointList[i+1]);
    }
}

void MainWindow::startClicked()
{
    if(ui->startBtton->text() == tr("开始"))
    {
        exportDataList.clear();//清理上次剩余的导出的信息
        clearAll();//清理掉已有的信息
        collectSettingMessage();//收集设置区的信息
        ui->startBtton->setText(tr("停止"));
        ui->flushButton->setEnabled(false);
        ui->saveDataButton->setText(tr("保存数据"));
        ui->saveStatueButton->setText("已保存0组");
        currentFile = "uuchen";
        start();//根据设置区的信息建立串口，启动定时器
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
        char index = 0xe0;
        for(int i=0;i<currentCups;i++)
        {
            exportDataList.append(speedList[index]);
            ++index;
        }

        exportDataList.append(averageSpeed);
        exportDataList.append(currentVolume);
        exportDataList.append(negPressure);
        exportDataList.append(atmPressure);

        exportDataList.append(electricalData[0]);
        exportDataList.append(electricalData[1]);
        exportDataList.append(electricalData[2]);
        exportDataList.append(electricalData[3]);
        exportDataList.append(electricalData[4]);
        exportDataList.append(electricalData[5]);
        exportDataList.append(electricalData[6]);
        exportDataList.append(electricalData[7]);
        exportDataList.append(electricalData[8]);

        exportDataList.append(settingData.voltage.toDouble());
        exportDataList.append(settingData.electric.toDouble());
        exportDataList.append(settingData.testArea.toDouble());

        int x = exportDataList.size() / (currentCups + 16);
        ui->saveStatueButton->setText("已保存" + QString::number(x) + "组");
    }
    else
    {//读取数据，并且显示数据
        //加载用户文件对话框
        QFileDialog* dialog = new QFileDialog;
        dialog->setWindowTitle("历史数据");

        /*******在windows运行时需要修改路径*******/
        dialog->setDirectory("D:\\WindCupData");
        dialog->setWindowModality(Qt::ApplicationModal);
        dialog->resize(800,500);
        dialog->setModal(true);
        if(dialog->exec() == QDialog::Accepted)
            currentFile = dialog->selectedFiles()[0];

        //读取数据
        readDataInFile();
        if(!exportDataList.empty())
        {
            int rowCount = (exportDataList.size()) / (currentCups + 16);
            int columnCount = currentCups + 16;
            widget->setColumnCount(columnCount);
            widget->setRowCount(rowCount);
            widget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //初始化X轴
            char index = 0xe0;
            for(int i=0;i<columnCount-16;i++,index++)
            {
                QTableWidgetItem* item = new QTableWidgetItem;
                item->setText(nameList[index]);
                widget->setHorizontalHeaderItem(i,item);
            }

            QTableWidgetItem* item1 = new QTableWidgetItem;
            item1->setText("平均风速:");
            widget->setHorizontalHeaderItem(columnCount-16,item1);
            QTableWidgetItem* item2 = new QTableWidgetItem;
            item2->setText("当前风量:");
            widget->setHorizontalHeaderItem(columnCount-15,item2);
            QTableWidgetItem* item3 = new QTableWidgetItem;
            item3->setText("负压值:");
            widget->setHorizontalHeaderItem(columnCount-14,item3);
            QTableWidgetItem* item4 = new QTableWidgetItem;
            item4->setText("大气压值:");
            widget->setHorizontalHeaderItem(columnCount-13,item4);
            QTableWidgetItem* item5 = new QTableWidgetItem;
            item5->setText("Ua值:");
            widget->setHorizontalHeaderItem(columnCount-12,item5);
            QTableWidgetItem* item6 = new QTableWidgetItem;
            item6->setText("Ia值:");
            widget->setHorizontalHeaderItem(columnCount-11,item6);
            QTableWidgetItem* item7 = new QTableWidgetItem;
            item7->setText("Ub值:");
            widget->setHorizontalHeaderItem(columnCount-10,item7);
            QTableWidgetItem* item8 = new QTableWidgetItem;
            item8->setText("Ib值:");
            widget->setHorizontalHeaderItem(columnCount-9,item8);
            QTableWidgetItem* item9 = new QTableWidgetItem;
            item9->setText("Uc值:");
            widget->setHorizontalHeaderItem(columnCount-8,item9);
            QTableWidgetItem* item10 = new QTableWidgetItem;
            item10->setText("Ic值:");
            widget->setHorizontalHeaderItem(columnCount-7,item10);
            QTableWidgetItem* item11 = new QTableWidgetItem;
            item11->setText("有功功率:");
            widget->setHorizontalHeaderItem(columnCount-6,item11);
            QTableWidgetItem* item12 = new QTableWidgetItem;
            item12->setText("无功功率:");
            widget->setHorizontalHeaderItem(columnCount-5,item12);
            QTableWidgetItem* item13 = new QTableWidgetItem;
            item13->setText("功率因数:");
            widget->setHorizontalHeaderItem(columnCount-4,item13);
            QTableWidgetItem* item14 = new QTableWidgetItem;
            item14->setText("电压变比:");
            widget->setHorizontalHeaderItem(columnCount-3,item14);
            QTableWidgetItem* item15 = new QTableWidgetItem;
            item15->setText("电流变比:");
            widget->setHorizontalHeaderItem(columnCount-2,item15);
            QTableWidgetItem* item16 = new QTableWidgetItem;
            item16->setText("测断面面积:");
            widget->setHorizontalHeaderItem(columnCount-1,item16);
    //初始化Y轴
            for(int i=0;i<rowCount;i++)
            {
                QTableWidgetItem* item = new QTableWidgetItem;
                item->setText(tableGroupList[i]);
                widget->setVerticalHeaderItem(i,item);
            }
    //填充表格
            for(int i=0;i < rowCount;i++)
            {
                for(int j = 0;j < columnCount;j++)
                {
                    if(!exportDataList.empty())
                    {
                        widget->setItem(i,j,new QTableWidgetItem(QString::number(exportDataList.front(),10,2)));
                        exportDataList.pop_front();
                    }
                }
            }

            widget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            widget->resize(800,500);
            widget->setWindowTitle(currentFile);
            widget->setWindowModality(Qt::ApplicationModal);
            widget->show();
        }
    }
}

void MainWindow::writeDataInFile()
{

    //要求用户输入要保存的文件名称
    if(currentFile == "uuchen")
    {
        QInputDialog* dialog = new QInputDialog(this);
        dialog->setModal(false);
        currentFile = dialog->getText(this,"WindCup","请输入新建文件名：");
    /*****在windows运行时需要修改文件路径********/
        if(currentFile.size() != 0)
        {
            currentFile = "D:\\WindCupData\\" + currentFile + ".dat";
            ui->saveStatueButton->setText("已保存");
        }
        else
        {
            exportDataList.clear();
            ui->saveStatueButton->setText("未保存");
        }
    }

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
    if(!current.exists())
        return;
    if(!current.open(QIODevice::ReadWrite))
        qDebug() << "readDataInFile: open file error!";
    QDataStream in(&current);
    in >> exportDataList;
    current.close();
}

void MainWindow::fillCurrentAddrList()
{
    currentAddrList.append(0xde);
    currentAddrList.append(0xdf);
    char index = 0xe0;
    for(int i=0;i<currentCups;i++)
    {
        currentAddrList.append(index);
        index++;
    }
}

//处理串口定时器到期
void MainWindow::handleTimeout()
{
    char ch;
    if(!currentAddrList.empty())
    {
        ch = currentAddrList.front();
        currentAddrList.pop_front();
    }
    else
    {
        char out[7] = {0x4c,0x57,0x01,0x30,0x01,0x32,0x0d};
        currentSerialPort->write(out,7);
        char in[25];
        for(int i=0;i<25;i++)
            in[i] = '\0';
        int readBytes = currentSerialPort->read(in,25);
        qDebug() << "readBytes: " << readBytes;
        int elecIndex = 0;
        if(readBytes == 25)
        {
            double result = 0;
            for(int i=5;i<23;i+=2)
            {//这里只将16位保存下来，在显示的时候进行具体的计算
                bool isNegative = 0x80 & in[i];
                result = (double)((uint16_t)((in[i] & 0x7f) << 8) + (uint8_t)in[i+1]);
                isNegative ? result = -result : result = result;
                electricalData[elecIndex] = result;
                ++elecIndex;
            }
        }

        fillCurrentAddrList();

        return;
    }


    char out[3];
    out[0] = ch;
    out[1] = 0xa5;
    out[2] = 0x5a;
    currentSerialPort->write(out,3);
//    qDebug() << "write: " << (uint8_t)ch;
    char in[4] = {'\0','\0','\0','\0'};
    int readByte = currentSerialPort->read(in,4);
//    qDebug() << "read: " << (uint8_t)in[0]  << " " << (uint8_t)in[1] << " " << (uint8_t)in[2] << " " << (uint8_t)in[3];
//    qDebug() << "readByte: " << readByte;

    if(readByte != 4)
    {
        if((uint8_t)in[0] > 0xdd || (uint8_t)in[0] <= 0xff)
            cupStatuList[(uint8_t)in[0]] = ERROR;
        return;
    }
    else
    {
        if((uint8_t)in[0] > 0xdd || (uint8_t)in[0] <= 0xff)
            cupStatuList[(uint8_t)in[0]] = RUNING;
    }

    if((uint8_t)in[0] < 0xe0)//处理负压与大气压
    {//无符号整数
        speedList[(uint8_t)in[0]] = (uint16_t)((in[2] << 8) + in[3]);
    }
    else
    {//处理风杯
        speedList[(uint8_t)in[0]] = (uint8_t)in[3];
    }
}

//处理1s定时器到期
void MainWindow::updateTime()
{
//更新到期的时间与日期
    timeStr = time->currentTime().toString();
    ui->currentTime->setText(timeStr);
    date->currentDate().getDate(&year,&mouth,&day);
    dateStr = QString::number(year) + "年" + QString::number(mouth) + "月" + QString::number(day) + "日";
    ui->currentDate->setText(dateStr);

//在程序处于数据采集过程中，对信息的更新
    if(ui->startBtton->text() == tr("停止"))
    {
        //计算平均风速与当前数据
        double speedSum = 0;
        uint8_t index = 0xe0;
        for(int i=0;i<currentCups;i++)
        {
            speedSum += speedList[index];
            ++index;
        }
        averageSpeed = speedSum / currentCups;
        currentVolume = averageSpeed * settingData.testArea.toDouble();
        negPressure = speedList[0xde];
        atmPressure = speedList[0xdf];

        //更新平均风速与当前风压
        ui->currentVolume->setText(QString::number(currentVolume,10,2) + "m³/s");
        ui->currentAverageSpeed->setText(QString::number(averageSpeed,10,2) + "m/s");
        ui->currentNegPressure->setText(QString::number(negPressure,10,1) + "Pa");
        ui->currentAtmPressure->setText(QString::number(atmPressure,10,1) + "KPa");

        //更新每个风杯的实时速度
        index = 0xe0;
        for(int i=0;i<currentCups;i++)
        {
            if(cupStatuList[index] == RUNING)
            {
                cupList[index]->setEnabled(true);
                cupList[index]->setText(nameList[index] + QString::number(speedList[index],10,2) + "m/s");
            }
            else
            {
                cupList[index]->setText(nameList[index] + "Error");
                cupList[index]->setEnabled(false);
            }

            ++index;
        }

        //更新电参数数据
        ui->UA->setText(QString::number((double)electricalData[0] / 20 * settingData.voltage.toInt(),10,1) + "V");
        ui->UB->setText(QString::number((double)electricalData[1] / 20 * settingData.electric.toInt(),10,1) + "A");
        ui->UC->setText(QString::number((double)electricalData[2] / 20 * settingData.voltage.toInt(),10,1) + "V");
        ui->IA->setText(QString::number((double)electricalData[3] / 20 * settingData.electric.toInt(),10,1) + "A");
        ui->IB->setText(QString::number((double)electricalData[4] / 20 * settingData.voltage.toInt(),10,1) + "V");
        ui->IC->setText(QString::number((double)electricalData[5] / 20 * settingData.electric.toInt(),10,1) + "A");
        ui->PA->setText(QString::number((double)electricalData[6] * 75 / 1000,10,1) + "KW");
        ui->PB->setText(QString::number((double)electricalData[7] * 75 / 1000,10,1) + "KW");
        ui->PC->setText(QString::number((double)electricalData[8] / 10000,10,1));

        //更新画折线图需要的风量信息
        lineChartMessage.push_front(currentVolume);
        if(lineChartMessage.size() > 100)
            lineChartMessage.pop_back();

    }

    //更新折线图
    update();
}
