/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Command handler for SSY <--> Sensor messages
*
*/


#include <e32property.h>
#include "ssyreferencecmdhandler.h"
#include "ssyreferencecontrol.h"
#include "ssyreferencechannel.h"
#include "ssyreferencetrace.h"

#ifdef	DSG
#include <u32exec.h>
#include <e32uid.h>
#define	SystemCategory	KUidSystemCategory
#define	EmulatorOrientationKey	KSystemEmulatorOrientationKey
#endif	// DSG

// ======== CONSTANTS ========
const TInt KSsyRefShortDelay = 100; 

// ======== MEMBER FUNCTIONS ========

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler C++ constructor
// ---------------------------------------------------------------------------
//
CSsyReferenceCmdHandler::CSsyReferenceCmdHandler( CSsyReferenceChannel& aSsyChannel ) :
    CActive( EPriorityNormal ),
    iSsyChannel( aSsyChannel )
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::CSsyReferenceCmdHandler()" ) ) );
    CActiveScheduler::Add( this );
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::CSsyReferenceCmdHandler() - return" ) ) );
    }


// ---------------------------------------------------------------------------
// Symbian 2nd phase constructor
// ---------------------------------------------------------------------------
//
void CSsyReferenceCmdHandler::ConstructL()
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::ConstructL()" ) ) );
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::ConstructL() - return" ) ) );
    }


// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::NewL
// ---------------------------------------------------------------------------
//
CSsyReferenceCmdHandler* CSsyReferenceCmdHandler::NewL( CSsyReferenceChannel& aSsyChannel )
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::NewL()" ) ) );
    CSsyReferenceCmdHandler* self = new ( ELeave ) CSsyReferenceCmdHandler( aSsyChannel );
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop( self );
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::NewL() - return" ) ) );
    return self;
    }

// ---------------------------------------------------------------------------
// Destructor
// ---------------------------------------------------------------------------
//
CSsyReferenceCmdHandler::~CSsyReferenceCmdHandler()
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::~CSsyReferenceCmdHandler()" ) ) );

    if ( iMessage )
        {
        // Send ProcessResponse
        iMessage->SetError( KErrCancel );
        iSsyChannel.ProcessResponse( iMessage );
        delete iMessage;
        iMessage = NULL;
        }

#ifdef	DSG
    if ( iPsListener )
        {
        iPsListener->Cancel();
        delete iPsListener;
        iPsListener = NULL;
        }
