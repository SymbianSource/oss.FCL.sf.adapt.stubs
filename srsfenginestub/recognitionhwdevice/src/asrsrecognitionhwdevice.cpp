/*
* Copyright (c) 2004-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:     Recognition HW device
*
*/





// INCLUDE FILES
#include "asrsrecognitionhwdevice.h"
#include <nsssispeechrecognitiondatadevasr.h>


// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::CASRSRecognitionHwDevice
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CASRSRecognitionHwDevice::CASRSRecognitionHwDevice()
 : iRecAlgorithm( NULL ),
   iReserved( NULL )
    {
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CASRSRecognitionHwDevice::ConstructL(
    MASRSRecognitionHwDeviceObserver& /*aObserver*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSRecognitionHwDevice* CASRSRecognitionHwDevice::NewL(
    MASRSRecognitionHwDeviceObserver& aObserver )
    {
    CASRSRecognitionHwDevice* self = new( ELeave ) CASRSRecognitionHwDevice;
    
    CleanupStack::PushL( self );
    self->ConstructL( aObserver );
    CleanupStack::Pop();
    
    return self;
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::~CASRSRecognitionHwDevice
// Destructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSRecognitionHwDevice::~CASRSRecognitionHwDevice()
    {
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::InitRecognizerBEL
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::InitRecognizerBEL( 
    const TDesC8& /*aRecognitionData*/, 
    const CSIModelBank& /*aModels*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::InitRecognizerFEL
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::InitRecognizerFEL(
    TBool /*aSendFeatureVectors*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::SetNBest
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::SetNBest( 
    TUint32 /*aNBest*/ )
    {
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::StartRecognitionL
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::StartRecognitionL( 
    RArray<TUint>& /*aNBestList*/, 
    RArray<TInt>&  /*aScore*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::StopRecognition
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::StopRecognition()
    {
    }
 
// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::SendSpeechData
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::SendSpeechData( 
    TPtrC8& /*aBuffer*/, 
    TBool /*aEnd*/ )
    {
    }
        

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::InitializeL
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::InitializeL()
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::Clear
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::Clear()
    {
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::CustomInterface
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TAny* CASRSRecognitionHwDevice::CustomInterface(
    TUid /*aInterfaceId*/ )
    {
    return NULL;
    }

// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::SetRejection
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSRecognitionHwDevice::SetRejection( TUint32 /*aRejection*/ )
    {
    }
    	
// -----------------------------------------------------------------------------
// CASRSRecognitionHwDevice::GetRejection
// Calls equivalent function of CRecognitionAlgorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TUint32 CASRSRecognitionHwDevice::GetRejection()
    {
    return 0;
    }

// End of File  
