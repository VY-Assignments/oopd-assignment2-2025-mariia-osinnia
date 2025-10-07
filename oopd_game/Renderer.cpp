#include "Renderer.h"
#include "IRenderable.h"
void Renderer::draw()
{
	getRenderable();
	window.clear();
	for (const auto& r : renderable) {
		r->draw(window);
	}
	window.display();
}

void Renderer::getRenderable()
{
	renderable.clear();
	const auto& entities = entityManager.getEntities();
	for (const auto& e : entities) {
		if (IRenderable* r = dynamic_cast<IRenderable*>(e.get())) {
			renderable.push_back(r);
		}
	}
}


