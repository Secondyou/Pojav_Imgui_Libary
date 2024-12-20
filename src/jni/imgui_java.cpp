#include "imgui_java.h"
#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "ImGuiJava", __VA_ARGS__))

extern "C" {

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_init(JNIEnv* env, jclass cls) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
}

JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_shutdown(JNIEnv* env, jclass cls) {
    ImGui::DestroyContext();
}

JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_newFrame(JNIEnv* env, jclass cls) {
    ImGui::NewFrame();
}

JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_render(JNIEnv* env, jclass cls) {
    ImGui::Render();
}

} // extern "C"
