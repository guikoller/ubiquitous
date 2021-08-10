#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window) {
	bg.setSize(sf::Vector2f(
			static_cast<float>(window.getSize().x), 
			static_cast<float>(window.getSize().y)
		)
	);
	
	bg.setFillColor(sf::Color(20, 20, 20, 100));
	
	container.setSize(sf::Vector2f(
			static_cast<float>(window.getSize().x) / 4.f,
			static_cast<float>(window.getSize().y)
		)
	);

	container.setFillColor(sf::Color(20, 20, 20, 200));
	container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - container.getSize().x / 2.f, 
		0.f
	);
}
PauseMenu::~PauseMenu() {
	
	auto it = buttons.begin();

	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}

}

void PauseMenu::update() {

}
void PauseMenu::render(sf::RenderTarget& target) {

	target.draw(bg);
	target.draw(container);

	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

}