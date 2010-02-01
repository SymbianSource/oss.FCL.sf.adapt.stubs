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
* Description: Audio Stubs -
*
*/


#include "audioequalizerproxy.h"
#include "bassboostproxy.h"
#include "distanceattenuationproxy.h"
#include "environmentalreverbproxy.h"
#include "listenerdopplerproxy.h"
#include "listenerlocationproxy.h"
#include "listenerorientationproxy.h"
#include "loudnessproxy.h"
#include "roomlevelproxy.h"
#include "sourcedopplerproxy.h"
#include "sourcelocationproxy.h"
#include "sourceorientationproxy.h"
#include "stereowideningproxy.h"
#include "addeddevsoundcontrolci.h"
#include "addeddevsoundcontrolproxy.h"
#include "restrictedaudiooutputproxy.h"
#include "audioinputproxy.h"
#include "audiooutputproxy.h"
#include "audioinputmessagetypes.h"
#include "audiooutputmessagetypes.h"
#include "g711decoderintfcproxy.h"
#include "g729decoderintfcproxy.h"
#include "ilbcdecoderintfcproxy.h"
#include "g711encoderintfcproxy.h"
#include "g729encoderintfcproxy.h"
#include "ilbcencoderintfcproxy.h"
#include "speechencoderconfigproxy.h"
#include "errorconcealmentintfcproxy.h"
#include "custominterfaceproxyfactory.h"


EXPORT_C TAny* CCustomInterfaceProxyFactory::CreateProxy(TUid aInterfaceUid,
                                                         TMMFMessageDestinationPckg aHandlePckg,
                                                         MCustomCommand& aCustomCommand,
                                                         CCustomInterfaceUtility* aCustomInterfaceUtility)
	{
	TAny* customInterface = NULL;

	if (aInterfaceUid == KUidAudioInput)
		{
		CAudioInputProxy* inputProxy = CAudioInputProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = inputProxy;
		}
    else if(aInterfaceUid == KUidAudioOutput)
		{
		CAudioOutputProxy* outputProxy = CAudioOutputProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = outputProxy;
		}
	else if (aInterfaceUid == KUidAudioEqualizerEffect)
		{
		CAudioEqualizerProxy* audioEqualizerProxy = CAudioEqualizerProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = audioEqualizerProxy;
		}
	else if (aInterfaceUid == KUidBassBoostEffect)
		{
		CBassBoostProxy* bassBoostProxy = CBassBoostProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = bassBoostProxy;
		}
	else if (aInterfaceUid == KUidDistanceAttenuationEffect)
		{
		CDistanceAttenuationProxy* distanceAttenuationProxy = CDistanceAttenuationProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = distanceAttenuationProxy;
		}
	else if (aInterfaceUid == KUidEnvironmentalReverbEffect)
		{
		CEnvironmentalReverbProxy* environmentalReverbProxy = CEnvironmentalReverbProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = environmentalReverbProxy;
		}
	else if (aInterfaceUid == KUidListenerDopplerEffect)
		{
		CListenerDopplerProxy* listenerDopplerProxy = CListenerDopplerProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = listenerDopplerProxy;
		}
	else if (aInterfaceUid == KUidListenerLocationEffect)
		{
		CListenerLocationProxy* listenerLocationProxy = CListenerLocationProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = listenerLocationProxy;
		}
	else if (aInterfaceUid == KUidListenerOrientationEffect)
		{
		CListenerOrientationProxy* listenerOrientationProxy = CListenerOrientationProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = listenerOrientationProxy;
		}
	else if (aInterfaceUid == KUidLoudnessEffect)
		{
		CLoudnessProxy* loudnessProxy = CLoudnessProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = loudnessProxy;
		}
	else if (aInterfaceUid == KUidRoomLevelEffect)
		{
		CRoomLevelProxy* roomLevelProxy = CRoomLevelProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = roomLevelProxy;
		}
	else if (aInterfaceUid == KUidSourceDopplerEffect)
		{
		CSourceDopplerProxy* sourceDopplerProxy = CSourceDopplerProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = sourceDopplerProxy;
		}
	else if (aInterfaceUid == KUidSourceLocationEffect)
		{
		CSourceLocationProxy* sourceLocationProxy = CSourceLocationProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = sourceLocationProxy;
		}
	else if (aInterfaceUid == KUidSourceOrientationEffect)
		{
		CSourceOrientationProxy* sourceOrientationProxy = CSourceOrientationProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = sourceOrientationProxy;
		}
	else if (aInterfaceUid == KUidStereoWideningEffect)
		{
		CStereoWideningProxy* stereoWideningProxy = CStereoWideningProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = stereoWideningProxy;
		}
    else if(aInterfaceUid == KUidAddedDevSoundControlInterface)
		{
		CAddedDevSoundControlProxy* proxy = CAddedDevSoundControlProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = proxy;
		}
    else if (aInterfaceUid == KUidG711DecoderIntfc)
        {
        CG711DecoderIntfcProxy* g711DecoderIntfcProxy = CG711DecoderIntfcProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = g711DecoderIntfcProxy;
        }
    else if (aInterfaceUid == KUidG729DecoderIntfc)
        {
        CG729DecoderIntfcProxy* g729DecoderIntfcProxy = CG729DecoderIntfcProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = g729DecoderIntfcProxy;
        }
    else if (aInterfaceUid == KUidIlbcDecoderIntfc)
        {
        CIlbcDecoderIntfcProxy* iIlbcDecoderIntfcProxy = CIlbcDecoderIntfcProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = iIlbcDecoderIntfcProxy;
        }
    else if (aInterfaceUid == KUidG711EncoderIntfc)
        {
        CG711EncoderIntfcProxy* g711EncoderIntfcProxy = CG711EncoderIntfcProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = g711EncoderIntfcProxy;
        }
    else if (aInterfaceUid == KUidG729EncoderIntfc)
        {
        CG729EncoderIntfcProxy* g729EncoderIntfcProxy = CG729EncoderIntfcProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = g729EncoderIntfcProxy;
        }
    else if (aInterfaceUid == KUidIlbcEncoderIntfc)
        {
        CIlbcEncoderIntfcProxy* iIlbcEncoderIntfcProxy = CIlbcEncoderIntfcProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = iIlbcEncoderIntfcProxy;
        }
    else if (aInterfaceUid == KUidSpeechEncoderConfig)
        {
        CSpeechEncoderConfigProxy* speechEncoderIntfcProxy = CSpeechEncoderConfigProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = speechEncoderIntfcProxy;
        }
    else if (aInterfaceUid == KUidErrorConcealmentIntfc)
        {
        CErrorConcealmentIntfcProxy* errConcealmentIntfcProxy = CErrorConcealmentIntfcProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = errConcealmentIntfcProxy;
        }
    else if(aInterfaceUid == KUidRestrictedAudioOutput)
		{
		CRestrictedAudioOutputProxy* proxy = CRestrictedAudioOutputProxy::NewL(aHandlePckg, aCustomCommand, aCustomInterfaceUtility);
		customInterface = proxy;
		}

	return customInterface;
	}


// End of File
