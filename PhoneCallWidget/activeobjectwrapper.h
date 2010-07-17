#ifndef ACTIVEOBJECTWRAPPER_H
#define ACTIVEOBJECTWRAPPER_H

#include <QObject>

class ActiveObjectWrapperPrivate;

class ActiveObjectWrapper : public QObject
{
    Q_OBJECT
public:
    explicit ActiveObjectWrapper(QObject *parent = 0);

signals:

public slots: // New slots

    /**
    * requestManufacturer
    * Requests manufacturer information.
    */
    void requestManufacturer();
    void dialTelephoneNumber(QString phoneNumber);

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

private: // Data

    /**
    * d_ptr pointer to private implementation
    * instantiated in constructor.
    */
    ActiveObjectWrapperPrivate *d_ptr;


private: // Friend class definitions

    friend class ActiveObjectWrapperPrivate;
};

#endif // ACTIVEOBJECTWRAPPER_H
