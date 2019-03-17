#include "../interface/IBinderDemoObserver.h"
#include "../interface/IBinderDemoService.h"

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>

#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <utils/Log.h>

#undef LOG_TAG
#define LOG_TAG "BinderDemoClient"

namespace android {

class BinderDemoObserver : public BnBinderDemoObserver {
public:
    virtual status_t echoBack(const String16 &msg) {
        String8 tmpStr = msg ? String8(msg) : String8("UNKNOWN");
        ALOGI("%s - observer received message back to client: %s", __func__, tmpStr.string());
        return NO_ERROR;
    }
};

}  // namespace android

using namespace android;

int main() {
    const char *kServiceName = "binderdemo.service";
    ALOGI("Starting clinet");

    sp<IServiceManager> sm(defaultServiceManager());
    sp<IBinder> binder = sm->getService(String16(kServiceName));

    if (binder == nullptr) {
        ALOGE("can't get serivce binder : %s", kServiceName);
        return -1;
    }

    sp<IBinderDemoService> binderDemoService = interface_cast<IBinderDemoService>(binder);

    binderDemoService->registerObserver(new BinderDemoObserver);

    ALOGI("=== echo message 1      ===");
    binderDemoService->echoTo(String16("1st message from client"));
    ALOGI("=== echo message 1 done ===");

    ALOGI("=== echo message 2      ===");
    binderDemoService->echoTo(String16("2st message from client"));
    ALOGI("=== echo message 2 done ===");

    return 0;
}