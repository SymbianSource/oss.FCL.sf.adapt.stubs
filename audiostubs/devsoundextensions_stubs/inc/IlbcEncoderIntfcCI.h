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


#ifndef ILBCENCODERINTFCCI_H
#define ILBCENCODERINTFCCI_H

// INCLUDES
#include <e32base.h>
#include <ilbcencoderintfc.h>

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
class CIlbcEncoderIntfcCI : public CIlbcEncoderIntfc
	{
    public:  // Constructors and destructor

        /**
        * Two-phased constructor.
        */
		IMPORT_C static CIlbcEncoderIntfcCI* NewL();

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CIlbcEncoderIntfcCI();

    public: // New functions

    public: // Functions from base classes

        /**
        * From ?base_class ?member_description.
        * @since Series ?XX ?SeriesXX_version
        * @param ?arg1
        * @return
        */
		IMPORT_C virtual TInt SetEncoderMode(TEncodeMode aEncodeMode);
		IMPORT_C virtual TInt SetVadMode(TBool aVadMode);
		IMPORT_C virtual TInt GetVadMode(TBool& aVadMode);

    protected:  // New functions

    protected:  // Functions from base classes

	private:

        /**
        * C++ default constructor.
        */
	    CIlbcEncoderIntfcCI();

        /**
        * By default Symbian 2nd phase constructor is private.
        */
	    void ConstructL();

    public:     // Data
    protected:  // Data
    private:    // Data
        TBool iVadMode;
    public:     // Friend classes
    protected:  // Friend classes
    private:    // Friend classes

	};

#endif      // ILBCENCODERINTFCCI_H

// End of File
