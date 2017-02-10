#include "form.h"
#include "ui_form.h"
#include <QLCDNumber>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(2);
}

Form::~Form()
{
    delete ui;
}

void Form::set(int num)
{
    //ui->lcdNumber->intValue();
    ui->label_3->setNum(num);
}

