cmake_minimum_required(VERSION 3.22.1)
project(imgui_java)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ImGui source files
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
)

# ImGui Java binding sources
set(IMGUI_JAVA_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jni/imgui_java.cpp
)

# Create shared libraries
add_library(imgui SHARED ${IMGUI_SOURCES})
add_library(imgui_java SHARED ${IMGUI_JAVA_SOURCES})

# Include directories
target_include_directories(imgui PUBLIC ${IMGUI_DIR})
target_include_directories(imgui_java PUBLIC 
    ${IMGUI_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jni
)

# Link libraries
target_link_libraries(imgui_java
    imgui
    android
    log
)

# Set compile definitions
target_compile_definitions(imgui_java PRIVATE IMGUI_IMPL_OPENGL_ES2)
