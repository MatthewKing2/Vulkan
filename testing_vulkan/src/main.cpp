// #include <vulkan/vulkan.h>  //Include the Vulkan header which provides the functions, structures and enumerations.  
#define GLFW_INCLUDE_VULKAN     // Replace vulkan header with the GLFW one (this automaticlaly loads the vulkan one)
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {
private:
    GLFWwindow* window;             // Stores pointer to the window we writing stuff to
    const uint32_t WIDTH = 800;     // Window Width
    const uint32_t HEIGHT = 600;    // Window Height

public:
    void run() {
        initWindow();   // Initalized the window that we write to
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    void initWindow() {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);   // Init the GLFW library. Tell it not to use OpenGL API (we doing vulkan)
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);     // Diabling resizable windows b/c they require extra work

        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);    // Args = Width, Height, Title, Monitor*, OpenGL*. 
    }

    void initVulkan() {

    }

    // This is the main (forever) loop of the HellowTriangleApplication (render frames)
    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {    // while you should not close the window: 
            glfwPollEvents();                       // polls for events, like clicking the X button
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);      // destory the window
        glfwTerminate();                // turn off glfw 
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}