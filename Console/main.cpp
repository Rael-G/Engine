//#define GLAD_GL_IMPLEMENTATION
//#include <glad/glad.h>
//#define GLFW_INCLUDE_NONE
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//#include <vector>
//#include <ProgramShader.hpp>
//#include <structs/Shader.hpp>
//#include <enums/ShaderType.hpp>
//#include <unit/Cube2DObj.hpp>
//#include <Window.hpp>
//#include <data_structs/RenderMap.hpp>
//#include <structs/Transform3D.hpp>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <Transformer.hpp>
//#include <camera/Camera.hpp>
//#include <camera/Perspective.hpp>
//#include <camera/Orthographic.hpp>
//#include <structs/WindowData.hpp>
//#include <memory>
////
////float width = 800;
////float height = 600;
////
//std::vector<float> vertices = {
//    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//};
////
////
////static void key_callback(int key, int scancode, int action, int mods)
////{
////    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
////        Window::set_isRunning(false);
////}
////
////
////float lastX = width / 2, lastY = height / 2;
////float sensitivity = 0.1f;
////
////float pitch = 0;
////float yaw = -90;
////
////auto front = glm::vec3(0.0f, 0.0f, 1.0f);
////bool firstMouse = true;
//Perspective* perspective = new Perspective(45.0, 800 / 600, 0.5, 100.0);
////
////
////void scroll_callback(double xoffset, double yoffset)
////{
////    auto fov = perspective->m_fov;
////    fov -= (float)yoffset;
////    if (fov < 1.0f)
////        fov = 1.0f;
////    if (fov > 45.0f)
////        fov = 45.0f;
////
////    perspective->m_fov = fov;
////}
////
////static void mouse_callback(double xpos, double ypos)
////{
////    if (firstMouse)
////    {
////        lastX = xpos;
////        lastY = ypos;
////        firstMouse = false;
////    }
////
////    float xoffset = xpos - lastX;
////    float yoffset = lastY - ypos;
////    lastX = xpos;
////    lastY = ypos;
////    xoffset *= sensitivity;
////    yoffset *= sensitivity;
////
////    yaw += xoffset;
////    pitch += yoffset;
////
////    if (pitch > 89.0f)
////        pitch = 89.0f;
////    if (pitch < -89.0f)
////        pitch = -89.0f;
////
////    glm::vec3 direction{};
////    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
////    direction.y = sin(glm::radians(pitch));
////    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
////    front = glm::normalize(direction);
////}
////
////static void proccess_input(double deltaTime) {
////    
////    float speed = 10 * deltaTime;
////    if ((Window::key_status(GLFW_KEY_W) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
////        Camera::m_position += front * speed;
////    if ((Window::key_status(GLFW_KEY_S) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
////        Camera::m_position += front * -speed;
////    if ((Window::key_status(GLFW_KEY_A) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
////        Camera::m_position += glm::normalize(glm::cross(front, Camera::m_up)) * -speed;
////    if ((Window::key_status(GLFW_KEY_D) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
////        Camera::m_position += glm::normalize(glm::cross(front, Camera::m_up)) * speed;
////    if ((Window::key_status(GLFW_KEY_E) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
////        Camera::m_position += Camera::m_up * speed;
////    if ((Window::key_status(GLFW_KEY_Q) & (GLFW_PRESS | GLFW_REPEAT)) > 0)
////        Camera::m_position += Camera::m_up * -speed;
////}
////
////WindowData config { true, false, key_callback, mouse_callback, scroll_callback };
////
//const char* vertexShaderSource = 
//    "#version 330 core\n"
//    "layout (location = 0) in vec3 aPos;\n"
//    "layout (location = 1) in vec2 aTexCoord;\n"
//    "out vec2 texCoord;\n"
//    "uniform mat4 mvp;\n"
//    "void main()\n"
//    "{\n"
//    "   gl_Position = mvp * vec4(aPos, 1.0f);\n"
//    "   texCoord = aTexCoord;\n"
//    "}\0";
//
//const char* fragmentShaderSource =
//    "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "in vec2 texCoord;\n"
//    "uniform sampler2D ourTexture;\n"
//    "void main()\n"
//    "{\n"
//    "    FragColor = texture(ourTexture, texCoord);  \n"
//    "}\0";
////
//Shader vertex{ 0, vertexShaderSource, ShaderType::Vertex };
//Shader fragment{ 0, fragmentShaderSource, ShaderType::Fragment };
//const char* path = "C:/Users/israe/OneDrive/Imagens/232d0491ced5766623d5a10011c3a29f.jpg";
//ProgramShader program{ { vertex, fragment } };
//VAOCube2D vao{ vertices, path };
//Transform3D transform1{
//    glm::vec3{ 0.0f, 0.0f, 0.0f },
//    glm::vec3{ 0.0f, 0.0f, 0.0f },
//    glm::vec3{300.5f, 300.5f, 300.5f }
//};
//Transform3D transform2{
//    glm::vec3{1.0f,  1.0f, -1.0f },
//    glm::vec3{ 0.0f, 0.0f, 0.0f },
//    glm::vec3{ 0.5f, 0.5f, 0.5f }
//};
//Transform3D transform3{
//    glm::vec3{ -1.f, -1.0f, -1.0f },
//    glm::vec3{ 0.0f, 0.0f, 0.0f },
//    glm::vec3{ 0.5f, 0.5f, 0.5f }
//};
////
////glm::mat4 model = glm::mat4(1.0f);
////glm::mat4 view = glm::mat4(1.0f);
////glm::mat4 projection;
////
//std::unique_ptr<Cube2DObj> cube1 = std::make_unique<Cube2DObj>(program, vao, transform1);
//std::unique_ptr<Cube2DObj> cube2 = std::make_unique<Cube2DObj>( program, vao, transform2 );
//std::unique_ptr<Cube2DObj> cube3 = std::make_unique<Cube2DObj>( program, vao, transform3 );
////
//
//auto ortho = new Orthographic(0.0, 800.0, 000.0, 600.0, 0, 500000.0);
//
//int main(void) {
//    Camera::m_frustum = ortho;
//    //Window::set_config(config);
//    Window::init(800, 600, "Minha janela");
//    Window::config();
//
//    RenderMap::add("cube1", std::move(cube1));
//    RenderMap::add("cube2", std::move(cube2));
//    RenderMap::add("cube3", std::move(cube3));
//    
//    float lastFrameTime = glfwGetTime();
//    while (RUNNING) {
//        double currentFrameTime = glfwGetTime();
//        double deltaTime = currentFrameTime - lastFrameTime;
//        lastFrameTime = currentFrameTime;
//        //proccess_input(deltaTime);
//        //auto target = Camera::m_position + front;
//        //Camera::m_target = target;
//        //cube1.m_transform.position.x += 0.00001;
//        //cube1.m_transform.rotation.y += 0.0001;
//        Window::render();
//    }
//
//    return 0;
//}
#include <WindowApi.hpp>
#include <iostream>
#include <Assets.hpp>
#include <unit/Rectangle.hpp>
#include <RenderMap.hpp>
#include <Window.hpp>
#include <RenderMapApi.hpp>
#include <camera/Orthographic.hpp>
#include <camera/Camera.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <structs/Transform3D.hpp>
#include <GlErrorUtils.hpp>

