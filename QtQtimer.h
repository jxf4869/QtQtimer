#pragma once

#include <QtWidgets/QDialog>
#include "ui_QtQtimer.h"
#include <qlcdnumber.h>
#include <QMouseEvent>
class QtQtimer : public QLCDNumber
{
    Q_OBJECT

public:
    QtQtimer(QWidget *parent = nullptr);
    ~QtQtimer();

private:
    QPoint  m_pos;//相对于电子时钟左上角的位置
    QTimer* m_timer;  
    bool m_showColon;//一秒闪烁":"

private slots:
    void on_showLCDClock();


protected:
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
};
