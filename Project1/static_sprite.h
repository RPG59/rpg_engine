#pragma once

#include "renderable2d.h"

namespace graphics {
	class StaticSprite : public Renderable2D
	{
	private:
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
		Shader& m_Shader;
	public:
		StaticSprite(float x, float y, float width, float height, float4 color, Shader& shader);
		~StaticSprite();


		inline Shader& getShader() const { return m_Shader; }

		inline VertexArray* getVAO() const { return m_VertexArray; }
		inline IndexBuffer* getIBO() const { return m_IndexBuffer; }
	};
}
