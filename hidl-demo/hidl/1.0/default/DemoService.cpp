#include "DemoService.h"

#include <utils/Log.h>

#undef LOG_TAG
#define LOG_TAG "DemoService"

namespace simple {
namespace demo {
namespace hidl {
namespace V1_0 {
namespace implementation {

// Methods from ::simple::demo::hidl::V1_0::IDemoService follow.
Return<int32_t> DemoService::echo(const ::simple::demo::hidl::V1_0::DemoInfo& info) {
    // TODO implement
    ALOGI("id %u - msg %s", info.id, info.message.c_str());
    return int32_t{};
}

// Methods from ::android::hidl::base::V1_0::IBase follow.

IDemoService* HIDL_FETCH_IDemoService(const char* /* name */) { return new DemoService(); }

}  // namespace implementation
}  // namespace V1_0
}  // namespace hidl
}  // namespace demo
}  // namespace simple
