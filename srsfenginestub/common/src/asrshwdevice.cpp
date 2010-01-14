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
* Description:     Hardware device base class
*
*/






// INCLUDE FILES
#include    "asrshwdevice.h"

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CASRSHwDevice::CASRSHwDevice
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
CASRSHwDevice::CASRSHwDevice()
    {
    }

// -----------------------------------------------------------------------------
// CASRSHwDevice::ConstructL
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CASRSHwDevice::ConstructL()
    {
    }

// -----------------------------------------------------------------------------
// CASRSHwDevice::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSHwDevice* CASRSHwDevice::NewL()
    {
    CASRSHwDevice* self = new( ELeave ) CASRSHwDevice;
    
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }


// -----------------------------------------------------------------------------
// CASRSHwDevice::~CASRSHwDevice    
// Destructor
// -----------------------------------------------------------------------------
//
EXPORT_C CASRSHwDevice::~CASRSHwDevice()
    {
    
    }
 
// -----------------------------------------------------------------------------
// CASRSHwDevice::InitializeL()
// do nothing
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSHwDevice::InitializeL()
   {
   // nothing
   }

// -----------------------------------------------------------------------------
// CASRSHwDevice::Clear()
// do nothing
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C void CASRSHwDevice::Clear()
   {
   // nothing
   }

// -----------------------------------------------------------------------------
// CASRSHwDevice::CustomInterface()
// return empty interface
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C TAny* CASRSHwDevice::CustomInterface( TUid /*aInterfaceId*/ )
   {
   return NULL;
   }

