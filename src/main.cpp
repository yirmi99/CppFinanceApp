#include <iostream>
#include <GLFW/glfw3.h>
#include "UIManager.h"
#include "FinanceManager.h"

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Personal Finance Tracker", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    UIManager::setup(window);

    FinanceManager financeManager;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        UIManager::render(financeManager);
        glfwSwapBuffers(window);
    }

    UIManager::shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
