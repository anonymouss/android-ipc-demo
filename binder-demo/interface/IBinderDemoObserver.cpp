#include "IBinderDemoObserver.h"

#include <binder/Parcel.h>

namespace android {

enum {
    ECHO_BACK = IBinder::FIRST_CALL_TRANSACTION,
};

#undef LOG_TAG
#define LOG_TAG "IBinderDemoObserver(Bp)"

class BpBinderDemoObserver : public BpInterface<IBinderDemoObserver> {
public:
    explicit BpBinderDemoObserver(const sp<IBinder> &binder)
        : BpInterface<IBinderDemoObserver>(binder) {}

    virtual status_t echoBack(const String16 &msg) {
        String8 tmpStr = msg ? String8(msg) : String8("UNKNOWN");
        ALOGE("%s - message is： %s", __func__, tmpStr.string());
        Parcel data, reply;
        data.writeInterfaceToken(IBinderDemoObserver::getInterfaceDescriptor());
        data.writeString16(msg);
        remote()->transact(ECHO_BACK, data, &reply);

        return reply.readInt32();
    }
};

IMPLEMENT_META_INTERFACE(BinderDemoObserver, "test.binderdemo.observer");

////////////////////////////////////////////////////////////////////////////////

#undef LOG_TAG
#define LOG_TAG "IBinderDemoObserver(Bn)"

status_t BnBinderDemoObserver::onTransact(uint32_t code, const Parcel &data, Parcel *reply,
                                          uint32_t flags) {
    switch (code) {
        case ECHO_BACK: {
            CHECK_INTERFACE(IBinderDemoObserver, data, reply);
            ALOGI("%s - ECHO_BACK", __func__);
            String16 msg = data.readString16();
            auto err = echoBack(msg);

            reply->writeInt32(err);
            return NO_ERROR;
        }

        default: return BBinder::onTransact(code, data, reply, flags);
    }
}

}  // namespace android