#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QMovie>
#include <QImage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
   // _timerEventId = this->startTimer(1000);

    connect(ui->pushButton,&QPushButton::released,
            [=]()
            {
                this->killTimer(_timerEventId);
            }
        );

    connect(ui->pushButton_2,&QPushButton::released,
            [=]()
            {
                this->startTimer(1000);
            }
        );

    ui->progressBar->setRange(0,100); //设置进度条最小值和最大值(取值范围)
    ui->widget_3->setStyleSheet("QWidget{background:rgb(64,66,68);}");
    ui->label_2->setStyleSheet("QLabel{color:rgb(255,255,255);}");




    ui->label->setGeometry(10,10,300,150);
    ui->label->setStyleSheet("QLabel:hover{border-width: 2px;border-style: solid;border-radius:21px;border-color:rgb(0, 177, 252);}");

    ui->label->setPixmap(QPixmap("://pic/22.jpg"));

    QPushButton *btn = new QPushButton();
    btn->setParent(ui->label);
    btn->setText("I'm a button");
    btn->setGeometry(80,10,90,40);

    connect(btn,&QPushButton::clicked,
            [=]{
                 QMovie *mov = new QMovie("://pic/111.gif");
                 ui->label->setMovie(mov);
                 //mov->stop();
                 ui->label->setScaledContents(true);
                 mov->start();
               }
            );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    static int sec = 0;
    ui->label->setText(
                QString("<center><h1>time out: %1</h1></center>").arg(sec++)
                );
    //ui->progressBar->setValue(sec);  //设置当前的运行值
    double dProgress = sec;
    ui->progressBar->setFormat(tr("Current progress : %1%").arg(QString::number(dProgress, 'f', 1)));
    ui->progressBar->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);  // 对齐方式
}
