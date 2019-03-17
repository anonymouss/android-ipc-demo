#include "IBinderDemoService.h"
#include "IBinderDemoObserver.h"

#include <binder/Parcel.h>

namespace android {

enum {
    REGISTER_OBSERVER = IBinder::FIRST_CALL_TRANSACTION,
    ECHO_TO,
};

#undef LOG_TAG
#define LOG_TAG "IBinderDemoService(Bp)"

/**
 * BpXXX: 客户端的代理
 */
class BpBinderDemoService : public BpInterface<IBinderDemoService> {
public:
    explicit BpBinderDemoService(const sp<IBinder> &binder)
        : BpInterface<IBinderDemoService>(binder) {}

    virtual status_t registerObserver(const sp<IBinderDemoObserver> &observer) {
        ALOGI("%s", __func__);
        Parcel data, reply;
        data.writeInterfaceToken(IBinderDemoService::getInterfaceDescriptor());
        data.writeStrongBinder(IInterface::asBinder(observer));
        remote()->transact(REGISTER_OBSERVER, data, &reply);

        return reply.readInt32();
    }

    virtual status_t echoTo(const String16 &msg) {
        String8 tmpStr = msg ? String8(msg) : String8("UNKNOWN");
        ALOGI("%s - messgae is: %s", __func__, tmpStr.string());
        Parcel data, reply;
        data.writeInterfaceToken(IBinderDemoService::getInterfaceDescriptor());
        data.writeString16(msg);
        remote()->transact(ECHO_TO, data, &reply);

        return reply.readInt32();
    }
};

IMPLEMENT_META_INTERFACE(BinderDemoService, "test.binderdemo.service");

////////////////////////////////////////////////////////////////////////////////

#undef LOG_TAG
#define LOG_TAG "IBinderDemoService(Bn)"

status_t BnBinderDemoService::onTransact(uint32_t code, const Parcel &data, Parcel *reply,
                                         uint32_t flags) {
    switch (code) {
        case REGISTER_OBSERVER: {
            CHECK_INTERFACE(IBinderDemoService, data, reply);
            ALOGI("%s - REGISTER_OBSERVER", __func__);
            sp<IBinderDemoObserver> observer =
                interface_cast<IBinderDemoObserver>(data.readStrongBinder());
            auto err = registerObserver(observer);

            reply->writeInt32(err);
            return NO_ERROR;
        }

        case ECHO_TO: {
            CHECK_INTERFACE(IBinderDemoService, data, reply);
            ALOGI("%s - ECHO_TO", __func__);
            String16 msg = data.readString16();
            auto err = echoTo(msg);

            reply->writeInt32(err);
            return NO_ERROR;
        }

        default: return BBinder::onTransact(code, data, reply, flags);
    }
}

}  // namespace android