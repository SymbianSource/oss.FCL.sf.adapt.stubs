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
* Description:     ARM hardware device for grammar compiling
*
*/






// INCLUDE FILES
#include    "asrsgrcompilerhwdevice.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CASRSGrCompilerHwDevice::CASRSGrCompilerHwDevice
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CASRSGrCompilerHwDevice::CASRSGrCompilerHwDevice(
    MASRSGrCompilerHwDeviceObserver& anObserver
    )
: iObserver( anObserver ),
  iAlgorithm( NULL ),
  iIsInitialised( EFalse ),
  iReserved( 0 )
    {
    // Nothing
    }

// -----------------------------------------------------------------------------
// CASRSGrCompilerHwDevice::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CASRSGrCompilerHwDevice::ConstructL(void)
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSGrCompilerHwDevice::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSGrCompilerHwDevice* CASRSGrCompilerHwDevice::NewL(
    MASRSGrCompilerHwDeviceObserver& anObserver ) // The observer
    {
    CASRSGrCompilerHwDevice* self = new( ELeave ) CASRSGrCompilerHwDevice( anObserver );
    
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }

    
// -----------------------------------------------------------------------------
// ~CASRSGrCompilerHwDevice
// Destructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSGrCompilerHwDevice::~CASRSGrCompilerHwDevice()
    {
    }

// -----------------------------------------------------------------------------
// CustomInterface
// Provides clients with an interface, given an UID.
// Returns: NULL - No custom interface with that UID
// -----------------------------------------------------------------------------
//
EXPORT_C TAny* CASRSGrCompilerHwDevice::CustomInterface(
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
EXPORT_C void CASRSGrCompilerHwDevice::InitializeL(void)
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// ClearL
// Clears the device
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSGrCompilerHwDevice::ClearL(void)
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// Compiles a speaker independent grammar.
// Clears the device
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSGrCompilerHwDevice::CompileGrammarL(
    CSICompiledGrammar& /*aSICompiledGrammar*/ ) // The grammar
     
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// Compiles a speaker independent grammar.
// Clears the device
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSGrCompilerHwDevice::CombineGrammarL(
    const RPointerArray<CSICompiledGrammar>& /*aCompiledGrammars*/, // The grammars
    const RPointerArray<TSIRuleVariantInfo>& /*aExcludedRules*/) // Blacklisted variants
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CancelCompilation
// Cancels grammar compilation. No callback is sent to the client.
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSGrCompilerHwDevice::CancelCompilation()
    {
    }

// -----------------------------------------------------------------------------
// CancelCombination
// Cancels grammar combination. No callback is sent to the client.
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSGrCompilerHwDevice::CancelCombination()
    {
    }

// -----------------------------------------------------------------------------
// Resolves a recognition result
// Clears the device
// Returns: None
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSGrCompilerHwDevice::ResolveResult(
    const RArray<TUint>& /*aNBestIDs*/,
    CSIResultSet& /*aSIResultSet*/,
    const RPointerArray<CSICompiledGrammar>& /*aSICompiledGrammar*/,
    const TDesC8& /*aCombinedData*/
    ) const
    {
    }


// ================================ OTHER EXPORTED FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// E32Dll
// DLL entry function
// -----------------------------------------------------------------------------
//
#ifndef EKA2
GLDEF_C TInt E32Dll( TDllReason /*aReason*/ )
    {
    return KErrNone;
    }
#endif


//  End of File  
