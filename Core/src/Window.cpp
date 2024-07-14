#include <Window.hpp>
#include <GlErrorUtils.hpp>
#include <iostream>

#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

GLFWwindow* Window::m_window = nullptr;
bool Window::m_isRunning = false;
WindowData Window::m_config{};
glm::ivec2 Window::m_viewport{};

void Window::init(int width, int height, const std::string& title) {
    set_isRunning(true);

    if (!glfwInit())
    {
        throw std::runtime_error("Glfw failed to Init.");
    }

    glfwSetErrorCallback(GlErrorUtils::error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_viewport = { width, height };
    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        throw std::runtime_error("Window creation failed.");
    }

    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        throw std::runtime_error("Glad failed to load.");
    }
}

void Window::config()
{
    if (m_window == nullptr)
        throw std::runtime_error("Window was not initialized.");

    glfwSetKeyCallback(m_window, key_callback);
    glfwSetCursorPosCallback(m_window, mouse_callback);
    glfwSetFramebufferSizeCallback(m_window, frame_buffer_size_callback);
    glfwSwapInterval(m_config.vsync);
    if (m_config.disableCursor)
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetScrollCallback(m_window, scroll_callback);
}

void Window::begin_render() {
    if (m_window == nullptr)
        throw std::runtime_error("Window was not initialized.");

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void Window::end_render() {
    GlErrorUtils::check_error();

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Window::close() {
    if (m_window == nullptr)
        throw std::runtime_error("Window was not initialized.");
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool Window::get_isRunning() {
    if (m_window == nullptr)
        return false;
    return !glfwWindowShouldClose(m_window) && m_isRunning;
}

void Window::set_isRunning(bool isRunning) {
    m_isRunning = isRunning;
}

void Window::set_config(WindowData config) {
    m_config = config;
}

int Window::key_status(int key) {
    if (m_window == nullptr)
        throw std::runtime_error("Window was not initialized.");
    return glfwGetKey(m_window, key);
}

void Window::frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
    m_viewport = { width, height };
    glViewport(0, 0, width, height);
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (m_config.keyCallback != nullptr)
        m_config.keyCallback(key, scancode, action, mods);
}

void Window::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (m_config.mouseCallback != nullptr)
        m_config.mouseCallback(xpos, ypos);
}

void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    if (m_config.scrollCalback != nullptr)
        m_config.scrollCalback(xoffset, yoffset);
}

glm::ivec2 Window::getViewport() {
    return m_viewport;
}
void Window::setViewport(glm::ivec2 viewport) {
    m_viewport = viewport;
    glViewport(0, 0, viewport.x, viewport.y);
}