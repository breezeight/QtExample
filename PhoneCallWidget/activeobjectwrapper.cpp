#include "activeobjectwrapper.h"
#include "activeobjectwrapperprivate.h"

ActiveObjectWrapper::ActiveObjectWrapper(QObject *parent) :
    QObject(parent),
    d_ptr(new ActiveObjectWrapperPrivate(this))
{
}

void ActiveObjectWrapper::requestManufacturer()
{
    d_ptr->RequestManufacturer();
}
