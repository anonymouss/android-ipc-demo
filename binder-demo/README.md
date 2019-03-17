# Simple Binder Demo

## Compile & Run

> 当前代码在 **Android O (8.x)** 编译验证通过

- 将本文件夹置于 Android 源代码任意目录，如 `$ROOT/vendor/$THIRD_PARTY/binder-demo`
- lunch Andoird 编译配置，在 `binder-demo` 目录运行 Android 编译命令 `mm`
- 编译输出位于 `$OUT/vendor/lib(64)/` 以及 `$OUT/vendor/bin/`
- push 到设备
    ```shell
    adb wait-for-device devices
    adb root && adb remount

    # push libs
    adb push vendor/lib/libbinderdemo_interface.so vendor/lib/
    adb push vendor/lib64/libbinderdemo_interface.so vendor/lib64/

    # push binaries
    adb push vendor/bin/binderdemo_service vendor/bin/
    adb push vendor/bin/binderdemo_client vendor/bin/

    adb shell chmod 777 system/bin/binderdemo_service
    adb shell chmod 777 system/bin/binderdemo_client
    ```
- 启动 `adb logcat` 抓取 log。启动 service 与 client `adb shell vendor/bin/binderdemo_service` ， `adb shell vendor/bin/binderdemo_client`

## Result

> grep BinderDemo
```
// TIME             PID   TID  L LOG_TAG            DETAILS 
03-18 02:18:46.070  4518  4518 I BinderDemoService: Starting service: binderdemo.service
03-18 02:18:46.081  4518  4518 I BinderDemoService: add service binderdemo.service successfully
03-18 02:18:48.003  4522  4522 I BinderDemoClient: Starting clinet
03-18 02:18:48.009  4522  4522 I IBinderDemoService(Bp): registerObserver
03-18 02:18:48.009  4518  4520 I IBinderDemoService(Bn): onTransact - REGISTER_OBSERVER
03-18 02:18:48.009  4518  4520 I BinderDemoService: registerObserver
03-18 02:18:48.009  4522  4522 I BinderDemoClient: === echo message 1      ===
03-18 02:18:48.009  4522  4522 I IBinderDemoService(Bp): echoTo - messgae is: 1st message from client
03-18 02:18:48.009  4518  4520 I IBinderDemoService(Bn): onTransact - ECHO_TO
03-18 02:18:48.009  4518  4520 I BinderDemoService: echoTo - service side received message: 1st message from client
03-18 02:18:48.009  4518  4520 I BinderDemoService: echoTo - observer exist, I will send message back to observer
03-18 02:18:48.009  4518  4520 E IBinderDemoObserver(Bp): echoBack - message is： 1st message from client
03-18 02:18:48.010  4522  4522 I IBinderDemoObserver(Bn): onTransact - ECHO_BACK
03-18 02:18:48.010  4522  4522 I BinderDemoClient: echoBack - observer received message back to client: 1st message from client
03-18 02:18:48.010  4522  4522 I BinderDemoClient: === echo message 1 done ===
03-18 02:18:48.010  4522  4522 I BinderDemoClient: === echo message 2      ===
03-18 02:18:48.010  4522  4522 I IBinderDemoService(Bp): echoTo - messgae is: 2st message from client
03-18 02:18:48.010  4518  4520 I IBinderDemoService(Bn): onTransact - ECHO_TO
03-18 02:18:48.010  4518  4520 I BinderDemoService: echoTo - service side received message: 2st message from client
03-18 02:18:48.010  4518  4520 I BinderDemoService: echoTo - observer exist, I will send message back to observer
03-18 02:18:48.010  4518  4520 E IBinderDemoObserver(Bp): echoBack - message is： 2st message from client
03-18 02:18:48.010  4522  4522 I IBinderDemoObserver(Bn): onTransact - ECHO_BACK
03-18 02:18:48.010  4522  4522 I BinderDemoClient: echoBack - observer received message back to client: 2st message from client
03-18 02:18:48.010  4522  4522 I BinderDemoClient: === echo message 2 done ===
```

## How to use `binder` in native C++ codes

> TODO

## Inside the `binder` mechanism

> TODO