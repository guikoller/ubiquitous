#pragma once

#include <map>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class AnimationComponent
{
private:
	class Animation{
	public:
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationTimer;
		float timer;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;
		Animation(sf::Sprite& sprite,sf::Texture& texture_sheet,float animation_timer, int start_x, int start_y, int end_x, int end_y, int width, int height)
			: sprite(sprite), textureSheet(texture_sheet), animationTimer(animation_timer), width(width), height(height)
		{
			this->startRect = sf::IntRect(start_x, start_y, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(end_x, end_y, width, height);
			
			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
			
			timer = 0.f;
		}
		virtual ~Animation(){}

		//Function
		void update(const float& dt) {
			
			//UPDATE TIMER
			timer = 10.f * dt;
			if (timer >= animationTimer) {
				//RESET TIMER
				timer = 0.f;
				//ANimate
				if (currentRect != endRect) {
					this->currentRect.left += this->width;
				}
				else {
					this->currentRect.left = startRect.left;
				}

			}
		}
		void pause() {
		}
		void reset(){}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation> animation;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	~AnimationComponent();

	void addAnimation(const std::string key);

	void startAnimation(const std::string animation);
	void pauseAnimation(const std::string animation);
	void resetAnimation(const std::string animation);

	void update(const float& dt);
};

