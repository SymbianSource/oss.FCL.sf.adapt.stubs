/*
* Copyright (c) 2002-2008 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: Audio Stubs -
*
*/


#ifndef G711DECODERINTFCCI_H
#define G711DECODERINTFCCI_H

// INCLUDES
#include <e32base.h>
#include <G711DecoderIntfc.h>

// CONSTANTS

// MACROS

// DATA TYPES

// FUNCTION PROTOTYPES

// FORWARD DECLARATIONS

// CLASS DECLARATION

/**
*  ?one_line_short_description.
*  ?other_description_lines
*
*  @lib ?library
*  @since Series ?XX ?SeriesXX_version
*/
class CG711DecoderIntfcCI : public CG711DecoderIntfc
	{
    public:  // Constructors and destructor

        /**
        * Two-phased constructor.
        */
		IMPORT_C static CG711DecoderIntfcCI* NewL();

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CG711DecoderIntfcCI();

    public: // New functions

    public: // Functions from base classes

        /**
        * From ?base_class ?member_description.
        * @since Series ?XX ?SeriesXX_version
        * @param ?arg1
        * @return
        */
		IMPORT_C virtual TInt SetDecoderMode(TDecodeMode aDecodeMode);
		IMPORT_C virtual TInt SetCng(TBool aCng);
		IMPORT_C virtual TInt GetCng(TBool& aCng);
		IMPORT_C virtual TInt SetPlc(TBool aPlc);

    protected:  // New functions

    protected:  // Functions from base classes

	private:

        /**
        * C++ default constructor.
        */
	    CG711DecoderIntfcCI();

        /**
        * By default Symbian 2nd phase constructor is private.
        */
	    void ConstructL();

    public:     // Data
    protected:  // Data
    private:    // Data
        TBool iCng;
    public:     // Friend classes
    protected:  // Friend classes
    private:    // Friend classes

	};

#endif      // G711DECODERINTFCCI_H

// End of File
