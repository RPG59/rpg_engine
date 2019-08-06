#include "layer.h"

namespace graphics {
	Layer::Layer(Renderer2D* renderer, Shader* shader, glm::mat4x4 projectionMatrix) 
		: m_Renderer(renderer), m_Shader(shader), m_ProjectionMatrix(projectionMatrix)
	{
		m_Shader->Enable();
		m_Shader->SetUniform("u_ProjectionMatrix", m_ProjectionMatrix);
		m_Shader->Disable();
	}

	Layer::~Layer()
	{
		delete m_Shader;
		delete m_Renderer;
		for (int i = 0; i < m_Renderables.size(); ++i)
		{
			delete m_Renderables[i];
		}
	}

	void Layer::add(Renderable2D* renderable)
	{
		m_Renderables.push_back(renderable);
	}

	void Layer::render()
	{
		m_Shader->Enable();

		m_Renderer->begin();
		for (Renderable2D* renderable : m_Renderables)
		{
			renderable->submit(m_Renderer);
		}
		m_Renderer->end();

		m_Renderer->flush();

		m_Shader->Disable();
	}
}

