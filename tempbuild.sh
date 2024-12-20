#!/bin/bash

# Set NDK path - adjust this to your NDK location
export ANDROID_NDK=/data/data/com.termux/files/home/android-sdk/ndk/26.1.10909125

# Create build directories for each ABI
mkdir -p build/arm64-v8a
mkdir -p build/armeabi-v7a

# Build for ARM64
cd build/arm64-v8a
cmake ../.. \
    -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
    -DANDROID_ABI=arm64-v8a \
    -DANDROID_PLATFORM=android-24 \
    -DCMAKE_BUILD_TYPE=Release \
    -DANDROID_STL=c++_shared
cmake --build . --config Release

# Build for ARM32
cd ../armeabi-v7a
cmake ../.. \
    -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
    -DANDROID_ABI=armeabi-v7a \
    -DANDROID_PLATFORM=android-24 \
    -DCMAKE_BUILD_TYPE=Release \
    -DANDROID_STL=c++_shared
cmake --build . --config Release

# Copy libraries to a common directory
mkdir -p ../../libs/arm64-v8a
mkdir -p ../../libs/armeabi-v7a
cp lib*.so ../../libs/armeabi-v7a/
cd ../arm64-v8a
cp lib*.so ../../libs/arm64-v8a/

echo "Build complete. Libraries are in the 'libs' directory"
