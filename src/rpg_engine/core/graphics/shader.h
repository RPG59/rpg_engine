
#pragma once
#include <fstream>
#include <iostream>

#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>

#include <glew.h>

namespace graphics {
	class Shader {
	public:
		Shader() = default;
		Shader(const char* vsPath, const char* fsPath);
		~Shader();
		void SetUniform(const char*, float x);
		void SetUniform(const char*, int32_t count, float* pVal);
		void SetUniform(const char*, int32_t count, int32_t* pVal);
		void SetUniform(const char*, glm::mat4x4& vec);
		void SetUniform(const char*, const glm::vec2& vec);
		void SetUniform(const char*, glm::vec3& vec);
		void SetUniform(const char*, glm::vec4& vec);

		void Enable();
		void Disable();
	private:
		std::string LoadShader(const char* path);
		uint32_t CreateShader(int shaderType, const char* shaderSource);
		bool CompileShader(uint32_t& id);
		void PrintCompileErrors(uint32_t& id);

		uint32_t vsId;
		uint32_t fsId;
		uint32_t program;
		bool isEnable = false;
	};
}