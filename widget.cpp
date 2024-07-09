#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label_9->hide();

    timer = new QTimer;
    connect(timer,&QTimer::timeout,this,[=](){
        // 早8晚4

//        QDateTime currentDateTime = QDateTime::currentDateTime();
//        int hour = currentDateTime.time().hour();
//        int minute = currentDateTime.time().minute();
//        int second = currentDateTime.time().second();
//        QString time1= QString("%1:%2:%3").arg(hour).arg(minute).arg(second);           // 当前时间
//        QTime timestart(hour, minute, second);
//        QTime timeend(16, 00, 00);
//        int secondsDifference = qAbs (timestart.secsTo(timeend));
//        int hours = secondsDifference / 3600;
//        int minutes = (secondsDifference % 3600) / 60;
//        int seconds = secondsDifference % 60;
//        QString time1_1= QString("%1:%2:%3").arg(hours).arg(minutes).arg(seconds);      // 剩余
//        QString time1_2= QString("%1:%2:%3").arg(00).arg(15).arg(55);       // 当前已经休息总时
//        QString time1_3= QString("%1:%2:%3").arg(8-hours).arg(60-minutes).arg(60-seconds);       // 总工作量
//        QString time1_4= QString("%1:%2:%3").arg(00).arg(15).arg(55);       // 休息的总时间
//        QString time1_5= QString("%1:%2:%3").arg(hour+2).arg(minute).arg(second);       // 下次该休息时间
//        QString time1_6= QString("%1:%2:%3").arg(hour-2).arg(minute).arg(second);       // 上次休息时间
//        ui->lineEdit->setText(time1);       // 当前时间
//        ui->lineEdit_2->setText(time1_1);   // 剩余
//        ui->lineEdit_3->setText(time1_2);   // 当前已经休息总时
//        ui->lineEdit_4->setText(time1_3);   // 总工作量
//        ui->lineEdit_5->setText(time1_4);   // 休息的总时间
//        ui->lineEdit_6->setText(time1_5);   // 下次该休息时间
//        ui->lineEdit_7->setText(time1_6);   // 上次休息时间

        if(flag == 1)
        {
            QDateTime currentDateTime = QDateTime::currentDateTime();
            int hour = currentDateTime.time().hour();
            int minute = currentDateTime.time().minute();
            int second = currentDateTime.time().second();
            QString time1= QString("%1:%2:%3").arg(hour).arg(minute).arg(second);           // 当前时间
            QTime timestart(hour, minute, second);
            QTime timeend(16, 00, 00);
            int secondsDifference = qAbs (timestart.secsTo(timeend));
            int hours = secondsDifference / 3600;
            int minutes = (secondsDifference % 3600) / 60;
            int seconds = secondsDifference % 60;
//            QString time1_1= QString("%1:%2:%3").arg(hours).arg(minutes).arg(seconds);      // 剩余
//            QString time1_2= QString("%1:%2:%3").arg(00).arg(15).arg(55);       // 当前已经休息总时
////            QString time1_3= QString("%1:%2:%3").arg(8-hours).arg(60-minutes).arg(60-seconds);       // 总工作量
//            QString time1_4= QString("%1:%2:%3").arg(00).arg(15).arg(55);       // 休息的总时间
//            QString time1_5= QString("%1:%2:%3").arg(hour+2).arg(minute).arg(second);       // 下次该休息时间
//            QString time1_6= QString("%1:%2:%3").arg(hour-2).arg(minute).arg(second);       // 上次休息时间
//            ui->lineEdit->setText(time1);       // 当前时间
//            ui->lineEdit_2->setText(time1_1);   // 剩余
            int secondsDifference2 = qAbs (timestart.secsTo(timeEnd));
            int hours2 = secondsDifference2 / 3600;
            int minutes2 = (secondsDifference2 % 3600) / 60;
            int seconds2 = secondsDifference2 % 60;

            QString time1_2= QString("%1:%2:%3").arg(hours2).arg(minutes2).arg(seconds2);       // 当前已经休息总时
//            QString time1_3= QString("%1:%2:%3").arg(8-hours).arg(60-minutes).arg(60-seconds);       // 总工作量
            QString time1_4= QString("%1:%2:%3").arg(hours2).arg(minutes2).arg(seconds2);       // 休息的总时间

            ui->lineEdit_3->setText(time1_2);   // 当前已经休息总时
//            ui->lineEdit_4->setText(time1_3);   // 总工作量
            ui->lineEdit_5->setText(time1_4);   // 休息的总时间
//            ui->lineEdit_6->setText(time1_5);   // 下次该休息时间
//            ui->lineEdit_7->setText(time1_6);   // 上次休息时间
        }
        else
        {
            QDateTime currentDateTime = QDateTime::currentDateTime();
            int hour = currentDateTime.time().hour();
            int minute = currentDateTime.time().minute();
            int second = currentDateTime.time().second();
            QString time1= QString("%1:%2:%3").arg(hour).arg(minute).arg(second);           // 当前时间
            QTime timestart(hour, minute, second);
            // 设置时分秒，例如设置为14:30:59
            timeEnd = QTime(hour, minute, second);
            QTime timeend(16, 00, 00);
            int secondsDifference = qAbs (timestart.secsTo(timeend));
            int hours = secondsDifference / 3600;
            int minutes = (secondsDifference % 3600) / 60;
            int seconds = secondsDifference % 60;
            QString time1_1= QString("%1:%2:%3").arg(hours).arg(minutes).arg(seconds);      // 剩余
            QString time1_2= QString("%1:%2:%3").arg(00).arg(15).arg(55);       // 当前已经休息总时
            QString time1_3= QString("%1:%2:%3").arg(8-hours).arg(60-minutes).arg(60-seconds);       // 总工作量
            QString time1_4= QString("%1:%2:%3").arg(00).arg(15).arg(55);       // 休息的总时间
            QString time1_5= QString("%1:%2:%3").arg(hour+2).arg(minute).arg(second);       // 下次该休息时间
            QString time1_6= QString("%1:%2:%3").arg(hour-2).arg(minute).arg(second);       // 上次休息时间
            ui->lineEdit->setText(time1);       // 当前时间
            ui->lineEdit_2->setText(time1_1);   // 剩余
            ui->lineEdit_3->setText(time1_2);   // 当前已经休息总时
            ui->lineEdit_4->setText(time1_3);   // 总工作量
            ui->lineEdit_5->setText(time1_4);   // 休息的总时间
            ui->lineEdit_6->setText(time1_5);   // 下次该休息时间
            ui->lineEdit_7->setText(time1_6);   // 上次休息时间
        }



    });
    timer ->start(500);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui->label_9->show();
}


void Widget::on_pushButton_2_clicked()
{
    flag = 1;
    ui->label_9->hide();
}
