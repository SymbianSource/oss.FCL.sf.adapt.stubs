/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Hardware Resource Manager stub plugins timer definition
*
*/



#ifndef __PLUGINTIMER_H_
#define __PLUGINTIMER_H_

#include <hwrmpluginservice.h>

/**
*  An interface for handling timer expiration events.
*/
class MPluginTimerCallback
    {
    public:
        /** 
        * Called when the timer fires
        */
        virtual void GenericTimerFired(MHWRMPluginCallback* aService,
                          TInt aCommandId,
                          TUint8 aTransId,
                         TInt aRetVal) = 0;
    };


class CPluginTimer : public CTimer
    {
    public:
        CPluginTimer(TInt aPriority, 
                   MHWRMPluginCallback* aService,
                    TInt aCommandId,
                    TUint8 aTransId,
                   TInt aRetVal,
                   MPluginTimerCallback* aCallback
                   );
        
        ~CPluginTimer();

        CPluginTimer(TInt aPriority);

        static CPluginTimer* NewL(const TTimeIntervalMicroSeconds32& anInterval, 
                         MHWRMPluginCallback* aService,
                          TInt aCommandId,
                          TUint8 aTransId,
                         TInt aRetVal,
                         MPluginTimerCallback* aCallback);
                         
        void ConstructL();
        
        void RunL();
        
        inline TUint8 TransId() const
            {
            return  iTransId;
            };
    
    private:
    
       MHWRMPluginCallback* iService;  // Not owned
        
       TInt iCommandId;
       TUint8 iTransId;
       TInt iRetVal;
       
       MPluginTimerCallback* iCallback;  // Not owned
    
    };


#endif // __PLUGINTIMER_H_