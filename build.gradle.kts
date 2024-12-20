plugins {
    id("com.android.library") version "8.1.0"
}

android {
    namespace = "com.secondyou.imgui"
    compileSdk = 34

    defaultConfig {
        minSdk = 24

        externalNativeBuild {
            cmake {
                path = file("CMakeLists.txt")
                version = "3.22.1"
                arguments(
                    "-DANDROID_STL=c++_shared",
                    "-DANDROID_ARM_NEON=TRUE"
                )
                cppFlags("-std=c++17")
            }
        }
    }

    buildTypes {
        release {
            isMinifyEnabled = false
        }
    }

    ndkVersion = "26.1.10909125"
}

tasks.register<Exec>("buildArm64") {
    val ndkDir = System.getenv("ANDROID_NDK") ?: "/data/data/com.termux/files/home/android-sdk/ndk/26.1.10909125"

    workingDir = file("build/arm64-v8a")
    commandLine(
        "cmake",
        "-DCMAKE_TOOLCHAIN_FILE=$ndkDir/build/cmake/android.toolchain.cmake",
        "-DANDROID_ABI=arm64-v8a",
        "-DANDROID_PLATFORM=android-24",
        "-DCMAKE_BUILD_TYPE=Release",
        "-DANDROID_STL=c++_shared",
        file("..")
    )
    doLast {
        exec {
            workingDir = file("build/arm64-v8a")
            commandLine("make")
        }
    }
}

tasks.register<Exec>("buildArm32") {
    val ndkDir = System.getenv("ANDROID_NDK") ?: "/data/data/com.termux/files/home/android-sdk/ndk/26.1.10909125"

    workingDir = file("build/armeabi-v7a")
    commandLine(
        "cmake",
        "-DCMAKE_TOOLCHAIN_FILE=$ndkDir/build/cmake/android.toolchain.cmake",
        "-DANDROID_ABI=armeabi-v7a",
        "-DANDROID_PLATFORM=android-24",
        "-DCMAKE_BUILD_TYPE=Release",
        "-DANDROID_STL=c++_shared",
        file("..")
    )
    doLast {
        exec {
            workingDir = file("build/armeabi-v7a")
            commandLine("make")
        }
    }
}

tasks.register("buildAll") {
    dependsOn("buildArm64", "buildArm32")
}
