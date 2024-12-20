plugins {
    `cpp-library`
}

library {
    // Configure target platforms
    targetMachines.add(machines.linux.x86_64)
    
    binaries.configureEach {
        // Set compile options
        compileTask.get().apply {
            includes.from("imgui")
            includes.from("src/jni")
            source.from(
                fileTree("imgui") {
                    include("*.cpp")
                    exclude("**/examples/**")
                },
                fileTree("src/jni") {
                    include("*.cpp")
                }
            )
        }

        // Configure linkage type as shared library
        linkTask.get().apply {
            targetPlatform.set(when {
                targetMachine.architectureFamily.name == "arm64" -> "arm64-v8a"
                targetMachine.architectureFamily.name == "arm" -> "armeabi-v7a"
                else -> targetMachine.architectureFamily.name
            })
        }
    }
}

tasks.register<Exec>("buildAndroidArm64") {
    val ndkDir = System.getenv("ANDROID_NDK") ?: "/data/data/com.termux/files/home/android-sdk/ndk/26.1.10909125"
    
    workingDir = file("build/arm64")
    doFirst {
        file("build/arm64").mkdirs()
    }
    
    commandLine(
        "cmake", 
        "-DCMAKE_TOOLCHAIN_FILE=$ndkDir/build/cmake/android.toolchain.cmake",
        "-DANDROID_ABI=arm64-v8a",
        "-DANDROID_PLATFORM=android-24",
        "-DCMAKE_BUILD_TYPE=Release",
        "-DANDROID_STL=c++_shared",
        file(".")
    )
    
    doLast {
        exec {
            workingDir = file("build/arm64")
            commandLine("make")
        }
    }
}

tasks.register<Exec>("buildAndroidArm32") {
    val ndkDir = System.getenv("ANDROID_NDK") ?: "/data/data/com.termux/files/home/android-sdk/ndk/26.1.10909125"
    
    workingDir = file("build/arm32")
    doFirst {
        file("build/arm32").mkdirs()
    }
    
    commandLine(
        "cmake", 
        "-DCMAKE_TOOLCHAIN_FILE=$ndkDir/build/cmake/android.toolchain.cmake",
        "-DANDROID_ABI=armeabi-v7a",
        "-DANDROID_PLATFORM=android-24",
        "-DCMAKE_BUILD_TYPE=Release",
        "-DANDROID_STL=c++_shared",
        file(".")
    )
    
    doLast {
        exec {
            workingDir = file("build/arm32")
            commandLine("make")
        }
    }
}

tasks.register("buildAll") {
    dependsOn("buildAndroidArm64", "buildAndroidArm32")
}