#endif	// DSG

    if ( iTimer )
        {
        iTimer->Cancel();
        delete iTimer;
        }

    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::~CSsyReferenceCmdHandler() - return" ) ) );
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::ProcessCommand
// ---------------------------------------------------------------------------
//
TInt CSsyReferenceCmdHandler::ProcessCommand( TSsyReferenceMsg aMessage )
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::ProcessCommand()" ) ) );
    TInt err( KErrAlreadyExists );
    
    // Special case, when channel is reciving, iMessage is not deleted after ProcessCommand
    if ( aMessage.Function() == ESsyReferenceStopChannelData )
        {
        // Stop 'receiving'. No need to handle this asynchronously
        if ( iTimer )
            {
            iTimer->Cancel();
            delete iTimer;
            iTimer = NULL;
            }

#ifdef	DSG
		if ( iPsListener )
			{
			iPsListener->Cancel();
			delete iPsListener;
			iPsListener = NULL;
			}
#endif	// DSG

        iDataItemArray.Reset();
        iDataItemPtr = 0;
        err = KErrNone;
        // No need to send ProcessResponse either
        delete iMessage;
        iMessage = NULL;
        }
    else if ( !iMessage )
        {
        TRAP(err, iMessage = new ( ELeave ) TSsyReferenceMsg( aMessage ));
        COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::ProcessCommand() - error %d creatig TSsyReferenceMsg" ), err ) );

        switch( aMessage.Function() )
            {
            case ESsyReferenceStartChannelData:
                {
                // Get channel data items and start 'receiving'
                IssueRequest();
                err = KErrNone;
                break;
                }
            case ESsyReferenceOpenChannel:
                {
                // Open channel specific handling here
                IssueRequest();
                err = KErrNone;
                break;
                }
            case ESsyReferenceCloseChannel:
                {
                // Close channel specific handling here
                IssueRequest();
                err = KErrNone;
                break;  
                }
            default:
                {
                COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::ProcessCommand() - Unknown function" ) ) );
                err = KErrNotFound;
                }
            }
        }
    else
        {
        err = KErrUnknown;
        }
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::ProcessCommand() - return" ) ) );
    return err;
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::IssueRequest
// ---------------------------------------------------------------------------
//
void CSsyReferenceCmdHandler::IssueRequest( TInt aError )
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::IssueRequest()" ) ) );
    // Provides synchronous function calls to be handled as asynchronous
    if ( !IsActive() )
        {
        TRequestStatus *s = &iStatus;
	    User::RequestComplete( s, aError );
	    SetActive();
        }
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::IssueRequest() - return" ) ) );
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::SendResponse
// ---------------------------------------------------------------------------
//
void CSsyReferenceCmdHandler::SendResponse( TInt aError )
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::SendResponse()" ) ) );
    // Send response to channel
    if ( iMessage )
        {
        iMessage->SetError( aError );
        iSsyChannel.ProcessResponse( iMessage );
        delete iMessage;
        iMessage = NULL;
        }
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::SendResponse() - return" ) ) );
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::RunL
// ---------------------------------------------------------------------------
//
void CSsyReferenceCmdHandler::RunL()
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::RunL() - %i" ), iStatus.Int() ) );
    
    TInt err( iStatus.Int() );

    if ( iMessage )
        {
        switch( iMessage->Function() )
            {
            case ESsyReferenceStartChannelData:
                {
                TInt startInterval( 0 );
                
                // Get all Channel data information from config file
                iSsyChannel.SsyControl().SsyConfig().
                    GetChannelDataInformationL( iMessage->ChannelId(), iDataItemArray, startInterval );

                // Check that channel data items were found
                if ( iDataItemArray.Count() )
                    {
                    // If interval is zero, set small interval
                    if ( startInterval == 0 )
                        {
                        startInterval = KSsyRefShortDelay;
                        }

                    // wait that interval
                    if ( iTimer )
                        {
                        iTimer->Cancel();
                        delete iTimer;
                        iTimer = NULL;
                        }

                    // Reset pointer
                    iDataItemPtr = 0;


                    // Start timer and continue processing in callback function
                    iTimer = CPeriodic::NewL( EPriorityNormal );
#ifndef	DSG
                    iTimer->Start( startInterval * 1000, 0, TCallBack( DataItemCallback, this ) );
#else
					User::JustInTime();
                    if (startInterval > 0)
                    	{
						iTimer->Start(startInterval * 1000, 0, TCallBack(DataItemCallback, this));
						}
					else
						{
						// Register to receive property updates ...
						if (!iPsListener)
							iPsListener = CSsyPsListener::NewL(*this, SystemCategory, EmulatorOrientationKey);
						if (iPsListener)
							{
							// Respond to the inital value of the property, if it exists
							static TInt initialValue;
							if (RProperty::Get(SystemCategory, EmulatorOrientationKey, initialValue) == KErrNone)
								PsValueSet(SystemCategory, EmulatorOrientationKey, initialValue);
							}
						}
#endif	// DSG
                    }
                break;
                }
            case ESsyReferenceOpenChannel:
                {
                // Open channel response specific handling here
                iMessage->SetFunction( ESsyReferenceOpenChannelResp );
                SendResponse();
                break;
                }
            case ESsyReferenceCloseChannel:
                {
                // Close channel response specific handling here
                iMessage->SetFunction( ESsyReferenceCloseChannelResp );
                SendResponse();
                break;  
                }
            default:
                {
                COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::ProcessCommand() - Unknown function" ) ) );
                err = KErrNotFound;
                }
            }
        }

    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::RunL() - return" ) ) );
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::DoCancel
// ---------------------------------------------------------------------------
//
void CSsyReferenceCmdHandler::DoCancel()
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::DoCancel()" ) ) );

    // Handle cancel for this channel. Cancel any ongoing requests
    
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::DoCancel() - return" ) ) );
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::RunError
// ---------------------------------------------------------------------------
//
TInt CSsyReferenceCmdHandler::RunError( TInt /*aError*/ )
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::RunError()" ) ) );

    // Handle possible errors here and return KErrNone to prevent SSY from panic
    
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::RunError() - return" ) ) );
    return KErrNone;
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::DataItemCallback
// ---------------------------------------------------------------------------
//
TInt CSsyReferenceCmdHandler::DataItemCallback( TAny* aThis )
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::DataItemCallback()" ) ) );
    return static_cast<CSsyReferenceCmdHandler*>( aThis )->GenerateChannelDataItem();
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::GenerateChannelDataItem
// ---------------------------------------------------------------------------
//
TInt CSsyReferenceCmdHandler::GenerateChannelDataItem()
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::GenerateChannelDataItem()" ) ) );

    // Get next item from list and set pointer to next item
    TSsyRefChannelDataBase dataItem = iDataItemArray[iDataItemPtr++];

    // Get next item interval from data item
    TInt nextInterval( dataItem.Interval() );

    // Set timestamp to data item
    TTime time;
    time.HomeTime();
    dataItem.SetTimestamp( time );

    // If interval is zero, set small interval
    if ( nextInterval == 0 )
        {
        nextInterval = KSsyRefShortDelay;
        }

    // Add data item to message
    iMessage->SetDataItem( &dataItem );

    // If in last data item, set pointer back to first item
    if ( iDataItemArray.Count() == iDataItemPtr )
        {
        iDataItemPtr = 0;
        }

    // Send response and start new timer
    iMessage->SetFunction( ESsyReferenceDataItemReceived );
    iSsyChannel.ProcessResponse( iMessage );

    if ( iTimer )
        {
        delete iTimer;
        iTimer = NULL;
        }

    TRAP_IGNORE( iTimer = CPeriodic::NewL( EPriorityNormal );
                 iTimer->Start( nextInterval * 1000, 0, TCallBack( DataItemCallback, this ) ); )

    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::GenerateChannelDataItem() - return" ) ) );
    return KErrNone;
    }

