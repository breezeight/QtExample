#include "mywebview.h"
#include <QDebug>

MyWebView::MyWebView(QWidget *parent) :
    QWebView(parent)
{
}


void MyWebView::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Down)
    {
        bool b = page()->focusNextPrevChild (true );
        qDebug() << b;
    }
    else if (e->key() == Qt::Key_Up)
    {
        bool b = page()->focusNextPrevChild (false );
        qDebug() << b;
    }
    else
        QWebView::keyPressEvent(e);
}
