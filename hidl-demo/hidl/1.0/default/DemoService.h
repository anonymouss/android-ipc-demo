#ifndef SIMPLE_DEMO_HIDL_V1_0_DEMOSERVICE_H
#define SIMPLE_DEMO_HIDL_V1_0_DEMOSERVICE_H

#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <simple/demo/hidl/1.0/IDemoService.h>

namespace simple {
namespace demo {
namespace hidl {
namespace V1_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;

struct DemoService : public IDemoService {
    // Methods from ::simple::demo::hidl::V1_0::IDemoService follow.
    Return<int32_t> echo(const ::simple::demo::hidl::V1_0::DemoInfo& info) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.
};

// FIXME: most likely delete, this is only for passthrough implementations
extern "C" IDemoService* HIDL_FETCH_IDemoService(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace hidl
}  // namespace demo
}  // namespace simple

#endif  // SIMPLE_DEMO_HIDL_V1_0_DEMOSERVICE_H