#ifdef	DSG

void CSsyReferenceCmdHandler::SendData()
	{
	if (iMessage)
		{
		TSsyRefChannelDataBase dataItem = iDataItemArray[iDataItemPtr];

		// Set timestamp to data item
		TTime time;
		time.HomeTime();
		dataItem.SetTimestamp(time);

		// Add data item to message
		iMessage->SetDataItem(&dataItem);

		// Send response
		iMessage->SetFunction(ESsyReferenceDataItemReceived);
		iSsyChannel.ProcessResponse(iMessage);
		}
	}

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::GenerateChannelStateItem
// ---------------------------------------------------------------------------
//
TInt CSsyReferenceCmdHandler::GenerateChannelStateItem()
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::GenerateChannelStateItem()" ) ) );

	SendData();

	// If we wrap around, or the 'Interval' (i.e. state number) of the next entry
	// differs from that of the current one, we've finished this sequence of callbacks
	TInt newIndex = iDataItemPtr+1;
    if (newIndex >= iDataItemArray.Count())
		newIndex = 0;
	TInt oldState = iDataItemArray[iDataItemPtr].Interval();
	TInt newState = iDataItemArray[newIndex].Interval();
	if (newState == oldState && newIndex != 0)
	    {
        iDataItemPtr = newIndex;
	    }
	else
	    {
        iTimer->Cancel();
        
  	    }
	
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::GenerateChannelStateItem() - return" ) ) );
    return KErrNone;
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::StateItemCallback
// ---------------------------------------------------------------------------
//
TInt CSsyReferenceCmdHandler::StateItemCallback( TAny* aThis )
    {
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::StateItemCallback()" ) ) );
    return static_cast<CSsyReferenceCmdHandler*>( aThis )->GenerateChannelStateItem();
    }

// ---------------------------------------------------------------------------
// CSsyReferenceCmdHandler::PsValueSet
// ---------------------------------------------------------------------------
//
void CSsyReferenceCmdHandler::PsValueSet(TUid aCategory, TUint aKey, TInt aValue)
    {
	TUid c = aCategory;
	TInt k = aKey;
    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::PsValueSet(%x, %x, %d)" ), aCategory, aKey, aValue ) );

	// Find where to start ...
	for (TInt index = 0; index < iDataItemArray.Count(); ++index)
		{
		TSsyRefChannelDataBase& dataItem = iDataItemArray[index];
		if (dataItem.Interval() == aValue)
			{
			// The 'Interval' (i.e. state number) matches the property value.
			// Set the start index and start the timer callback running
			iDataItemPtr = index;
			iTimer->Cancel();
			iTimer->Start(10, 10000, TCallBack(StateItemCallback, this));
			break;
			}
		}

    COMPONENT_TRACE( ( _L( "SSY Reference Plugin - CSsyReferenceCmdHandler::PsValueSet() - return" ) ) );
    }

#include "ssypslistener.cpp"

#endif	// DSG

// End of file
