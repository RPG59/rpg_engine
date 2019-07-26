#include "Shader.h"

namespace graphics {
	Shader::Shader(const char* vsPath, const char* fsPath)
	{
		vsId = CreateShader(GL_VERTEX_SHADER, LoadShader(vsPath).c_str());
		fsId = CreateShader(GL_FRAGMENT_SHADER, LoadShader(fsPath).c_str());

		if (!CompileShader(vsId)) return;
		if (!CompileShader(fsId)) return;

		program = glCreateProgram();
		glAttachShader(program, vsId);
		glAttachShader(program, fsId);

		glValidateProgram(program);
		glLinkProgram(program);

		glDeleteShader(vsId);
		glDeleteShader(fsId);
	}

	std::string Shader::LoadShader(const char* shaderPath) {
		std::fstream file(shaderPath);
		std::string result((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		return result;
	}

	uint32_t Shader::CreateShader(int shaderType, const char* shaderSource) {
		uint32_t shaderId = glCreateShader(shaderType);
		const char* source = shaderSource;

		glShaderSource(shaderId, 1, &source, nullptr);
		return shaderId;
	}

	bool Shader::CompileShader(uint32_t& id) {
		int compileStatus;

		glCompileShader(id);
		glGetShaderiv(id, GL_COMPILE_STATUS, &compileStatus);
		if (compileStatus == GL_TRUE) {
			return true;
		}

		PrintCompileErrors(id);
		return false;
	}

	void Shader::PrintCompileErrors(uint32_t& id) {
		int length = 0;
		char buffer[512];

		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		glGetShaderInfoLog(id, length, &length, buffer);

		std::cout << "Shader compile ERRORS: " << buffer << std::endl;
	}

	void Shader::SetUniform(const char* name, float x)
	{
		if (!isEnable) Enable();
		int location = glGetUniformLocation(program, name);
		if (location != -1) {
			glGetUniformfv(program, location, &x);
		}
		else {
			std::cout << "Uniform float1 Error!" << std::endl;
		}
	}

	void Shader::SetUniform(const char* name, float4x4 matrix)
	{
		if (!isEnable) Enable();
		int location = glGetUniformLocation(program, name);
		if (location != -1) {
			glUniformMatrix4fv(location, 1, GL_FALSE, matrix.elements);
		}
		else {
			std::cout << "Uniform float4x4 Error!" << std::endl;
		}
	}

	void Shader::Enable()
	{
		glUseProgram(program);
		isEnable = true;
	}

	void Shader::Disable()
	{
		glUseProgram(0);
		isEnable = false;
	}
}