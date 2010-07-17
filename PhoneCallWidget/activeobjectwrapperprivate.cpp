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

void ActiveObjectWrapperPrivate::DialTelephoneNumber(QString phoneNumber)
{
    ASSERT(!IsActive());
    int err = CreateCTelephony();
    if (err)
    {
        emit q_ptr->errorOccured(err);
    }
    else
    {
        // converto il phonenumber nel tipo di symbian
        TPtrC aPhoneNumber(static_cast<const TUint16*>(phoneNumber.utf16()), phoneNumber.length());
        CTelephony::TTelNumber telNumber(aPhoneNumber);

        // imposto le opzioni della chiamata
        // impostazioni possibili (da enum): EIdRestrictDefault, ESendMyId, EDontSendMyId
        CTelephony::TCallerIdentityRestrict aRestinction = CTelephony::EIdRestrictDefault;
        CTelephony::TCallParamsV1 callParams;
        callParams.iIdRestrict = aRestinction;
        CTelephony::TCallParamsV1Pckg callParamsPckg(callParams);
        iState = ephoneCallDialing;

        iTelephony->DialNewCall(iStatus, callParamsPckg, telNumber, iCallId);
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
