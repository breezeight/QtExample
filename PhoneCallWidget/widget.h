#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class ActiveObjectWrapper;

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals: // New signals

    /**
    * manufacturerUpdated
    * Signal to be emitted when manufacturer name is received
    * @param manufacturer string containing manufacturer name.
    */
    void manufacturerUpdated(QString manufacturer);

    /**
    * errorOccured
    * Signal to be emitted when error occures.
    * @param error error code.
    */
    void errorOccured(int error);

private:
    Ui::Widget *ui;
    ActiveObjectWrapper *m_wrapper;

private slots:
    void on_pushButton_clicked();
};

#endif // WIDGET_H
