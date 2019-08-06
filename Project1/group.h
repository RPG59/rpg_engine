#pragma once

#include <glm/mat4x4.hpp>
#include "renderable2d.h"

namespace graphics {
	class Group : public Renderable2D
	{
	private:
		std::vector<Renderable2D*> m_Renderables;
		glm::mat4x4 m_TransformationMatrix;
	public:
		Group(glm::mat4x4& matrix);
		void submit(Renderer2D* renderer) override;
		void add(Renderable2D* renderable);
	};
}
