#include <hidl/HidlTransportSupport.h>
#include <utils/Log.h>

#include <simple/demo/hidl/1.0/IDemoService.h>

#undef LOG_TAG
#define LOG_TAG "DemoClient"

using namespace android;
using namespace android::hardware;
using namespace simple::demo::hidl::V1_0;

int main() {
    sp<IDemoService> demoService = IDemoService::getService("simple.demo.service");
    if (demoService == nullptr) {
        ALOGE("Failed to get demo service !!");
        return -1;
    }

    DemoInfo info{"Hello world", 100};
    ALOGI("call service echo");
    auto ret = demoService->echo(info);

    ALOGI("Done!");
    return 0;
}