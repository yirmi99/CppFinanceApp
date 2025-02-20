cmake_minimum_required(VERSION 3.10)
project(CppFinanceApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${CMAKE_SOURCE_DIR}/shared/HttpSrc")
include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_SOURCE_DIR}/third_party/imgui")
include_directories("${CMAKE_SOURCE_DIR}/third_party/glfw/include")
include_directories("/opt/homebrew/opt/openssl@3/include")

find_package(OpenSSL REQUIRED)
if(OPENSSL_FOUND)
    message(STATUS "Found OpenSSL: ${OPENSSL_INCLUDE_DIR} ${OPENSSL_LIBRARIES}")
else()
    message(FATAL_ERROR "OpenSSL not found!")
endif()

add_library(imgui STATIC
    third_party/imgui/imgui.cpp
    third_party/imgui/imgui_demo.cpp
    third_party/imgui/imgui_draw.cpp
    third_party/imgui/imgui_widgets.cpp
    third_party/imgui/imgui_tables.cpp
    third_party/imgui/backends/imgui_impl_glfw.cpp
    third_party/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC third_party/imgui third_party/imgui/backends)

add_subdirectory(third_party/glfw)

add_executable(CppFinanceApp
    src/main.cpp
    src/HttpClient.cpp
    src/DataStorage.cpp
    src/FinanceManager.cpp
    src/CurrencyAPI.cpp
    src/UIManager.cpp
)


target_link_libraries(CppFinanceApp PRIVATE imgui glfw OpenSSL::SSL OpenSSL::Crypto)

if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(OPENGL_LIBRARY OpenGL)
    target_link_libraries(CppFinanceApp PRIVATE ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${OPENGL_LIBRARY})
endif()
