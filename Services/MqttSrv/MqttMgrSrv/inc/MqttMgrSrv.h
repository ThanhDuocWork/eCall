#ifndef _MQTT_MGR_SRV_H_
#define _MQTT_MGR_SRV_H_

#include <iostream>
#include <chrono>
#include <list>
#include <string>
#include <thread>
#include <vector>

#include <binder/BinderService.h>
#include <binder/IInterface.h>

#include <MqttServiceInterface/BnMqttServiceInterface.h>
#include <MqttServiceInterface/BpMqttServiceInterface.h>
#include <MqttServiceInterface/MqttServiceInterface.h>

#include <MqttReceiver/BnMqttReceiver.h>
#include <MqttReceiver/BpMqttReceiver.h>
#include <MqttReceiver/MqttReceiver.h>

#include "Logger.h"
#include "Utils.h"

class MqttMgrSrv : public MqttServiceInterface::BnMqttServiceInterface
{
public:
    virtual ::android::binder::Status Connect(
        const ::android::String16& broker);

    virtual ::android::binder::Status Disconnect();

    virtual ::android::binder::Status Subscribe(
        const ::android::String16& topic);

    virtual ::android::binder::Status Publish(
        const ::android::String16& topic,
        const ::android::String16& payload);

    virtual ::android::binder::Status registerReceiver(
        const ::android::sp<::android::IBinder>& binder);

    void onMqttReceived(std::string topic, std::string data);

private:
    std::list<android::sp<MqttReceiver::IMqttReceiver>> mReceiverList;
};

#endif