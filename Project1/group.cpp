#include "group.h"

namespace graphics {
	Group::Group(float4x4& matrix)
		: m_TransformationMatrix(matrix)
	{

	}

	void Group::add(Renderable2D* pRenderable)
	{
		m_Renderables.push_back(pRenderable);
	}

	void Group::submit(Renderer2D* renderer)
	{
		renderer->push(m_TransformationMatrix);

		for (Renderable2D* renderable : m_Renderables)
			renderable->submit(renderer);

		renderer->pop();
	}
}