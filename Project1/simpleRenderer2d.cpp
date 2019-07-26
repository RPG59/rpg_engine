#include "simpleRenderer2d.h"

namespace graphics {
	void SimpleRenderer2D::submit(const Renderable2D* renderable)
	{
		m_RanderQueue.push_back(renderable);
	}
	
	void SimpleRenderer2D::flush()
	{
		while (!m_RanderQueue.empty())
		{
			const Renderable2D* renderable = m_RanderQueue.front();
			float4x4 matrix;

			matrix.translate(renderable->getPosition());
			renderable->getVAO()->bind();
			renderable->getIBO()->bind();
			
			//renderable->getShader().SetUniform("ml_matrix", matrix);
			glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);
			m_RanderQueue.pop_front();
		}
	}
}