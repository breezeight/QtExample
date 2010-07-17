#include "activeobjectwrapperprivate.h"
#include "activeobjectwrapper.h"
#include <QObject>

ActiveObjectWrapperPrivate::ActiveObjectWrapperPrivate(ActiveObjectWrapper *wrapper)
    : CActive(CActive::EPriorityStandard)
    , q_ptr(wrapper)
    , iTelephony(NULL)
    , iPhoneIdV1Pckg(iPhoneIdV1)
{
    CActiveScheduler::Add(this);
}

void ActiveObjectWrapperPrivate::RequestManufacturer()
{
    ASSERT(!IsActive());
    int err = CreateCTelephony();
    if (err)
        {
        emit q_ptr->errorOccured(err);
        }
    else
        {
        iTelephony->GetPhoneId(iStatus, iPhoneIdV1Pckg);
        SetActive();
        }
}

int ActiveObjectWrapperPrivate::CreateCTelephony()
{
    int err = 0;
    if( !iTelephony )
        {
        TRAP(err, iTelephony = CTelephony::NewL());
        }
    return err;
}

void ActiveObjectWrapperPrivate::RunL()
{
    if(iStatus == KErrNone) {
        QString text = QString::fromUtf16(
                iPhoneIdV1.iManufacturer.Ptr(),
                iPhoneIdV1.iManufacturer.Length());
        emit q_ptr->manufacturerUpdated(text);
    } else {
        emit q_ptr->errorOccured(iStatus.Int());
    }
}

void ActiveObjectWrapperPrivate::DoCancel()
{
}
