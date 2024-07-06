#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GraphicalObject.hpp>
#include <map>
#include <string>

#define RUNNING Window::get_isRunning()

typedef void (*KeyCallback)(int key, int scancode, int action, int mods);
typedef void (*MouseCallback)(double xpos, double ypos);
typedef void (*MouseCallback)(double xoffset, double yoffset);

struct WindowData {
	bool vsync;
	bool cursor;
	KeyCallback keyCallback;
	MouseCallback mouseCallback;
	MouseCallback scrollCalback;
};

class Window {
private:
	static GLFWwindow* m_window;
	static std::map<std::string, GraphicalObject> m_graphicalObjects;
	static bool m_isRunning;
	static WindowData m_config;
	
public:
	static void init(int width, int height, const char* title);
	static void config(WindowData config);
	static void render();
	static void close();
	static int key_status(int key);
	static bool get_isRunning();
	static void set_isRunning(bool isRunning);

private:
	static void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};
