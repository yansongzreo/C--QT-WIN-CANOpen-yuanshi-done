#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canthread.h"
#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QSplineSeries>
#include <QValueAxis>
#include <QScatterSeries>
#include <QTimer>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddDataToList(QStringList strList);
    void setChart(QChart *chart);
private slots:
    void onGetProtocolData(VCI_CAN_OBJ *vci,unsigned int dwRel,unsigned int channel);
    void onBoardInfo(VCI_BOARD_INFO vbi);
    void on_pushButton_clicked();

    void on_sendBtn_clicked();

    void on_cleanListBtn_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_StartTimer_clicked();

    void slotTimeout();

    void on_pushButton_velocityctl_forward_clicked();

    void on_pushButton_motor_disable_clicked();

private:
    Ui::MainWindow *ui;
    CANThread *canthread;



    QValueAxis *m_spaxisX;
    QValueAxis *m_spaxisY;


    QSplineSeries *m_spSeries;

    QChart *m_spchart;

    QTimer *timer;

    QVector<QString> cancmd_vel_forword;
    QVector<QString> cancmd_motor_disable;
    QVector<QString> cancmd_readspeed;
    QVector<QString> cancmd_readpos;
    QVector<QString> cancmd_readcurrent;



    void drawcurveline(int newData);
    void on_sendBtn_func(QString text);
    void parseJSON();
};

#endif // MAINWINDOW_H
