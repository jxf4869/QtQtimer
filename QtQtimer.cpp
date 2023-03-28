#include "QtQtimer.h"
#include<QTimer>
#include<Qtime>
QtQtimer::QtQtimer(QWidget *parent)
    : QLCDNumber(parent)
{
    
    //隐藏窗体
    setWindowFlags(Qt::FramelessWindowHint);
    //设置窗体的透明度
    setWindowOpacity(0.5);
    //获取电子时钟调色板
    QPalette palette=this->palette();
    //调色板设置模式以及颜色
    palette.setColor(QPalette::Window,Qt::green);
    //设置电子时钟调色板
    this->setPalette(palette);

    QTimer* timer = new QTimer;
    timer->setInterval(1000);
   
    timer->start();
    connect(timer, &QTimer::timeout,this,&QtQtimer::on_showLCDClock);


    resize(400, 220);
    m_showColon = true;
}

QtQtimer::~QtQtimer()
{}
void QtQtimer::on_showLCDClock() {
   
    QTime currentTime = QTime::currentTime();
    //yyyy-MM-dd hh:mm:ss.zzz
    QString strTimer=currentTime.toString("hh:mm");
   
    if (m_showColon) {//时间 有":"
        strTimer[2] = ':';
        m_showColon = !m_showColon;
    }
    else//时间 无":"
    {
        strTimer[2] = ' ';
        m_showColon = !m_showColon;
    }
    display(strTimer);
}
void QtQtimer::mousePressEvent(QMouseEvent * event)
{   //按下的是左键
    if (event->button() == Qt::LeftButton) {
        //鼠标相对于左上角的位置
        QPoint globalLeftpos = event->globalPos();
        //鼠标相对于电子时钟左上角的位置
        QPoint clockLeftPos= frameGeometry().topLeft();
        //电子时钟相对于窗体左上角位置
        m_pos =globalLeftpos - clockLeftPos;
        //接受所需的事件
        event->accept();
    }
    if (event->button()==Qt::RightButton){
        close();
    
    }
}
void QtQtimer::mouseMoveEvent(QMouseEvent* event)
{
    /*
      event->buttons()
      返回产生事件的按钮状态，函数返回当前按下的所有按钮，按钮状态可以是 
      Qt::LeftButton,Qt::RightButton,Qt::MidButton或运算组合
    */
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos()- m_pos);
        event->accept();

    }
    

}
