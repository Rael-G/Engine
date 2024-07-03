#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <ProgramShader.hpp>
#include <VertexArrayObject.hpp>
#include <structs/Shader.hpp>
#include <enums/ShaderType.hpp>
#include <GraphicalObject.hpp>

static void error_callback(int error, const char* description)
{
    std::cerr << "Glfw Error: " << error << ". " << description << std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

std::vector<float> vertices = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};

std::vector<unsigned int> indices = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

const char* vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

Shader vertex{ NULL, vertexShaderSource, ShaderType::Vertex };
Shader fragment{ NULL, fragmentShaderSource, ShaderType::Fragment };

ProgramShader program{ { vertex, fragment } };
VertexArrayObject vao{ vertices, indices };

GraphicalObject square{ program, vao };

int main(void)
{
    if (!glfwInit())
    {
        throw std::exception("Glfw failed to Init.");
    }

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow(800, 600, "My Title", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::exception("Window creation failed.");
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        throw std::exception("Glad failed to load.");
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
    glfwSwapInterval(0);

    //wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    square.start();
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //
        square.render();
        //
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //glDeleteVertexArrays(1, &VAO);
    //glDeleteBuffers(1, &VBO);
    //glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}












//#include <iostream>
//#include <stdexcept>
//#define GLAD_GL_IMPLEMENTATION
//#include <glad/glad.h>
//#define GLFW_INCLUDE_NONE
//#include <GLFW/glfw3.h>
//#define ratio getRatio()
//
//#include <Node.hpp>
//
//using namespace std;
//
//static void error_callback(int error, const char* description);
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
//static void frame_buffer_size_callback(GLFWwindow* window, int width, int height);
//static void gen_VAO(unsigned int* VAO);
//static void render(unsigned int VAO, unsigned int program_id);
//float getRatio();
//static unsigned int program();
//
//struct Vector2
//{
//    int x;
//    int y;
//};
//
//struct Vector3
//{
//    float x;
//    float y;
//    float z;
//};
//
////struct Shader
////{
////    unsigned int id;
////    const char** source;
////};
//
//struct Program
//{
//    unsigned int id;
//    unsigned int vertex_id;
//    unsigned int fragment_id;
//};
//
//const Vector2 aspect_ratio{ 16 * 10, 9 * 10 };
//const int hd = 8;
//int scale = hd;
//int width = aspect_ratio.x * scale;
//int height = aspect_ratio.y * scale;
//bool vsync = true;
//
//float vertices[] = {
//     0.5f,  0.5f, 0.0f,  // top right
//     0.5f, -0.5f, 0.0f,  // bottom right
//    -0.5f, -0.5f, 0.0f,  // bottom left
//    -0.5f,  0.5f, 0.0f   // top left 
//};
//
//unsigned int indices[] = {  // note that we start from 0!
//    0, 1, 3,   // first triangle
//    1, 2, 3    // second triangle
//};
//
//const char* vertexShaderSource = 
//    "#version 330 core\n"
//    "layout (location = 0) in vec3 aPos;\n"
//    "void main()\n"
//    "{\n"
//    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//    "}\0";
//
//const char* fragmentShaderSource =
//    "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "void main()\n"
//    "{\n"
//    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//    "}\0";
//
//int main(void)
//{
//    if (!glfwInit())
//    {
//        throw exception("Glfw failed to Init.");
//    }
//
//    glfwSetErrorCallback(error_callback);
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    auto window = glfwCreateWindow(width, height, "My Title", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        throw exception("Window creation failed.");
//    }
//
//    glfwMakeContextCurrent(window);
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        glfwTerminate();
//        throw exception("Glad failed to load.");
//    }
//
//    glfwSetKeyCallback(window, key_callback);
//    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
//    glfwSwapInterval(vsync);
//
//    //wireframe
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    unsigned int program_id = program();
//    unsigned int VAO;
//    gen_VAO(&VAO);
//    while (!glfwWindowShouldClose(window))
//    {
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        //
//        render(VAO, program_id);
//        //
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(1, &VAO);
//    //glDeleteBuffers(1, &VBO);
//    //glDeleteProgram(shaderProgram);
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    
//    return 0;
//}
//
//static void error_callback(int error, const char* description)
//{
//    cerr << "Glfw Error: " << error << ". " << description << endl;
//}
//
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GLFW_TRUE);
//}
//
//static void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
//{
//
//    glViewport(0, 0, width, height);
//}
//
//static void gen_shader(Shader shader)
//{
//    glShaderSource(shader.id, 1, &shader.source, NULL);
//    glCompileShader(shader.id);
//
//    int success;
//    char infoLog[512];
//    glGetShaderiv(shader.id, GL_COMPILE_STATUS, &success);
//
//    if (!success)
//    {
//        glGetShaderInfoLog(shader.id, 512, NULL, infoLog);
//        throw exception(infoLog);
//    }
//}
//
//static unsigned int program()
//{
//    
//    Shader vertex{ glCreateShader(GL_VERTEX_SHADER), vertexShaderSource };
//    Shader fragment{ glCreateShader(GL_FRAGMENT_SHADER), fragmentShaderSource };
//    Program program{ glCreateProgram(), vertex.id, fragment.id };
//
//    auto message = "ERROR::SHADER::COMPILATION_FAILED\n";
//    try {
//        gen_shader(vertex);
//    }
//    catch(exception e){
//        cout << message << "VERTEX:\n" << e.what() << endl;
//    }
//    try {
//        gen_shader(fragment);
//    }
//    catch (exception e) {
//        cout << message << "FRAGMENT:\n" << e.what() << endl;
//    }
//
//    glAttachShader(program.id, program.vertex_id);
//    glAttachShader(program.id, program.fragment_id);
//    glLinkProgram(program.id);
//
//    int success;
//    char infoLog[512];
//    glGetProgramiv(program.id, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(program.id, 512, NULL, infoLog);
//        cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
//    }
//
//    glDeleteShader(program.vertex_id);
//    glDeleteShader(program.fragment_id);
//
//    return program.id;
//}
//
//static void render(unsigned int VAO, unsigned int program_id)
//{
//    glUseProgram(program_id);
//    glBindVertexArray(VAO);
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//    glBindVertexArray(0);
//    /*glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);*/
//}
//
//static void gen_VAO(unsigned int* VAO)
//{
//    glGenVertexArrays(1, VAO);
//    unsigned int VBO;
//    glGenBuffers(1, &VBO);
//    unsigned int EBO;
//    glGenBuffers(1, &EBO);
//
//    glBindVertexArray(*VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//}
//
//float getRatio()
//{
//    return width / height;
//}