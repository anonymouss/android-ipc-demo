#ifndef __BINDER_DEMO_SERVICE_H__
#define __BINDER_DEMO_SERVICE_H__

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>

namespace android {

class IBinderDemoObserver;

/**
 * IXXX: 接口，定义服务暴露出的方法
 */
class IBinderDemoService : public IInterface {
public:
    DECLARE_META_INTERFACE(BinderDemoService);

    virtual status_t registerObserver(const sp<IBinderDemoObserver> &observer) = 0;
    virtual status_t echoTo(const String16 &msg) = 0;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * BnXXX: 服务端的代理
 */
class BnBinderDemoService : public BnInterface<IBinderDemoService> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel &data, Parcel *reply,
                                uint32_t flags = 0);
};

}  // namespace android

#endif  // __BINDER_DEMO_SERVICE_H__