static void key_callback(int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		Window::set_isRunning(false);
}

WindowData data{
};

int width = 800;
int height = 600;
const char* title = "Test from main";

Transform3D transform{
{
	400.0, 300.0, 0.0
},
{
	0.0, 0.0, 0.0
},
{
	1.0, 1.0, 0.0
}
};

float color[4]{
	1.0, 0.0, 0.0, 1.0
};



glm::mat4 projection(float left, float right, float bottom, float top, float near, float far) {
	return glm::ortho(left, right, bottom, top, near, far);
}

glm::mat4 view(glm::vec3 position, glm::vec3 target, glm::vec3 up) {
	//return glm::lookAt(position, target, up);
	return glm::translate(glm::mat4(1.0f), -position);
}

const glm::vec3 X_AXIS = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 Y_AXIS = glm::vec3(0.0f, 1.0f, 0.0f);
const glm::vec3 Z_AXIS = glm::vec3(0.0f, 0.0f, 1.0f);

glm::mat4 Transform(Transform3D transform3D) {
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::translate(transform, transform3D.position);
	transform = glm::rotate(transform, transform3D.rotation.x, X_AXIS);
	transform = glm::rotate(transform, transform3D.rotation.y, Y_AXIS);
	transform = glm::rotate(transform, transform3D.rotation.z, Z_AXIS);
	transform = glm::scale(transform, transform3D.scale);
	return transform;
}


//int main(void) {
//	Window::init(width, height, title);
//	data.keyCallback = key_callback;
//	Window::set_config(data);
//	Window::config();
//
//	Camera::m_frustum = new Orthographic(0.0, 800.0, 0.0, 600.0, -100.0, 100.0);
//	Camera::m_target.x += 100;
//	Camera::m_position.x += 100;
//	auto rect = std::make_unique<Rectangle>(transform, 1, 1, color);
//	RenderMap::add("rect", std::move(rect));
//	while (Window::get_isRunning()) {
//		Window::render();
//	}
//
//	Window::close();
//}

int main(void) {
	auto proj = projection(0.0, 800.0, 600.0, 0.0, -1.0, 10.0);
	auto vw = view({ 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f });
	double r = 0.0;
	auto model = Transform(Transform3D{ { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 0.0 } });
	auto mvpmatrix = proj * vw * model;
	auto mvp = glm::value_ptr(proj * vw * model);

	init(width, height, title);
	data.keyCallback = key_callback;
	set_config(data);
	config();

	add_rectangle("rect", mvp, 400, 300, color);
	while (get_is_running()) {
		begin_render();
		model = Transform(Transform3D{ { 0.0, 0.0, 0.0 }, { 0.0, 0.0, r += 0.0001 }, { 1.0, 1.0, 0.0 } });
		auto mvp = glm::value_ptr(proj * vw * model);
		update_rectangle("rect", mvp, 400, 300, color);

		render_unit("rect");
		end_render();
	}

	close();
}