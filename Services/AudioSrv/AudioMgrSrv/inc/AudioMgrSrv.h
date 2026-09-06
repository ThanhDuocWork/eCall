#ifndef _AUDIO_MGR_SRV_H_
#define _AUDIO_MGR_SRV_H_

#include <iostream>
#include <thread>
#include <list>
#include <vector>
#include <string>

#include <binder/BinderService.h>
#include <binder/IInterface.h>

#include "PlayAudio.h"

#include <AudioServiceInterface/BnAudioServiceInterface.h>
#include <AudioServiceInterface/BpAudioServiceInterface.h>
#include <AudioServiceInterface/AudioServiceInterface.h>

#include <AudioReceiver/BnAudioReceiver.h>
#include <AudioReceiver/BpAudioReceiver.h>
#include <AudioReceiver/AudioReceiver.h>

using namespace android;
using namespace std;

class AudioMgrSrv
    : public AudioServiceInterface::BnAudioServiceInterface,
      public PlayAudio
{
public:
    virtual ::android::binder::Status PlayAudio(
        const ::android::String16& filePath,
        int32_t* _aidl_return);

    virtual ::android::binder::Status StopAudio(
        int32_t* _aidl_return);

    virtual ::android::binder::Status registerReceiver(
        const ::android::sp<::android::IBinder>& binder);

    virtual ::android::binder::Status callBack();

    void PlayStateChanged(FLAG_AUDIO stateCurrent);

private:
    std::list<android::sp<AudioReceiver::IAudioReceiver>> mReceiverList;
};

#endif