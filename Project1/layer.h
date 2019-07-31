#pragma once

#include "renderable2d.h"
#include "renderer2d.h"

namespace graphics {
	class Layer
	{
	protected:
		Renderer2D* m_Renderer;
		std::vector<Renderable2D*> m_Renderables;
		Shader* m_Shader;
		float4x4 m_ProjectionMatrix;
	public:
		Layer();
	protected:
		Layer(Renderer2D* renderer, Shader* shader, float4x4 projectionMatrix);
	public:
		virtual ~Layer();
		virtual void add(Renderable2D* renderable);
		virtual void render();
	};
}
