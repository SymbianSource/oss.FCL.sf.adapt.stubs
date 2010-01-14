/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:     HW device stub of NLP
*
*/





// INCLUDE FILES
#include    "asrsnlphwdevice.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CNlpHwDevice::CNlpHwDevice
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CNlpHwDevice::CNlpHwDevice():
	iAlgorithm( NULL ),
    iReserved( NULL )
    {
    // nothing
    }

// -----------------------------------------------------------------------------
// CNlpHwDevice::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CNlpHwDevice::ConstructL( MNlpHwDeviceObserver& /*aObserver*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CNlpHwDevice::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CNlpHwDevice* CNlpHwDevice::NewL( MNlpHwDeviceObserver& aObserver )
    {
    CNlpHwDevice* self = new( ELeave ) CNlpHwDevice;
    
    CleanupStack::PushL( self );
    self->ConstructL( aObserver);
    CleanupStack::Pop();

    return self;
    }
    
// -----------------------------------------------------------------------------
// CNlpHwDevice::~CNlpHwDevice
// Destructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CNlpHwDevice::~CNlpHwDevice()
	{
    }

// -----------------------------------------------------------------------------
// CNlpHwDevice::IsLanguageSupported
// Tells if given language is supported by NLP module or not.
// -----------------------------------------------------------------------------
//
EXPORT_C TBool CNlpHwDevice::IsLanguageSupported( TLanguage /*aLanguage*/ )
    {
    return EFalse;
    }

// -----------------------------------------------------------------------------
// CNlpHwDevice::NormalizeTextL
// Processes text.
// -----------------------------------------------------------------------------
//
EXPORT_C void CNlpHwDevice::NormalizeTextL( CTtsParsedText& /*aText*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CNlpHwDevice::NormalizeAndSegmentTextL
// Processes text and divides it to segments.
// -----------------------------------------------------------------------------
//    
EXPORT_C void CNlpHwDevice::NormalizeAndSegmentTextL( CTtsParsedText& /*aText*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CNlpHwDevice::NormalizeTextL
// Processes text.
// -----------------------------------------------------------------------------
//
EXPORT_C void CNlpHwDevice::NormalizeTextAsyncL( CTtsParsedText& /*aText*/ )
    {
    User::Leave( KErrNotSupported );
    }
    
// -----------------------------------------------------------------------------
// CNlpHwDevice::NormalizeAndSegmentTextL
// Processes text and divides it to segments.
// -----------------------------------------------------------------------------
//    
EXPORT_C void CNlpHwDevice::NormalizeAndSegmentTextAsyncL( CTtsParsedText& /*aText*/ )
    {
    User::Leave( KErrNotSupported );
    }

// ========================== OTHER EXPORTED FUNCTIONS =========================

// -----------------------------------------------------------------------------
// for DLL goodness
// -----------------------------------------------------------------------------
//

#ifndef EKA2
GLDEF_C TInt E32Dll( TDllReason )
{
	return KErrNone;
}
#endif

//  End of File  
