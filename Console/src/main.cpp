#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <ProgramShader.hpp>
#include <TestVAO.hpp>
#include <structs/Shader.hpp>
#include <enums/ShaderType.hpp>
#include <TestObj.hpp>
#include <Window.hpp>
#include <data_structs/GraphicalObjects.hpp>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}


std::vector<float> vertices = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
};


std::vector<unsigned int> indices = {
    0, 1, 2
};

WindowData config { true, key_callback };

const char* vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   ourColor = aColor;\n"
    "}\0";

const char* fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(ourColor, 1.0);\n"
    "}\0";

Shader vertex{ NULL, vertexShaderSource, ShaderType::Vertex };
Shader fragment{ NULL, fragmentShaderSource, ShaderType::Fragment };

ProgramShader program{ { vertex, fragment } };
TestVAO vao{ vertices, indices };
TestObj square{ program, vao };

int main(void) {
    Window::init(800, 600, "Minha janela");
    Window::config(config);

    GraphicalObjects::add("square", &square);

    while (RUNNING) {
        Window::render();
    }

    return 0;
}