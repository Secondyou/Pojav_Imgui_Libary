package com.secondyou.imgui;

public class ImGui {
    static {
        System.loadLibrary("imgui");
        System.loadLibrary("imgui_java");
        System.loadLibrary("imgui_sdl");
    }

    // Native methods
    public static native void init();
    public static native void shutdown();
    public static native void newFrame();
    public static native void render();
}
