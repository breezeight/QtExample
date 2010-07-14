#ifndef MYWEBVIEW_H
#define MYWEBVIEW_H

#include <QWebView>
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



};

#endif // MYWEBVIEW_H
