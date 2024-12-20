#pragma once

#include <jni.h>
#include "imgui.h"

extern "C" {

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);

// Core/Basic functions
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_init(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_shutdown(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_newFrame(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_render(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_showDemoWindow(JNIEnv* env, jclass cls, jbooleanArray p_open);

// Window functions
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_begin(JNIEnv* env, jclass cls, jstring name, jbooleanArray p_open, jint flags);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_end(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_setNextWindowPos(JNIEnv* env, jclass cls, jfloat x, jfloat y, jint cond, jfloat pivot_x, jfloat pivot_y);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_setNextWindowSize(JNIEnv* env, jclass cls, jfloat width, jfloat height, jint cond);

// Layout
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_separator(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_sameLine(JNIEnv* env, jclass cls, jfloat offset_from_start_x, jfloat spacing);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_spacing(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_dummy(JNIEnv* env, jclass cls, jfloat width, jfloat height);

// Widgets
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_button(JNIEnv* env, jclass cls, jstring label, jfloat width, jfloat height);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_text(JNIEnv* env, jclass cls, jstring text);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_textColored(JNIEnv* env, jclass cls, jfloat r, jfloat g, jfloat b, jfloat a, jstring text);
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_checkbox(JNIEnv* env, jclass cls, jstring label, jbooleanArray v);
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_inputText(JNIEnv* env, jclass cls, jstring label, jcharArray buf, jint flags);
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_sliderFloat(JNIEnv* env, jclass cls, jstring label, jfloatArray v, jfloat v_min, jfloat v_max, jstring format, jint flags);

// Menus
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_beginMainMenuBar(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_endMainMenuBar(JNIEnv* env, jclass cls);
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_beginMenu(JNIEnv* env, jclass cls, jstring label, jboolean enabled);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_endMenu(JNIEnv* env, jclass cls);
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_menuItem(JNIEnv* env, jclass cls, jstring label, jstring shortcut, jboolean selected, jboolean enabled);

// Popups
JNIEXPORT jboolean JNICALL Java_com_secondyou_imgui_ImGui_beginPopup(JNIEnv* env, jclass cls, jstring str_id, jint flags);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_endPopup(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_openPopup(JNIEnv* env, jclass cls, jstring str_id, jint popup_flags);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_closeCurrentPopup(JNIEnv* env, jclass cls);

// Tooltips
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_beginTooltip(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_endTooltip(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_setTooltip(JNIEnv* env, jclass cls, jstring text);

// Drawing
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_pushStyleColor(JNIEnv* env, jclass cls, jint idx, jfloat r, jfloat g, jfloat b, jfloat a);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_popStyleColor(JNIEnv* env, jclass cls, jint count);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_pushStyleVar(JNIEnv* env, jclass cls, jint idx, jfloat val);
JNIEXPORT void JNICALL Java_com_secondyou_imgui_ImGui_popStyleVar(JNIEnv* env, jclass cls, jint count);

} // extern "C"
