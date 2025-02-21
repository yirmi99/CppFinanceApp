#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "FinanceManager.h"
#include "DownloadThread.h"
#include "../third_party/imgui/imgui.h"
#include "../third_party/imgui/backends/imgui_impl_glfw.h"
#include "../third_party/imgui/backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

class UIManager {
private:
    static DownloadThread downloadThread;

public:
    static void setup(GLFWwindow* window);
    static void render(FinanceManager& financeManager);
    static void shutdown();
};

#endif // UI_MANAGER_H