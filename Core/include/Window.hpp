#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GraphicalObject.hpp>
#include <map>
#include <string>

#define RUNNING Window::isRunning()


typedef void (*KeyboardCallback)(GLFWwindow* window, int key, int scancode, int action, int mods);

struct WindowData {
	bool vsync;
	KeyboardCallback keyboardCallback;
};

class Window {

private:
	static GLFWwindow* m_window;
	static std::map<std::string, GraphicalObject> m_graphicalObjects;
	
public:
	static void init(int width, int height, const char* title);
	static void config(WindowData config);
	static void render();
	static void close();
    static bool isRunning();

private:
	static void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
};
