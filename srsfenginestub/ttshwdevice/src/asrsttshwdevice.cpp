/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:     Stub algorithms for Speech Synthesis
*
*/





// INCLUDE FILES
#include    "asrsttshwdevice.h"
#include    <e32svr.h>

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CTtsHwDevice::CTtsHwDevice
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CTtsHwDevice::CTtsHwDevice(): iAlgorithm( NULL ), iReserved( NULL )
    {
    // nothing
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CTtsHwDevice::ConstructL( MTtsHwDeviceObserver& /*aObserver*/,
                               TUint /*aSamplingRate*/, 
                               TUint /*aBufferSize*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CTtsHwDevice* CTtsHwDevice::NewL( MTtsHwDeviceObserver& aObserver,
                                           TUint aSamplingRate, 
                                           TUint aBufferSize )
    {
    CTtsHwDevice* self = new ( ELeave ) CTtsHwDevice;
    
    CleanupStack::PushL( self );
    self->ConstructL( aObserver, aSamplingRate, aBufferSize );
    CleanupStack::Pop();

    return self;
    }

    
// -----------------------------------------------------------------------------
// CTtsHwDevice::~CTtsHwDevice
// Destructor;
// -----------------------------------------------------------------------------
//
EXPORT_C CTtsHwDevice::~CTtsHwDevice()
	{
    }


// -----------------------------------------------------------------------------
// CTtsHwDevice::AddStyleL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TTtsStyleID CTtsHwDevice::AddStyleL( const TTtsStyle& /*aStyle*/ )
    {
    User::Leave( KErrNotSupported );
    return 0;
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::AnalyzeProsodyL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::AnalyzeProsodyL( CTtsParsedText& /*aText*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::AnalyzeStructureL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::AnalyzeStructureL( CTtsParsedText& /*aText*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::BufferProcessed
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::BufferProcessed( const TDesC8& /*aBuffer*/ )
    {
    }


// -----------------------------------------------------------------------------
// CTtsHwDevice::DeleteStyleL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::DeleteStyleL( TTtsStyleID /*aStyleID*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::GetPositionL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::GetPositionL( TTimeIntervalMicroSeconds& /*aTime*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::GetPositionL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::GetPositionL( TTtsSegment& /*aSegment*/, 
                                          TInt& /*aWordIndex*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::IsLanguageSupported
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TBool CTtsHwDevice::IsLanguageSupported( TLanguage /*aLanguage*/ )
    {
    return EFalse;
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::NumberOfStyles
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TUint16 CTtsHwDevice::NumberOfStyles() const
    {
    return 0;
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::Pause
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::Pause()
    {
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::PrimeSynthesisL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::PrimeSynthesisL( MTtsSegmentStream& /*aStream*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::PrimeSynthesisL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::PrimeSynthesisL( CTtsParsedText& /*aText*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::SetPositionL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::SetPositionL( const TTimeIntervalMicroSeconds& /*aTime*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::SetPositionL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::SetPositionL( const TTtsSegment& /*aSegment*/,
                                          TInt /*aWordIndex*/ )
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::Stop
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::Stop()
    {
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::StyleL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TTtsStyle& CTtsHwDevice::StyleL( TTtsStyleID /*aStyleID*/ )
    {
    User::Leave( KErrNotSupported );
    // Just for removing errors & warning, we never get here
    TInt* dummy = new ( ELeave ) TInt;
    TTtsStyle* style = (TTtsStyle*) dummy;
    return *style;    
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::StyleL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TTtsStyle& CTtsHwDevice::StyleL( TUint16 /*aIndex*/ )
    {
    User::Leave( KErrNotSupported );
    // Just for removing errors & warning, we never get here
    TInt* dummy = new ( ELeave ) TInt;
    TTtsStyle* style = (TTtsStyle*) dummy;
    return *style;
    }

// -----------------------------------------------------------------------------
// CTtsHwDevice::SynthesizeL
// Calls responding function of TTS algorithm
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CTtsHwDevice::SynthesizeL()
    {
    User::Leave( KErrNotSupported );
    }

// ========================== OTHER EXPORTED FUNCTIONS =========================

// -----------------------------------------------------------------------------
// for DLL goodness
// -----------------------------------------------------------------------------
//
#ifndef EKA2
GLDEF_C TInt E32Dll( TDllReason /*aReason*/ )
    {
    return KErrNone;
    }
#endif

//  End of File  
