#include <Window.hpp>
#include <data_structs/GraphicalObjects.hpp>
#include <GlErrorUtils.hpp>
#include <exception>
#include <iostream>

#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

GLFWwindow* Window::m_window = nullptr;

void Window::init(int width, int height, const char* title) {
    if (!glfwInit())
    {
        throw std::exception("Glfw failed to Init.");
    }

    glfwSetErrorCallback(GlErrorUtils::error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        throw std::exception("Window creation failed.");
    }

    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        throw std::exception("Glad failed to load.");
    }
}

void Window::config(WindowData config)
{
    if (m_window == nullptr)
        throw std::exception("Window was not initialized.");

    glfwSetKeyCallback(m_window, config.keyboardCallback);
    glfwSetFramebufferSizeCallback(m_window, frame_buffer_size_callback);
    glfwSwapInterval(config.vsync);
}

void Window::render() {
    if (m_window == nullptr)
        throw std::exception("Window was not initialized.");

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    GraphicalObjects::render();

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Window::close() {
    if (m_window == nullptr)
        throw std::exception("Window was not initialized.");
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool Window::isRunning() {
    if (m_window == nullptr)
        throw std::exception("Window was not initialized.");
    return !glfwWindowShouldClose(m_window);
}

void Window::frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}