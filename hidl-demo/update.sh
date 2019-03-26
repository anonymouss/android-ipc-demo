#!/bin/bash

package="simple.demo.hidl@1.0"

options="
-r simple.demo:vendor/ThirdParty/android-ipc-demo/hidl-demo/
-r android.hidl:system/libhidl/transport"

echo "Updating $package"

hidl-gen -Landroidbp $options $package

hidl-gen -o hidl/1.0/default/ -Lc++-impl $options $package

hidl-gen -o hidl/1.0/default/ -Landroidbp-impl $options $package