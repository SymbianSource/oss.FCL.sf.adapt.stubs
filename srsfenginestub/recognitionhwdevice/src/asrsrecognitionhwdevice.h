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
* Description:     HW Device for speech recognition
*
*/






#ifndef ASRSRECOGNITIONHWDEVICE_H
#define ASRSRECOGNITIONHWDEVICE_H

//  INCLUDES
#include <asrshwdevice.h>

// FORWARD DECLARATIONS
class CSDModelBank;
class CSIModelBank;
class CRecognitionAlgorithm;

// CLASS DECLARATION
/**
*  Observer for recognition HW device
*
*  @lib asrsrecognitionhwdevice.lib
*  @since 2.8
*/
class MASRSRecognitionHwDeviceObserver 
    {
        
    public: // New functions
        
        /**
        * Called by the hardware device when the InitializeL() method has completed.
        * @since 2.8
        * @param aError Initialization result code. 
        *               KErrNone if successful otherwise a system-wide error code.
        * @return none
        */
        virtual void MarhdoInitializationComplete( TInt aError ) = 0;

        /**
        * Called by the hardware device when the  InitializeL() method has completed.
        * @since 2.8
        * @param aError Initialization result code. 
        *               KErrNone if successful otherwise a system-wide error code.
        * @return none
        */
        virtual void MarhdoInitRecognizerFEComplete( TInt aError ) = 0;

        /**
        * Called by the hardware device when backend initialization is completed.
        * @since 2.8
        * @param aError Initialization result code. 
        *               KErrNone if successful otherwise a system-wide error code.
        * @return none
        */
        virtual void MarhdoInitRecognizerBEComplete( TInt aError ) = 0;

        /**
        * Called by the hardware device when recognition result is available.
        * @since 2.8
        * @param aError Recognition result code. KErrNone if successful.  
        *               KErrRejected if the recognition result is rejected, 
        *               otherwise a system-wide error code
        * @return none
        */ 
        virtual void MarhdoRecognitionComplete( TInt aError ) = 0;

        /**
        * Called by the hardware device when end-of-utterance is detected by the 
        * acoustic frontend. This method must be called before MarhdoRecognitionComplete().
        * @since 2.8
        * @param aError Recognition result code. KErrNone if successful, otherwise KErrTooLong, 
        *               KErrTooShort, KErrAsrSpeechTooEarly, KErrNoSpeech
        * @return none
        */
        virtual void MarhdoEouDetected( TInt aError ) = 0;

        /**
        * Called by the hardware device when a feature vector is extracted by acoustic frontend.
        * @since 2.8
        * @param aFV A buffer containing a feature vector.
        * @param aSNR Signal-to-noise ratio.
        * @param aPosition Indicates whether this is the first, subsequent or last feature vector in a series.
        * @return none
        */
        virtual void MarhdoFeatureVector( const TDesC8& aFV, TInt32 aSNR, TInt32 aPosition ) = 0;

        /**
        * Called by the hardware device to request for utterance data. 
        * The response to the request is sent in SendSpeechData().
        * @since 2.8
        * @param none
        * @return none
        */
        virtual void MarhdoRequestSpeechData () = 0;
    };

/**
*  Recognition HW Device
*
*  @lib asrsrecognitionhwdevice.lib
*  @since 2.8
*/
class CASRSRecognitionHwDevice : public CASRSHwDevice
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        */
        IMPORT_C static CASRSRecognitionHwDevice* NewL( MASRSRecognitionHwDeviceObserver& aObserver );
        
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CASRSRecognitionHwDevice();
        
    public: // New functions
        
        /**
        * This method initializes the backend of the recognition Hw device.
        * @since 2.8
        * @param aRecognitionData A recognition data generated by grammar compilation.
        * @param aModels A model bank containing acoustic models 
        * @return none
        */
        IMPORT_C void InitRecognizerBEL( const TDesC8& aRecognitionData, 
                               const CSIModelBank& aModels );

        /**
        * This method initialize the frontend of the recognition Hwdevice
        * @since 2.8
        * @param none
        * @return none
        */  
        IMPORT_C void InitRecognizerFEL( TBool aSendFeatureVectors = EFalse );

        /**
        * Sets the maximum number of entries wanted in the ranked list of recognition results. 
        * @since 2.8
        * @param aNBest The n-best number.
        * @return none
        */ 
    	IMPORT_C void SetNBest( TUint32 aNBest );
    	
    	/**
        * Sets the rejection threshold. 
        * @since 3.2
        * @param aRejection Rejection threshold value.
        * @return none
        */ 
    	IMPORT_C void SetRejection( TUint32 aRejection );
    	
    	/**
        * Gets the rejection threshold. 
        * @since 2.8
        * @param none
        * @return Rejection threshold value.
        */ 
    	IMPORT_C TUint32 GetRejection();

        /**
        * Start recognition
        * @since 2.8
        * @param aNBestList At the end of recognition, this object will contain Nbest list IDs.
        * @param aScore At the end of recognition, this object will contain scores for Nbest list.
        * @param aSendFeatureVectors ETrue send feature vector to client, EFalse do not send feature vector to client.
        * @return none
        */ 
        IMPORT_C void StartRecognitionL( RArray<TUint>& aNBestList, RArray<TInt>& aScore );

        /**
        * Stop a started recognition process.
        * @since 2.8
        * @param none
        * @return none
        */ 
        IMPORT_C void StopRecognition();
 
        /**
        * Use to send utterance data
        * @since 2.8
        * @param aBuffer Buffer containing utterance data.
        * @param aEnd End of utterance data indicator. ETrue indicates end of data or no data.
        * @return none
        */ 
        IMPORT_C void SendSpeechData( TPtrC8& aBuffer, TBool aEnd );
        
    public: // Functions from base classes

        /**
        * From CASRSHwDevice Use to initilize HW device
        * @since 2.8
        * @param none
        * @return none
        */
        IMPORT_C virtual void InitializeL();

        /**
        * From CASRSHwDevice Use to clear HW device
        * @since 2.8
        * @param none
        * @return none
        */
        IMPORT_C virtual void Clear();

		/**
        * From CASRSHwDevice Use to get custom interface
        * @since 2.8
        * @param aInterfaceId Identifier of the intercace implementation
        * @return Pointer to the interface implementation or NULL.
        */
        IMPORT_C virtual TAny* CustomInterface( TUid aInterfaceId );
               
    private:
        
        /**
        * C++ default constructor.
        */
        CASRSRecognitionHwDevice();
        
        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL( MASRSRecognitionHwDeviceObserver& aObserver );
                
    private:    // Data

        // Actual implementation of recognition
        CRecognitionAlgorithm* iRecAlgorithm;
        
        // Reserved pointer for future extension
        TAny* iReserved;
        
    };

#endif      // ASRSRECOGNITIONHWDEVICE  

// End of File