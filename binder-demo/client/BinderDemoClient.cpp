#include "IBinderDemoObserver.h"
#include "IBinderDemoService.h"

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
        ALOGI("%s - observer received message %s on client side", tmpStr.string());
        return NO_ERROR;
    }
};

}  // namespace android

using namespace android;

int main() {
    const char *kServiceName = "binderdemo.service";
    ALOGI("Starting clinet");

    // TODO: get service proxy, echo message into it

    return 0;
}