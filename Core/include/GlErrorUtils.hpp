#pragma once

#include <glad/glad.h>

class GlErrorUtils {
public:
	static void check_shader_compilation(int shader_id);
	static void check_program_linking(int program_id);
	static void check_error();
	static void check_program(int expected_program);
	static void check_vao(int expected_vao);
	static void check_vbo(int expected_vbo);
	static void check_ebo(int expected_ebo);
	static void check_texture(int expected_texture);
	static void error_callback(int error, const char* description);

private:
	static bool check_status(GLenum pname, GLint expected);
};