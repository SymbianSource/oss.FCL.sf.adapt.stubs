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
* Description:     Vocabulary handling stub functions.
*
*/






// INCLUDE FILES
#include    "asrsvocmanhwdevice.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::CASRSVocManHwDevice
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CASRSVocManHwDevice::CASRSVocManHwDevice()
: iVMAlgorithm( NULL )
    {
    }

// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CASRSVocManHwDevice::ConstructL()
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSVocManHwDevice* CASRSVocManHwDevice::NewL()
    {
    CASRSVocManHwDevice* self = new ( ELeave ) CASRSVocManHwDevice;
    
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }

    
// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::~CASRSVocManHwDevice
// Destructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSVocManHwDevice::~CASRSVocManHwDevice()
    {
    }


// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::AdaptL
// Updates given scores
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSVocManHwDevice::AdaptL( 
	const TSIRuleVariantID /*aCorrectRuleVariantID*/, 
	CSIRule& /*aRule*/ )
	{
    User::Leave( KErrNotSupported );
	}

// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::Prune
// Give information which items can be pruned
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TBool CASRSVocManHwDevice::Prune( 
	const CSIGrammar& /*aGrammar*/, 
	const TUint32 /*aMinNumber*/,
	RArray<TSIRuleVariantInfo>& /*aPrunedItems*/ )
	{
    return EFalse;
	}

// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::ComputeNRuleVariantsL
// Determine how many rule variants can be added to grammar
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSVocManHwDevice::ComputeNRuleVariantsL( 
	const CSIGrammar& /*aGrammar*/, 
	const TUint32 /*aTargetNRuleVariants*/, 
	const TUint32 /*aMaxNRuleVariants*/, 
	const RArray<TUint>& /*aNewRuleScores*/, 
	RArray<TUint>& /*aNNewRuleVariants*/, 
	TUint32& /*aNPrune*/ )
	{
    User::Leave( KErrNotSupported );
	}

// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::InitializeL
// Initializes the HW device.
// You only need this function, if you have called ClearL().
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
void CASRSVocManHwDevice::InitializeL()
    {
    User::Leave( KErrNotSupported );
    }

// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::Clear
// Clears the HW device.
// You don't need this function, destructor does the same better
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
void CASRSVocManHwDevice::Clear()
    {
    }

// -----------------------------------------------------------------------------
// CASRSVocManHwDevice::CustomInterface
// Returns a custom interface. None implemented yet.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
TAny* CASRSVocManHwDevice::CustomInterface(TUid /*aInterfaceUid*/)
    {
    return( NULL );
    }

// ========================== OTHER EXPORTED FUNCTIONS =========================

// for DLL goodness
#ifndef EKA2
GLDEF_C TInt E32Dll( TDllReason /*aReason*/ )
    {
    return KErrNone;
    }
#endif


//  End of File  
