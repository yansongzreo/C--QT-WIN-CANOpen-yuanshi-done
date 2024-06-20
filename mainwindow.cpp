#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QMessageBox>
#include <QBarSeries>
#define AXIS_MAX_X 30
#define AXIS_MAX_Y 2000
static int count = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList listHeader;
    listHeader << "系统时间" << "时间标识" << "时间标识(s)" << "CAN通道" << "传输方向" << "ID号" << "帧类型" << "帧格式" << "长度" << "数据";

    ui->comboBox_3->setCurrentIndex(10);

    ui->tableWidget->setColumnCount(listHeader.count());
    ui->tableWidget->setHorizontalHeaderLabels(listHeader);

    ui->tableWidget->setColumnWidth(0,120);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,120);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,80);
    ui->tableWidget->setColumnWidth(5,120);
    ui->tableWidget->setColumnWidth(6,90);
    ui->tableWidget->setColumnWidth(7,90);
    ui->tableWidget->setColumnWidth(8,80);
    ui->tableWidget->setColumnWidth(9,250);

    //for(int i = 0;i < 9;i ++)
    //    ui->tableWidget->horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);


    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);


    //ui 曲线
    timer = new QTimer(this);
    timer->setInterval(1000);

    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimeout);

    //新增一个窗口来画图
    m_spaxisX = new QValueAxis();
    m_spaxisY = new QValueAxis();
    m_spaxisX->setTitleText("X-label");
    m_spaxisY->setTitleText("Y-label");
    m_spaxisX->setMin(0);
    m_spaxisY->setMin(0);
    m_spaxisX->setMax(AXIS_MAX_X);
    m_spaxisY->setMax(AXIS_MAX_Y);

    m_spSeries = new QSplineSeries();
    m_spSeries->setPointsVisible(true);
    m_spSeries->setName("电机曲线");

    m_spchart = new QChart();
    m_spchart->addAxis(m_spaxisY, Qt::AlignLeft);
    m_spchart->addAxis(m_spaxisX, Qt::AlignBottom);
    m_spchart->addSeries(m_spSeries);
    m_spchart->setAnimationOptions(QChart::SeriesAnimations);//注释调可防止抖动

    m_spSeries->attachAxis(m_spaxisX);
    m_spSeries->attachAxis(m_spaxisY);

    ui->graphicsView_2->setChart(m_spchart);
    ui->graphicsView_2->setRenderHint(QPainter::Antialiasing);

    //init parsejson
    parseJSON();




    canthread = new CANThread();
    connect(canthread,&CANThread::getProtocolData,this,&MainWindow::onGetProtocolData);//接收
    connect(canthread,&CANThread::boardInfo,this,&MainWindow::onBoardInfo);
}

// 导入json文件
void MainWindow::parseJSON()
{
    //QByteArray data;
    //QJsonDocument doc= QJsonDocument::fromJson(data,&json_error);
    //读取json文件
    //#注意：凡是双引号 请用@@代替
    qDebug()<<QCoreApplication::applicationDirPath()+"/test.json";
    QFile file2_json(QCoreApplication::applicationDirPath()+"/test.json");
    file2_json.open(QIODevice::ReadWrite);
    //json文件读入字符串
    QByteArray data = file2_json.readAll();
    qDebug()<<data.data();
    file2_json.close();

    //使用字符串初始化json文件对象
    QJsonDocument doc = QJsonDocument::fromJson(data);
    qDebug()<<"parseJSON00";
    //判断是否是对象
    if(doc.isObject()){
        qDebug()<<"parseJSON01";
        //json文件对象转换为QJsonObject
        QJsonObject obj = doc.object();
        qDebug()<<"parseJSON02";
        //解析对象，val是键“server”的值，是一个QJsonValue::Object

        QJsonValue start_val = obj.value("start");
         //0是表明只执行一次，1 表示无数次
        QJsonValue stop_val = obj.value("stop");

        QJsonValue readspeed_val = obj.value("readspeed");
        //解析数组
        //判断是否是QJsonValue::Array
        if(start_val.isArray()){
            //将QJsonValue::Array转换为QJsonArray
            QJsonArray array = start_val.toArray();
            //获取数组长度
            int nSize = array.size();
            qDebug()<<"start_val size:" << nSize;
            //遍历数组将其存入vec_d
            for (int i = 0; i < nSize; ++i){
                //检查数组元素的类型
                QJsonValue value = array.at(i);
                //如果是double则放入vec_d
                QString cmd = value.toString();
                qDebug()<<"start_val" << cmd;
                cancmd_vel_forword.push_back(cmd);

              }
            }
        if(stop_val.isArray()){
            //将QJsonValue::Array转换为QJsonArray
            QJsonArray array = stop_val.toArray();
            //获取数组长度
            int nSize = array.size();
            qDebug()<<"start_val size:" << nSize;
            //遍历数组将其存入vec_d
            for (int i = 0; i < nSize; ++i){
                //检查数组元素的类型
                QJsonValue value = array.at(i);
                //如果是double则放入vec_d
                QString cmd = value.toString();
                qDebug()<<"stop_val" << cmd;
                cancmd_motor_disable.push_back(cmd);

              }
            }
        if(readspeed_val.isArray()){
            //将QJsonValue::Array转换为QJsonArray
            QJsonArray array = readspeed_val.toArray();
            //获取数组长度
            int nSize = array.size();
            qDebug()<<"start_val size:" << nSize;
            //遍历数组将其存入vec_d
            for (int i = 0; i < nSize; ++i){
                //检查数组元素的类型
                QJsonValue value = array.at(i);
                //如果是double则放入vec_d
                QString cmd = value.toString();
                qDebug()<<"readspeed_val" << cmd;
                cancmd_readspeed.push_back(cmd);

              }
            }

        }



}

