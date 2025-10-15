#include "Renderer.h"
#include "IRenderable.h"
void Renderer::draw()
{
	window.clear();
	for (auto obj : renderable) {
		drawFrame(obj->getRenderData(), window);
	}
	window.display();
}

void Renderer::drawFrame(const RenderData& renderData, sf::RenderWindow& window)
{
	if (renderData.shape == "rectangle") {
		sf::RectangleShape rect;
		rect.setOrigin(renderData.size.x / 2, renderData.size.y / 2);
		rect.setPosition(renderData.position.x, renderData.position.y);
		rect.setSize({ renderData.size.x, renderData.size.y });
		std::string color = renderData.color;
		if (color == "yellow"){
			rect.setFillColor(sf::Color::Yellow);
		}
		else if (color == "green") {
			rect.setFillColor(sf::Color::Green);
		}
		rect.setRotation(renderData.rotation);
		window.draw(rect);
	}
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


