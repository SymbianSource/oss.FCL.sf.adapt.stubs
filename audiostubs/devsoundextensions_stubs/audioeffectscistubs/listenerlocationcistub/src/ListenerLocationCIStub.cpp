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
* Description: Audio Stubs -  Implementation of the bassboost effect Custom Interface class
*
*/


#ifdef _DEBUG
#include <e32svr.h> // Needed for RDebug Prints
#endif

#include "ListenerLocationCI.h"
#include <sounddevice.h>

// -----------------------------------------------------------------------------
// CListenerLocation::NewL
// Static function for creating an instance of the CListenerLocationCI object.
// -----------------------------------------------------------------------------
//

EXPORT_C CListenerLocationCI* CListenerLocationCI::NewL(
	CMMFDevSound& aDevSound )
	{
	CListenerLocationCI* self = new(ELeave) CListenerLocationCI(aDevSound);
	return self;
	}

CListenerLocationCI::CListenerLocationCI(
	CMMFDevSound& aDevSound )
	:	iDevSound(&aDevSound)
	{
	iLocationData.iXCoordinate = 10;
	iLocationData.iYCoordinate = 10;
	iLocationData.iZCoordinate = 10;
	iLocationData.iAzimuth = 10;
	iLocationData.iElevation = 10;
	iLocationData.iRadius = 10;
	}

// -----------------------------------------------------------------------------
// CListenerLocation::NewL
// Static function for creating an instance of the CListenerLocationCI object.
// -----------------------------------------------------------------------------
//

EXPORT_C CListenerLocationCI* CListenerLocationCI::NewL()
	{
	CListenerLocationCI* self = new(ELeave) CListenerLocationCI();
	return self;
	}

CListenerLocationCI::CListenerLocationCI()
	{
	iLocationData.iXCoordinate = 10;
	iLocationData.iYCoordinate = 10;
	iLocationData.iZCoordinate = 10;
	iLocationData.iAzimuth = 10;
	iLocationData.iElevation = 10;
	iLocationData.iRadius = 10;
	}

// Destructor

CListenerLocationCI::~CListenerLocationCI()
	{
#ifdef _DEBUG
    RDebug::Print(_L("CListenerLocationCI::~CListenerLocationCI"));
#endif
	}

// -----------------------------------------------------------------------------
// CListenerLocationCI::ApplyL
//
// Applies the bassboost settings.
// Adaptation must check each settings and take appropriate actions since
// this method might be called after several settings have been made.
// -----------------------------------------------------------------------------
//
void CListenerLocationCI::ApplyL()
	{
#ifdef _DEBUG
    RDebug::Print(_L("CListenerLocationCI::ApplyL"));
#endif

	if ( !HaveUpdateRights() )
		{
		User::Leave(KErrAccessDenied);
		}

	if ( IsEnabled() )
		{
		}

	// The effect change event is simulated by changing the bassboost and
	// sending the observer a message indicating bassboost has changed.
	// This is done for testing only.

	// The intention of this callback is to notify the observer when the bassboost
	// object changes spontaneously. ie the user did not change the settings but
	// event somewhere in the system causes the bassboost object to change state.

	if (iObservers.Count() > 0)
		{
		iObservers[0]->EffectChanged(this, (TUint8)MListenerLocationObserver::KSpecificEffectBase);
		}
	}


// ========================== OTHER EXPORTED FUNCTIONS =========================


// End of File
