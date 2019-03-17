#ifndef __BINDER_DEMO_OBSERVER_H__
#define __BINDER_DEMO_OBSERVER_H__

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>

namespace android {

class IBinderDemoObserver : public IInterface {
public:
    DECLARE_META_INTERFACE(BinderDemoObserver);

    virtual status_t echoBack(const String16 &msg) = 0;
};

////////////////////////////////////////////////////////////////////////////////

class BnBinderDemoObserver : public BnInterface<IBinderDemoObserver> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel &data, Parcel *reply,
                                uint32_t flags = 0);
};

}  // namespace android

#endif  // __BINDER_DEMO_OBSERVER_H__