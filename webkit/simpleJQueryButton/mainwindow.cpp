#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QDebug>
#include <QKeyEvent>
#include "mywebview.h"

MyWebView *view;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    view = new MyWebView();

    view->page()->setLinkDelegationPolicy( QWebPage::DelegateExternalLinks );
    view = new MyWebView();
    setCentralWidget(view);
    view->load(QUrl("qrc:/bris.html"));
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
