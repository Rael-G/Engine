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
#include <Texture2DObj.hpp>
#include <Window.hpp>
#include <data_structs/GraphicalObjects.hpp>
#include <structs/Transform3D.hpp>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

std::vector<float> vertices = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};


std::vector<unsigned int> indices = {
    0, 1, 3,
    1, 2, 3
};

std::vector<float> texCoords = {
    0.0f, 0.0f,  // lower-left corner  
    1.0f, 0.0f,  // lower-right corner
    0.5f, 1.0f   // top-center corner
};

WindowData config { true, key_callback };

const char* vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "layout (location = 2) in vec2 aTexCoord;\n"
    "out vec3 ourColor;\n"
    "out vec2 texCoord;\n"
    "uniform mat4 transform;"
    "void main()\n"
    "{\n"
    "   gl_Position = transform * vec4(aPos, 1.0f);\n"
    "   ourColor = aColor;\n"
    "   texCoord = aTexCoord;\n"
    "}\0";

const char* fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "in vec2 texCoord;\n"
    "uniform sampler2D ourTexture;\n"
    "void main()\n"
    "{\n"
    "    FragColor = texture(ourTexture, texCoord) * vec4(ourColor, 1.0);  \n"
    "}\0";

Shader vertex{ NULL, vertexShaderSource, ShaderType::Vertex };
Shader fragment{ NULL, fragmentShaderSource, ShaderType::Fragment };
const char* path = "C:/Users/israe/OneDrive/Imagens/232d0491ced5766623d5a10011c3a29f.jpg";
ProgramShader program{ { vertex, fragment } };
VAOTexture2D vao{ vertices, indices, texCoords, path };
Transform3D transform{
    glm::vec3{ 0.0f, 0.0f, 0.0f },
    glm::vec3{ 0.0f, 0.0f, glm::radians(90.0f)},
    glm::vec3{ 0.5f, 0.5f, 0.5f }
};
Texture2DObj square{ program, vao, transform };

int main(void) {
    Window::init(800, 600, "Minha janela");
    Window::config(config);

    GraphicalObjects::add("square", &square);
    square.m_transform.position.y = -0.5f;

    while (RUNNING) {
        square.m_transform.rotation.z = (float)glfwGetTime();
        Window::render();
    }

    return 0;
}