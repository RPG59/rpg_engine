#pragma once

#include <vector>
#include <GLEW/glew.h>

#include "Math.h"



namespace graphics {
	class Renderable2D;
	class Renderer2D {
	protected:
		std::vector<float4x4> m_TransformationStack;
		float4x4* m_TransformationBack;
	protected:
		Renderer2D()
		{
			float4x4 mat;
			mat.identity();
			m_TransformationStack.push_back(mat);
			m_TransformationBack = &m_TransformationStack.back();
		}
	public:
		void push(float4x4 matrix, bool isOverride = false)
		{
			if (isOverride)
				m_TransformationStack.push_back(matrix);
			else
			{
				float4x4 mat = m_TransformationStack.back();
				mat.multiply(matrix);
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
