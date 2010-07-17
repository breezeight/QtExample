#include "mywebview.h"
#include <QDebug>
#include <QWebElement>
#include <QWebFrame>
#include <QWebPage>

MyWebView::MyWebView(QWidget *parent) :
    QWebView(parent)
    , m_spanIndex(-1)
{
    connect(this, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished()));
}


void MyWebView::keyPressEvent(QKeyEvent *e)
{
    //This property holds the position the frame is currently scrolled to.
    qDebug() << "------------------------------------------------------------" << page()->currentFrame()->scrollPosition ();
    /*QWebElementCollection allSpans = page()->currentFrame()->documentElement().findAll("a");

    foreach (const QWebElement &link, page()->currentFrame()->documentElement().findAll("a")) {
       qDebug() <<  link.toPlainText() << link.geometry();

    }*/

    /*foreach (const QWebElement &link, m_allSpans) {
       qDebug() <<  link.toPlainText() << link.geometry();
    }*/

    //Find the position of the bottom in the scolled area
    QPoint bottomScrollPosition = page()->currentFrame()->scrollPosition();
    bottomScrollPosition.setY( bottomScrollPosition.y() + geometry().bottom());

    QPoint topScrollPosition = page()->currentFrame()->scrollPosition();
    qDebug() << "Scoll Position "<< topScrollPosition << bottomScrollPosition;
    qDebug() << "Scoll Position "<< m_allSpans.count();


    if (e->key() == Qt::Key_Down && ( nextSpanY() < bottomScrollPosition.y()) && m_spanIndex < m_allSpans.count()-1 )
    {
            qDebug() << "(II) Scoll to span ";
            page()->focusNextPrevChild (true );
            if (m_spanIndex < m_allSpans.count()-1)
                m_spanIndex++;
    }
    else if (e->key() == Qt::Key_Up && ( prevSpanY() > topScrollPosition.y()) && m_spanIndex > 0 )
    {
        page()->focusNextPrevChild (false );
        if (m_spanIndex > 0)
            m_spanIndex--;
    }
    else
        QWebView::keyPressEvent(e);

    qDebug() << "span index "<< m_spanIndex;

}

void MyWebView::onLoadFinished()
{
    qDebug() << "MyWebView::onLoadFinished()";
    m_allSpans = page()->currentFrame()->documentElement().findAll("a");
}

int MyWebView::nextSpanY()
{
    int index = m_spanIndex < m_allSpans.count()-1 ? m_spanIndex + 1 : m_spanIndex;
    return page()->currentFrame()->documentElement().findAll("a").at(index).geometry().y();
}

int MyWebView::prevSpanY()
{
    int index = m_spanIndex > 1 ? m_spanIndex - 1 : m_spanIndex;
    return page()->currentFrame()->documentElement().findAll("a").at(index).geometry().y();
}
