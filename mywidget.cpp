#include "mywidget.h"
#include "QPushButton"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn1 = new QPushButton(this);
    QPushButton *btn2 = new QPushButton(this);

    btn1->setText("Close");
    btn2->setText("按钮2");
    //connect(btn1,&QPushButton::click,this,&QWidget::close);
    btn2->move(0,100);

    resize(600,400);

    setWindowTitle("QT程序");

    connect(btn1,&QPushButton::clicked,this,&QWidget::close);
    //QMetaObject::connectSlotsByName(this);
    resize(300,200);
    resize(600,400);

    this->zt = new Teacher(this);
    this->st = new student(this);

    //connect(zt,&Teacher::hungry,st,&student::treat);

    void(Teacher::* tSignal)(QString) = &Teacher::hungry;
    void(student::* sSignal)(QString) = &student::treat;
    connect(zt,tSignal,st,sSignal);
    classIsOver();
}

void myWidget::classIsOver()
{
    emit zt->hungry("宫保鸡丁");
}

myWidget::~myWidget()
{
}

