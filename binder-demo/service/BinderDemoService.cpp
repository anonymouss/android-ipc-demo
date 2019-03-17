#include "../interface/IBinderDemoObserver.h"
#include "../interface/IBinderDemoService.h"

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/RefBase.h>

#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <utils/Log.h>

#undef LOG_TAG
#define LOG_TAG "BinderDemoService"

namespace android {

// 服务端的具体实现，BnXXX 的具体实现
class BinderDemoService : public BnBinderDemoService {
public:
    virtual status_t registerObserver(const sp<IBinderDemoObserver> &observer) {
        ALOGI("%s", __func__);
        mObserver = observer;
        return NO_ERROR;
    }

    virtual status_t echoTo(const String16 &msg) {
        String8 tmpStr = msg ? String8(msg) : String8("UNKNOWN");
        ALOGI("%s - service side received message: %s", __func__, tmpStr.string());

        if (mObserver != nullptr) {
            ALOGI("%s - observer exist, I will send message back to observer", __func__);
            mObserver->echoBack(msg);
        } else {
            ALOGE("%s - no observer registered", __func__);
        }
        return NO_ERROR;
    }

private:
    sp<IBinderDemoObserver> mObserver;
};

}  // namespace android

using namespace android;

int main() {
    const char *kServiceName = "binderdemo.service";
    ALOGI("Starting service: %s", kServiceName);

    sp<ProcessState> proc(ProcessState::self());

    sp<IServiceManager> sm(defaultServiceManager());
    sm->addService(String16(kServiceName), new BinderDemoService());

    if (sm->checkService(String16(kServiceName)) == nullptr) {
        ALOGE("add service %s failed", kServiceName);
        return -1;
    } else {
        ALOGI("add service %s successfully", kServiceName);
    }

    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}