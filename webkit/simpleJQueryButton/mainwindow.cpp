#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->page()->setLinkDelegationPolicy( QWebPage::DelegateExternalLinks );
    QWebView v;
    //ui->webView->load(QUrl("C:/TestQtJquery/bris.html"));
    ui->webView->load(QUrl("qrc:/bris.html"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_webView_linkClicked(QUrl url )
{
    setWindowTitle(url.toString());
    qDebug() << url;
}
