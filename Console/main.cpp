#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <ProgramShader.hpp>
#include <structs/Shader.hpp>
#include <enums/ShaderType.hpp>
#include <Cube2DObj.hpp>
#include <Window.hpp>
#include <data_structs/GraphicalObjects.hpp>
#include <structs/Transform3D.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Transformer.hpp>
#include <Camera.hpp>
#include <Perspective.hpp>

float width = 800;
float height = 600;

std::vector<float> vertices = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};


static void key_callback(int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        Window::set_isRunning(false);
}


float lastX = width / 2, lastY = height / 2;
float sensitivity = 0.1f;

float pitch = 0;
float yaw = -90;

auto front = glm::vec3(0.0f, 0.0f, 1.0f);
bool firstMouse = true;
Perspective* perspective = new Perspective(45.0, width / height, 0.5, 100.0);


void scroll_callback(double xoffset, double yoffset)
{
    auto fov = perspective->m_fov;
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;

    perspective->m_fov = fov;
}

static void mouse_callback(double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction{};
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(direction);
}

static void proccess_input(double deltaTime) {
    
    float speed = 10 * deltaTime;
    if ((Window::key_status(GLFW_KEY_W) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
        Camera::m_position += front * speed;
    if ((Window::key_status(GLFW_KEY_S) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
        Camera::m_position += front * -speed;
    if ((Window::key_status(GLFW_KEY_A) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
        Camera::m_position += glm::normalize(glm::cross(front, Camera::m_up)) * -speed;
    if ((Window::key_status(GLFW_KEY_D) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
        Camera::m_position += glm::normalize(glm::cross(front, Camera::m_up)) * speed;
    if ((Window::key_status(GLFW_KEY_E) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
        Camera::m_position += Camera::m_up * speed;
    if ((Window::key_status(GLFW_KEY_Q) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
        Camera::m_position += Camera::m_up * -speed;
}

WindowData config { true, false, key_callback, mouse_callback, scroll_callback };

const char* vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "out vec2 texCoord;\n"
    "uniform mat4 mvp;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = mvp * vec4(aPos, 1.0f);\n"
    "   texCoord = aTexCoord;\n"
    "}\0";

const char* fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec2 texCoord;\n"
    "uniform sampler2D ourTexture;\n"
    "void main()\n"
    "{\n"
    "    FragColor = texture(ourTexture, texCoord);  \n"
    "}\0";

Shader vertex{ NULL, vertexShaderSource, ShaderType::Vertex };
Shader fragment{ NULL, fragmentShaderSource, ShaderType::Fragment };
const char* path = "C:/Users/israe/OneDrive/Imagens/232d0491ced5766623d5a10011c3a29f.jpg";
ProgramShader program{ { vertex, fragment } };
VAOCube2D vao{ vertices, path };
Transform3D transform1{
    glm::vec3{ 0.0f, 0.0f, 0.0f },
    glm::vec3{ 0.0f, 0.0f, 0.0f },
    glm::vec3{ 0.5f, 0.5f, 0.5f }
};
Transform3D transform2{
    glm::vec3{1.0f,  1.0f, -1.0f },
    glm::vec3{ 0.0f, 0.0f, 0.0f },
    glm::vec3{ 0.5f, 0.5f, 0.5f }
};
Transform3D transform3{
    glm::vec3{ -1.f, -1.0f, -1.0f },
    glm::vec3{ 0.0f, 0.0f, 0.0f },
    glm::vec3{ 0.5f, 0.5f, 0.5f }
};

glm::mat4 model = glm::mat4(1.0f);
glm::mat4 view = glm::mat4(1.0f);
glm::mat4 projection;

Cube2DObj cube1{ program, vao, transform1 };
Cube2DObj cube2{ program, vao, transform2 };
Cube2DObj cube3{ program, vao, transform3 };

int main(void) {
    Camera::m_frustum = perspective;
    Window::init(width, height, "Minha janela");
    Window::config(config);

    GraphicalObjects::add("cube1", &cube1);
    GraphicalObjects::add("cube2", &cube2);
    GraphicalObjects::add("cube3", &cube3);
    
    float lastFrameTime = glfwGetTime();
    while (RUNNING) {
        double currentFrameTime = glfwGetTime();
        double deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
        proccess_input(deltaTime);
        auto target = Camera::m_position + front;
        Camera::m_target = target;
        cube1.m_transform.position.x += 0.00001;
        cube1.m_transform.rotation.y += 0.0001;
        Window::render();
    }

    return 0;
}