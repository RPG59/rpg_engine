#pragma once

#include <vector>
#include <glew.h>
#include <mat4x4.hpp>



namespace graphics {
	class Renderable2D;
	class Renderer2D {
	protected:
		std::vector<glm::mat4x4> m_TransformationStack;
		glm::mat4x4* m_TransformationBack;
	protected:
		Renderer2D()
		{
			glm::mat4x4 mat(1.f);
			m_TransformationStack.push_back(mat);
			m_TransformationBack = &m_TransformationStack.back();
		}
	public:
		void push(glm::mat4x4 matrix, bool isOverride = false)
		{
			if (isOverride)
				m_TransformationStack.push_back(matrix);
			else
			{
				glm::mat4x4 mat = m_TransformationStack.back() * matrix;
				m_TransformationStack.push_back(mat);
			}
			m_TransformationBack = &m_TransformationStack.back();
		}

		void pop()
		{
			if (m_TransformationStack.size() > 1)
				m_TransformationStack.pop_back();
			m_TransformationBack = &m_TransformationStack.back();
		}


		virtual void begin() = 0;
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void end() = 0;
		virtual void flush() = 0;
	};
}
