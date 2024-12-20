plugins {
    id("com.android.library")
}

android {
    namespace = "com.secondyou.imgui"
    compileSdk = 34

    defaultConfig {
        minSdk = 24
        
        ndk {
            abiFilters += listOf("arm64-v8a", "armeabi-v7a")
        }

        externalNativeBuild {
            cmake {
                arguments(
                    "-DANDROID_STL=c++_shared",
                    "-DANDROID_ARM_NEON=TRUE",
                    "-DIMGUI_JAVA_BUILD_SHARED=ON"
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

    externalNativeBuild {
        cmake {
            path = file("CMakeLists.txt")
            version = "3.22.1"
        }
    }
}

buildscript {
    repositories {
        google()
        mavenCentral()
    }
    dependencies {
        classpath("com.android.tools.build:gradle:8.1.0")
    }
}
