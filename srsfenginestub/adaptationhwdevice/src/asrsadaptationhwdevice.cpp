/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:     SIND hardware device for model adaptation
*
*/






// INCLUDE FILES
#include "asrsadaptationhwdevice.h"


// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CASRSAdaptHwDevice::CASRSAdaptHwDevice
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//

CASRSAdaptHwDevice::CASRSAdaptHwDevice(
    MASRAdaptationHwDeviceObserver& anObserver
    )
: iObserver( anObserver ),
  iAlgorithm( NULL ),
  iIsInitialised( EFalse ),
  iReserved( 0 )
    {
    // Nothing
    }

// -----------------------------------------------------------------------------
// CASRSAdaptHwDevice::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CASRSAdaptHwDevice::ConstructL(void)
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSAdaptHwDevice::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSAdaptHwDevice* CASRSAdaptHwDevice::NewL(
     MASRAdaptationHwDeviceObserver& anObserver ) // The observer
    {
    CASRSAdaptHwDevice* self = new( ELeave ) CASRSAdaptHwDevice( anObserver );
    
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }

    
// -----------------------------------------------------------------------------
// CASRSAdaptHwDevice::~CASRSAdaptHwDevice
// Destructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSAdaptHwDevice::~CASRSAdaptHwDevice()
    {
    }

// ========================== OTHER EXPORTED FUNCTIONS =========================

// -----------------------------------------------------------------------------
// CustomInterface
// Provides clients with an interface, given an UID.
// Returns: NULL - No custom interface with that UID
// -----------------------------------------------------------------------------
//
EXPORT_C TAny* CASRSAdaptHwDevice::CustomInterface(
    TUid /*aInterfaceId*/ ) // UID of the interface
    {
    return NULL;
    }

// -----------------------------------------------------------------------------
// InitializeL
// Initializes the device. Subsequent calls reset the device.
// Returns: none
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSAdaptHwDevice::InitializeL(void)
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// Clear
// Clears the device
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSAdaptHwDevice::Clear(void)
    {
    }

// -----------------------------------------------------------------------------
// Start the adaptation.  It will adapt the acoustic models given the feature vector set and phoneme sequences 
// of a correctly recognized utterance
//  
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSAdaptHwDevice::StartAdaptationL ( const TDesC8& /*aAdaptationData*/,
                                                     CSIModelBank& /*aModelBank*/, 
                                                     CSIPronunciation& /*aPronunciation*/,
                                                     TLanguage /*aLanguage*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CancelAdaptation
// Cancels Adaptation  . No callback is sent to the client.
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSAdaptHwDevice::CancelAdaptation()
    {
    }

 
  
// ================================ OTHER EXPORTED FUNCTIONS ===============================

// for DLL goodness
#ifndef EKA2
GLDEF_C TInt E32Dll( TDllReason /*aReason*/ )
    {
    return KErrNone;
    }
#endif


//  End of File  
