#include "widget.h"
#include "ui_widget.h"

#include "activeobjectwrapper.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_wrapper(new ActiveObjectWrapper(this))
{
    ui->setupUi(this);
    connect(m_wrapper, SIGNAL(manufacturerUpdated(QString)),
                ui->lineEdit, SLOT(setText(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_wrapper->requestManufacturer();
}
