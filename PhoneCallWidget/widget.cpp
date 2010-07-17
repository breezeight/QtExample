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

    m_telephoneNumber = "";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_wrapper->requestManufacturer();
}



void Widget::on_pushButton_dial_clicked()
{
    m_telephoneNumber = ui->lineEdit_dial->text();

    if (m_telephoneNumber != "")
        m_wrapper->dialTelephoneNumber( m_telephoneNumber );
}
