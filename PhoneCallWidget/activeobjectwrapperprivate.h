#ifndef ACTIVEOBJECTWRAPPERPRIVATE_H
#define ACTIVEOBJECTWRAPPERPRIVATE_H

#include "etel3rdparty.h"
#include "e32base.h"

class QString;
class ActiveObjectWrapper;

class ActiveObjectWrapperPrivate : public CActive
{

enum ePhoneCallStates
{
      ephoneCallIdle,
      ephoneCallDialing,
      ephoneCallHangingup,
      ephoneCallAnswering
};

public:
    ActiveObjectWrapperPrivate(ActiveObjectWrapper *wrapper);

    /**
    * RequestManufacturer
    * Requests phone id.
    */
    void RequestManufacturer();

    void DialTelephoneNumber(QString phoneNumber);

private:
    /**
    * CreateCTelephony
    * Ensures that iTelephony instance exists before called.
    * @return error code
    */
    int CreateCTelephony();

    /**
    * RunL
    * Called when the scheduled function ends.
    */
    void RunL();

    /**
    * DoCancel
    * Cancels operations.
    */
    void DoCancel();


    /**
  * q_ptr pointer to AOWrapper
  * Owned by AOWrapperPrivate object, instantiated in
  * constructor.
  */
  ActiveObjectWrapper *q_ptr;

  /**
    * iTelephony the telephony whos manufacturer is requested
    * Owned by AOWrapperPrivate object, instantiated in
    * constructor.
    */
    CTelephony *iTelephony;

    /**
    * iPhoneIdV1 stores the mobile phone identity information
    */
    CTelephony::TPhoneIdV1 iPhoneIdV1;

    /**
    * iPhoneIdV1Pckg packages iPhoneIdV1.
    */
    CTelephony::TPhoneIdV1Pckg iPhoneIdV1Pckg;

    CTelephony::TCallId iCallId;
    ePhoneCallStates iState;

};

#endif // ACTIVEOBJECTWRAPPERPRIVATE_H
