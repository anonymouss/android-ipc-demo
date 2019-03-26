# Android IPC Demo

**Binder** - Android 进程间通信的一种方式，或者说是一种 RPC 调用方式。简言之，客户端进程可以通过 binder 机制获得服务端进程的代理对象，通过代理对象直接调用服务端进程暴露出来的接口。

**HIDL(HAL Interface Definition Language)** - Project Treble 的一部分，从 Android O 开始，HAL 不再和 Framework 跑在同一进程，HIDL 用以它们之间的通信（Binder化）。目的是隔离/解耦 AOSP 与 Vendor 代码。

- [Binder demo](./binder-demo/)
- [HIDL demo](./hidl-demo/)

> Related Topics: `Binder`, `HIDL`, `SELinux/sepolicy`
> 
> - https://source.android.com/devices/architecture/hidl
> - https://source.android.com/security/selinux/
> - https://source.android.com/security/selinux/images/SELinux_Treble.pdf

**Android 整体架构**

![Android Architecture](android_architecture.png)