void MainWindow::slotTimeout()
{
    //定时器去请求数据 产生 新的数据

    //on_sendBtn_func("40 6C 60 00 00 00 00 00"); // 读取速度
    on_sendBtn_func(cancmd_readspeed[0]);



}
void MainWindow::drawcurveline(int newData)
{
    if (count > AXIS_MAX_X)
    {


        m_spSeries->remove(0);
        m_spchart->axes(Qt::Horizontal).first()->setMin(count - AXIS_MAX_X);
        m_spchart->axes(Qt::Horizontal).first()->setMax(count);
    }

    //newData = qrand()%AXIS_MAX_Y;

    m_spSeries->append(QPointF(count, newData));
    m_spSeries->setUseOpenGL(true);
    count++;
}

void MainWindow::on_pushButton_Clear_clicked()
{
    timer->stop();
    ui->pushButton_StartTimer->setDisabled(0);
    ui->pushButton_Clear->setDisabled(1);

}

void MainWindow::on_pushButton_StartTimer_clicked()
{
    if (!timer->isActive())
    {
        timer->start();
        ui->pushButton_StartTimer->setDisabled(1);
        ui->pushButton_Clear->setDisabled(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddDataToList(QStringList strList)
{
    if(!ui->checkBox_4->checkState())
        return;
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    for(int i = 0; i < strList.count();i ++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(strList.at(i),0);
        ui->tableWidget->setItem(row, i, item);
        if(i != strList.count() - 1)
            ui->tableWidget->item(row,i)->setTextAlignment(Qt::AlignCenter | Qt::AlignHCenter);

    }
    ui->tableWidget->scrollToBottom();
}
void MainWindow::onGetProtocolData(VCI_CAN_OBJ *vci,unsigned int dwRel,unsigned int channel)
{
    QStringList messageList;
    QString str;
    for(unsigned int i = 0;i < dwRel;i ++)
    {
        messageList.clear();
        messageList << QTime::currentTime().toString("hh:mm:ss zzz");//时间
        if(vci[i].TimeFlag == 1)
        {
            messageList << "0x" + QString("%1").arg(vci[i].TimeStamp,8,16,QChar('0')).toUpper();//时间
            messageList << QString("%1").arg(QVariant(vci[i].TimeStamp * 0.1).toUInt(),8,10,QChar('0'));//时间
        }
        else
        {
            messageList << "无";//时间
            messageList << "无";//时间
        }
        messageList << "CH" + QString::number(channel);
        messageList << "接收";//收发
        messageList << "0x" + QString("%1").arg(vci[i].ID,8,16,QChar('0')).toUpper();//ID
        messageList << ((vci[i].RemoteFlag == 1) ? "远程帧" : "数据帧");//类型
        messageList << ((vci[i].ExternFlag == 1) ? "扩展帧" : "标准帧");//Frame
        QString str = "";
        if(vci[i].RemoteFlag == 0)//数据帧显示数据
        {
            messageList << "0x" + QString::number(vci[i].DataLen,16).toUpper();//长度
            str = "x| ";
            //BYTE	Data[8];  定义的标准的SDO数据
            for(int j = 0;j < vci[i].DataLen;j ++)
                str += QString("%1 ").arg(vci[i].Data[j],2,16,QChar('0')).toUpper();//QString::number(recvCANData[i].frame.data[j],16) + " ";
        }
        else
            messageList << "0x0";//长度
        messageList << str;//数据
        /*
        //listHeader << "时间"  << "收/发" << "ID" << "Frame" << "类型" << "长度" << "数据";
        messageList.clear();
        messageList << QString::number(channel);
        messageList << "收";//收发
        messageList << "0x" + QString("%1").arg(vci[i].ID,8,16,QChar('0'));//ID
        messageList << ((vci[i].ExternFlag == 1) ? "扩展帧" : "标准帧");//Frame
        messageList << ((vci[i].RemoteFlag == 1) ? "远程帧" : "数据帧");//类型
        str = "";
        if(vci[i].RemoteFlag == 0)//数据帧显示数据
        {
            messageList << QString::number(vci[i].DataLen);//长度
            for(int j = 0;j < vci[i].DataLen;j ++)
                str += QString("%1 ").arg(vci[i].Data[j],2,16,QChar('0'));//QString::number(recvCANData[i].frame.data[j],16) + " ";
        }
        else
            messageList << "0";//长度
        messageList << str;//数据
        */
        AddDataToList(messageList);

        if(timer->isActive())//收到数据后是否画曲线
        {

             if(vci[i].Data[0] == 0x43 && vci[i].Data[1] == 0x6C && vci[i].Data[2] == 0x60 && vci[i].Data[3] == 0x00)
             {
                 int curveread = vci[i].Data[4] + vci[i].Data[5]*256 + vci[i].Data[6]*256*256 + vci[i].Data[7]*256*256*256;
                 qDebug()<<str << curveread ;
                 drawcurveline(curveread);
             }

        }
    }
}

QString versionStr(USHORT ver)
{
    return "V" + QString::number((ver & 0x0FFF) /0x100,16).toUpper() + "." + QString("%1 ").arg((ver & 0x0FFF) % 0x100,2,16,QChar('0')).toUpper();
}

void MainWindow::onBoardInfo(VCI_BOARD_INFO vbi)
{
    ui->label_9->setText(QString::number(vbi.can_Num));
    ui->label_10->setText(versionStr(vbi.hw_Version));
    ui->label_12->setText(versionStr(vbi.in_Version));
    ui->label_13->setText(QString::number(vbi.irq_Num));
}

void MainWindow::on_pushButton_clicked()//打开
{
    if(ui->pushButton->text() == tr("打开设备"))
    {
        UINT baundRate = 0;
        if(ui->comboBox_3->currentText().indexOf("Kbps") != -1)
            baundRate = ui->comboBox_3->currentText().remove("Kbps").toUInt();
        else
            baundRate = QVariant(ui->comboBox_3->currentText().remove("Mbps").toFloat()).toUInt();
        bool dev = canthread->openDevice(4,//QVariant(ui->comboBox->currentIndex()).toUInt(),
                                      QVariant(ui->comboBox_2->currentIndex()).toUInt(),
                                      baundRate);
        if(dev == true)
        {
            ui->comboBox->setEnabled(false);
            ui->comboBox_2->setEnabled(false);
            ui->comboBox_3->setEnabled(false);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton->setText(tr("关闭设备"));
        }
        else
            QMessageBox::warning(this,"警告","打开设备失败！");
    }
    else if(ui->pushButton->text() == tr("关闭设备"))
    {
        ui->comboBox->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->sendBtn->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton->setText(tr("打开设备"));
        canthread->stop();
        canthread->closeDevice();
    }
}
void MainWindow::on_sendBtn_func(QString text)// tsxt = 11 22 33  = 0x11 0x22 0x33
{
    if(ui->sendBtn->isEnabled())
    {
        //on_sendBtn_func("40 6C 60 00 00 00 00 00"); // 读取速度
        QStringList strList = text.split(" ");
        unsigned char data[8];
        memset(data,0,8);
        UINT dlc = 0;
        dlc = strList.count() > 8 ? 8 : strList.count();
        for(int i = 0;i < dlc;i ++)
            data[i] = strList.at(i).toInt(Q_NULLPTR,16);
        if(canthread->sendData(QVariant(ui->comboBox_4->currentIndex()).toUInt(),
                               QVariant(ui->sendIDEdit->text().toInt(Q_NULLPTR,16)).toUInt(),
                               ui->comboBox_5->currentIndex(),
                               ui->comboBox_6->currentIndex(),
                               data,dlc))
        {//发送成功，打印数据
            QStringList messageList;

            messageList.clear();
            messageList << QTime::currentTime().toString("hh:mm:ss zzz");//时间
            messageList << "无";//时间
            messageList << "无";//时间
            messageList << "CH" + QString::number(QVariant(ui->comboBox_4->currentIndex()).toUInt());
            messageList << "发送";//收发
            messageList << "0x" + ui->sendIDEdit->text().toUpper();//ID
            messageList << ((ui->comboBox_5->currentIndex() == 0) ? "数据帧" : "远程帧");//类型
            messageList << ((ui->comboBox_6->currentIndex() == 0) ? "标准帧" : "扩展帧");//Frame
            QString str = "";
            if(ui->comboBox_5->currentIndex() == 0)//数据帧显示数据
            {
                messageList << "0x" + QString::number(dlc,16).toUpper();//长度
                str = "x| ";
                for(int j = 0;j < dlc;j ++)
                    str += QString("%1 ").arg((unsigned char)data[j],2,16,QChar('0')).toUpper();//QString::number((unsigned char)data[j],16) + " ";
            }
            else
                messageList << "0x0";//长度
            messageList << str;//数据
            AddDataToList(messageList);
        }
        else
            QMessageBox::warning(this,"警告","数据发送失败！");
    }
    else
    {
        qDebug()<<"error:CAN 未激活";
    }

}

void MainWindow::on_sendBtn_clicked()
{
    if(ui->comboBox_6->currentIndex() == 0)//标准帧，ID 范围0-0x7FF
    {
        if(ui->sendIDEdit->text().toInt(Q_NULLPTR,16) > 0x7FF)
        {
            QMessageBox::warning(this,"警告","发送失败，标准帧ID范围为0~0x7FF！");
            return;
        }
    }
    else
    {
        if(ui->sendIDEdit->text().toInt(Q_NULLPTR,16) > 0x1FFFFFFF)
        {
            QMessageBox::warning(this,"警告","发送失败，扩展帧ID范围为0~0x1FFFFFFF！");
            return;
        }
    }
    on_sendBtn_func(ui->sendDataEdit->text());
    /*QStringList strList = ui->sendDataEdit->text().split(" ");
    unsigned char data[8];
    memset(data,0,8);
    UINT dlc = 0;
    dlc = strList.count() > 8 ? 8 : strList.count();
    for(int i = 0;i < dlc;i ++)
        data[i] = strList.at(i).toInt(Q_NULLPTR,16);
    if(canthread->sendData(QVariant(ui->comboBox_4->currentIndex()).toUInt(),
                           QVariant(ui->sendIDEdit->text().toInt(Q_NULLPTR,16)).toUInt(),
                           ui->comboBox_5->currentIndex(),
                           ui->comboBox_6->currentIndex(),
                           data,dlc))
    {//发送成功，打印数据
        QStringList messageList;

        messageList.clear();
        messageList << QTime::currentTime().toString("hh:mm:ss zzz");//时间
        messageList << "无";//时间
        messageList << "无";//时间
        messageList << "CH" + QString::number(QVariant(ui->comboBox_4->currentIndex()).toUInt());
        messageList << "发送";//收发
        messageList << "0x" + ui->sendIDEdit->text().toUpper();//ID
        messageList << ((ui->comboBox_5->currentIndex() == 0) ? "数据帧" : "远程帧");//类型
        messageList << ((ui->comboBox_6->currentIndex() == 0) ? "标准帧" : "扩展帧");//Frame
        QString str = "";
        if(ui->comboBox_5->currentIndex() == 0)//数据帧显示数据
        {
            messageList << "0x" + QString::number(dlc,16).toUpper();//长度
            str = "x| ";
            for(int j = 0;j < dlc;j ++)
                str += QString("%1 ").arg((unsigned char)data[j],2,16,QChar('0')).toUpper();//QString::number((unsigned char)data[j],16) + " ";
        }
        else
            messageList << "0x0";//长度
        messageList << str;//数据
        AddDataToList(messageList);
    }
    else
        QMessageBox::warning(this,"警告","数据发送失败！");*/
}

void MainWindow::on_cleanListBtn_clicked()
{
    ui->tableWidget->setRowCount(0);
}

void MainWindow::on_pushButton_4_clicked()//复位
{
    if(canthread->reSetCAN())
    {
        ui->pushButton_4->setEnabled(false);
        ui->sendBtn->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
    }
    else
        QMessageBox::warning(this,"警告","CAN复位失败！");
}

void MainWindow::on_pushButton_2_clicked()//初始化
{
    if(canthread->initCAN())
    {
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }
    else
        QMessageBox::warning(this,"警告","CAN初始化失败！");
}

void MainWindow::on_pushButton_3_clicked()//启动
{
    if(canthread->startCAN())
    {
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(true);
        ui->sendBtn->setEnabled(true);
        canthread->start();
    }
    else
        QMessageBox::warning(this,"警告","CAN启动失败！");
}

void MainWindow::on_pushButton_velocityctl_forward_clicked()
{
    for(int i = 0;i<cancmd_vel_forword.size();i++)
    {
        on_sendBtn_func(cancmd_vel_forword[i]);
    }
}

void MainWindow::on_pushButton_motor_disable_clicked()
{
    for(int i = 0;i<cancmd_motor_disable.size();i++)
    {
        on_sendBtn_func(cancmd_motor_disable[i]);
    }
}
