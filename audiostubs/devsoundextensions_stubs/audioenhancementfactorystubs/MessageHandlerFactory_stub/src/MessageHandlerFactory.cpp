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
* Description: Audio Stubs -  Implementation of the adaptation stub for
*              : MessageHandlerFactory.
*
*/

#include "messagehandlerfactory.h"
#include "audioinputmessagehandler.h"
#include "audiooutputmessagehandler.h"
#include "audioinputmessagetypes.h"
#include "audiooutputmessagetypes.h"

#include "messagehandlerfactory.h"
#include "audioequalizermessagehandler.h"
#include "bassboostmessagehandler.h"
#include "distanceattenuationmessagehandler.h"
#include "environmentalreverbmessagehandler.h"
#include "listenerdopplermessagehandler.h"
#include "listenerlocationmessagehandler.h"
#include "listenerorientationmessagehandler.h"
#include "loudnessmessagehandler.h"
#include "roomlevelmessagehandler.h"
#include "sourcedopplermessagehandler.h"
#include "sourcelocationmessagehandler.h"
#include "sourceorientationmessagehandler.h"
#include "stereowideningmessagehandler.h"
#include "addeddevsoundcontrolmsghdlr.h"
#include "restrictedaudiooutputmessagehandler.h"
#include "audiooutputmessagehandler.h"

#include "speechencoderconfigmsghdlr.h"
#include "errorconcealmentintfcmsghdlr.h"
#include "g711decoderintfcmsghdlr.h"
#include "g729decoderintfcmsghdlr.h"
#include "ilbcdecoderintfcmsghdlr.h"
#include "g711encoderintfcmsghdlr.h"
#include "g729encoderintfcmsghdlr.h"
#include "ilbcencoderintfcmsghdlr.h"
#include "aacdecoderconfigmsghdlr.h"
//#include "AudioVibraControlMsgHdlr.h" // Audio Vibra Control API is deprecated

#include "speechencoderconfig.h"
#include "aacdecoderconfig.h"
#include "errorconcealmentintfc.h"
#include "g711decoderintfc.h"
#include "g729decoderintfc.h"
#include "ilbcdecoderintfc.h"
#include "g711encoderintfc.h"
#include "g729encoderintfc.h"
#include "ilbcencoderintfc.h"
//#include "AudioVibraControl.h" // Audio Vibra Control API is deprecated

EXPORT_C CMMFObject* CMessageHandlerFactory::Create(TUid aInterfaceUid,
                                                    TAny* aCustomInterface,
                                                    CMMFObjectContainer& aContainer)
	{
	CMMFObject* messageHandler = NULL;

	if (aInterfaceUid == KUidAudioEqualizerEffect)
		{
		messageHandler = CAudioEqualizerMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidBassBoostEffect)
		{
		messageHandler = CBassBoostMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidDistanceAttenuationEffect)
		{
		messageHandler = CDistanceAttenuationMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidEnvironmentalReverbEffect)
		{
		messageHandler = CEnvironmentalReverbMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidListenerDopplerEffect)
		{
		messageHandler = CListenerDopplerMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidListenerLocationEffect)
		{
		messageHandler = CListenerLocationMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidListenerOrientationEffect)
		{
		messageHandler = CListenerOrientationMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidLoudnessEffect)
		{
		messageHandler = CLoudnessMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidRoomLevelEffect)
		{
		messageHandler = CRoomLevelMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidSourceDopplerEffect)
		{
		messageHandler = CSourceDopplerMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidSourceLocationEffect)
		{
		messageHandler = CSourceLocationMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidSourceOrientationEffect)
		{
		messageHandler = CSourceOrientationMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidStereoWideningEffect)
		{
		messageHandler = CStereoWideningMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidRestrictedAudioOutput)
		{
		messageHandler = CRestrictedAudioOutputMessageHandler::NewL(aCustomInterface);
		}
	else if (aInterfaceUid == KUidAudioOutput)
		{
		messageHandler = CAudioOutputMessageHandler::NewL(aCustomInterface, aContainer);
		}
	else if (aInterfaceUid == KUidAudioInput)
		{
		messageHandler = CAudioInputMessageHandler::NewL(aCustomInterface, aContainer);
		}
	else if (aInterfaceUid == KUidAudioOutput)
		{
		messageHandler = CAudioOutputMessageHandler::NewL(aCustomInterface, aContainer);
		}
   else if (aInterfaceUid == KUidSpeechEncoderConfig)
       {
       messageHandler = CSpeechEncoderConfigMsgHdlr::NewL(aCustomInterface);
       }
   else if (aInterfaceUid == KUidErrorConcealmentIntfc)
       {
       messageHandler = CErrorConcealmentIntfcMsgHdlr::NewL(aCustomInterface);
       }
   else if (aInterfaceUid == KUidG711DecoderIntfc)
       {
       messageHandler = CG711DecoderIntfcMsgHdlr::NewL(aCustomInterface);
       }
   else if (aInterfaceUid == KUidG729DecoderIntfc)
       {
       messageHandler = CG729DecoderIntfcMsgHdlr::NewL(aCustomInterface);
       }
   else if (aInterfaceUid == KUidIlbcDecoderIntfc)
       {
       messageHandler = CIlbcDecoderIntfcMsgHdlr::NewL(aCustomInterface);
       }
   else if (aInterfaceUid == KUidG711EncoderIntfc)
       {
       messageHandler = CG711EncoderIntfcMsgHdlr::NewL(aCustomInterface);
       }
   else if (aInterfaceUid == KUidG729EncoderIntfc)
       {
       messageHandler = CG729EncoderIntfcMsgHdlr::NewL(aCustomInterface);
       }
   else if (aInterfaceUid == KUidIlbcEncoderIntfc)
       {
       messageHandler = CIlbcEncoderIntfcMsgHdlr::NewL(aCustomInterface);
       }/*
    else if (aInterfaceUid == KUidAddedDevSoundControlInterface)
       {
       messageHandler = CAddedDevSoundControlMsgHdlr::NewL(aCustomInterface);
       }
	else if (aInterfaceUid == KUidAudioResource)
		{
		messageHandler = CAudioResourceMessageHandler::NewL(aCustomInterface, aContainer);
		}
	else if (aInterfaceUid == KUidAudioEqualizerEffect)
		{
		messageHandler = CAudioEqualizerMessageHandler::NewL(aCustomInterface);
		}
   else if (aInterfaceUid == KUidAudioVibraControl)
       {
       messageHandler = CAudioVibraControlMsgHdlr::NewL(aCustomInterface);
       }
   else if (aInterfaceUid == KUidAacDecoderConfig)
       {
       messageHandler = CAacDecoderConfigMsgHdlr::NewL(aCustomInterface);
       }*/

	return messageHandler;
	}


// End of File
