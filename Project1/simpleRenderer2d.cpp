#include "simpleRenderer2d.h"

namespace graphics {
	void SimpleRenderer2D::submit(const Renderable2D* renderable)
	{
		m_RanderQueue.push_back((StaticSprite*) renderable);
	}
	
	void SimpleRenderer2D::flush()
	{
		while (!m_RanderQueue.empty())
		{
			const StaticSprite* sprite = m_RanderQueue.front();
			float4x4 matrix;

			matrix.translate(sprite->getPosition());
			sprite->getVAO()->bind();
			sprite->getIBO()->bind();
			
			sprite->getShader().SetUniform("u_ModelMatrix", matrix);
			glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);
			m_RanderQueue.pop_front();
		}
	}
}