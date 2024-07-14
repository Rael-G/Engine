#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <structs/WindowData.hpp>
#include <glm/glm.hpp>
#include <string>

#define RUNNING Window::get_isRunning()

class Window {
private:
	static GLFWwindow* m_window;
	static bool m_isRunning;
	static WindowData m_config;
	static glm::ivec2 m_viewport;
	
public:
	static void init(int width, int height, const std::string& title);
	static void config();
	static void begin_render();
	static void end_render();
	static void close();
	static int key_status(int key);
	static bool get_isRunning();
	static void set_isRunning(bool isRunning);
	static void set_config(WindowData config);
	static glm::ivec2 getViewport();
	static void setViewport(glm::ivec2 viewport);

private:
	static void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};
