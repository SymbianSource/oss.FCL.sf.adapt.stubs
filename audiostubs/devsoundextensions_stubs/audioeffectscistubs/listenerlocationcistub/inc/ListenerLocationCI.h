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
* Description: Audio Stubs -  This is the definition of the bassboost Custom Interface class.
*				 This serves as an example of how adaptation might define the
*				 custom interface class.
*				 The CListenerLocationCI object is typically instantiated by a DevSound
*                instance and return to the client when the CustomInterface()
*				 method is invoked.
*
*
*/


#include <ListenerLocationBase.h>
#include <MListenerLocationObserver.h>

class CMMFDevSound;

class CListenerLocationCI : public CListenerLocation
	{
	public: // Constructor and Destructor

        /**
        * Two-phased constructor.
        */
		IMPORT_C static CListenerLocationCI* NewL(CMMFDevSound& aDevSound);

        /**
        * Destructor.
        */
		virtual ~CListenerLocationCI();

 	public: // From Base Class

		/**
		* From CAudioEffect
        * Apply effect settings
        * @since 3.0
        */
        virtual void ApplyL();

		IMPORT_C static CListenerLocationCI* NewL();

	private:

        /**
        * C++ default constructor.
        */
        CListenerLocationCI(CMMFDevSound& aDevSound);
        CListenerLocationCI();

	private: // Data

		CMMFDevSound* iDevSound;
	};
