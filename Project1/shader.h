
#pragma once
#include <fstream>
#include <iostream>

#include "Math.h"
#include <glew.h>

namespace graphics {
	class Shader {
	public:
		Shader() = default;
		Shader(const char* vsPath, const char* fsPath);
		void SetUniform(const char*, float x);
		void SetUniform(const char*, float4x4 vec);
		void SetUniform(const char*, float2 vec);
		void SetUniform(const char*, float3 vec);
		void SetUniform(const char*, float4 vec);

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