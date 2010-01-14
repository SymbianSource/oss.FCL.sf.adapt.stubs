/*
* Copyright (c) 2004-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:     TTP hardware device stub.
*
*/





// INCLUDE FILES
#include "srsfenginestubbldvariant.hrh"
#include "asrsttphwdevice.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::CASRSTtpHwDevice
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CASRSTtpHwDevice::CASRSTtpHwDevice( MASRSTtpHwDeviceObserver& aObserver ) : 
	iObserver( aObserver ),
	iTTPAlgorithm( NULL ), 
	iTTPAlgObserver( NULL )
    {
    }

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CASRSTtpHwDevice::ConstructL()
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSTtpHwDevice* CASRSTtpHwDevice::NewL( MASRSTtpHwDeviceObserver& aObserver )
    {
    CASRSTtpHwDevice* self = new( ELeave ) CASRSTtpHwDevice( aObserver );
    
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::~CASRSTtpHwDevice
// Destructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSTtpHwDevice::~CASRSTtpHwDevice()
    {
    }


// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::InitializeL
// Initialize TTP module
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSTtpHwDevice::InitializeL()
	{
    User::Leave( KErrNotSupported );
	}

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::ConvertTextL
// Perform TTP for text.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C HBufC8* CASRSTtpHwDevice::ConvertTextL( const TDesC& /*aText*/, 
                                                 TLanguage& /*aLanguage*/ )
	{
    User::Leave( KErrNotSupported );
    return NULL;
	}

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::ConvertWordListL
// Perform TTP for word list. Asynchronous.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSTtpHwDevice::ConvertWordListL( CSITtpWordList& /*aWordList*/,
								                 const RArray<TLanguage> /*aDefaultLanguage*/,
								                 const RArray<TUint32> /*aMaxNPronunsForWord*/ )
	{
    User::Leave( KErrNotSupported );
	}

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::CancelWordListConversion
// Cancel TTP for word list.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSTtpHwDevice::CancelWordListConversion()
    {
    }


// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::SetPhonemeNotationL
// Sets the output phoneme notation.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSTtpHwDevice::SetPhonemeNotationL( const TDesC& /*aNotation*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::PhonemeNotation
// Returns the phoneme notation in use.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C const TDesC& CASRSTtpHwDevice::PhonemeNotation()
    {
    _LIT( KError, "Error" );
    return KError;
    }

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::Clear
// Clears HW Device.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSTtpHwDevice::Clear()
    {
    }

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::CustomInterface
// Returns pointer to wanted custom interface. Returns NULL pointer if not found.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TAny* CASRSTtpHwDevice::CustomInterface( TUid /*aInterfaceId*/ )
    {
    return NULL;
    }

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::WordListReady
// Notify that word list is ready
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//	
void CASRSTtpHwDevice::WordListReady( const TInt /*aError*/ )
	{
	}

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::ConfigurationData
// Notify that configuration data is needed.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
HBufC8* CASRSTtpHwDevice::ConfigurationData( TUint32 /*aPackageType*/, 
                                             TUint32 /*aPackageID*/,
                                             TUint32 /*aStartPosition*/,
                                             TUint32 /*aEndPosition*/ )
    {
    return NULL;
    }

// -----------------------------------------------------------------------------
// CASRSTtpHwDevice::LanguageIdentificationL
// Tries to guess the language of given text.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSTtpHwDevice::LanguageIdentificationL( const TDesC& /*aText*/,
                                                         TInt /*aNumberOfGuesses*/,
                                                         RArray<TLanguage>& /*aLanguages*/,
                                                         RArray<TInt>& /*aScores*/ )
    {
    User::Leave( KErrNotSupported );
    }


// ========================== OTHER EXPORTED FUNCTIONS =========================

// For DLL goodness
#ifndef EKA2
GLDEF_C TInt E32Dll( TDllReason /*aReason*/ )
    {
    return KErrNone;
    }
#endif


//  End of File  
