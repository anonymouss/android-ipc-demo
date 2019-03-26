#include "DemoService.h"

#include <hidl/HidlTransportSupport.h>
#include <utils/Log.h>

#undef LOG_TAG
#define LOG_TAG "DemoService-main"

using namespace android;
using namespace android::hardware;
using namespace simple::demo::hidl::V1_0::implementation;
using namespace simple::demo::hidl::V1_0;

int main() {
    sp<IDemoService> service = new DemoService();

    configureRpcThreadpool(1, true /* callerWillJoin */);

    ALOGI("Registering demo service...");
    service->registerAsService("simple.demo.service");

    joinRpcThreadpool();
    return 0;
}