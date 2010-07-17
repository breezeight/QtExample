#ifndef MYWEBVIEW_H
#define MYWEBVIEW_H

#include <QWebView>
#include <QWebElementCollection>
#include <QKeyEvent>

class MyWebView : public QWebView
{
    Q_OBJECT
public:
    explicit MyWebView(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *e);

signals:

public slots:

private slots:
    void onLoadFinished();

private:
    int nextSpanY();
    int prevSpanY();
    QWebElementCollection m_allSpans;
    int m_spanIndex;
};

#endif // MYWEBVIEW_H
