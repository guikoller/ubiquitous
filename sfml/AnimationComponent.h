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
		Animation(sf::Sprite& sprite,sf::Texture& texture_sheet,
			float animation_timer, 
			int start_frame_x, int start_frame_y, int frame_x, int frame_y, int width, int height)
			: sprite(sprite), textureSheet(texture_sheet), animationTimer(animation_timer), width(width), height(height)
		{
			this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(frame_x * width, frame_y * height, width, height);
			
			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
			
			timer = 0.f;
		}
		virtual ~Animation(){}

		//Function
		void play(const float& dt) {
			
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
					timer = 0.f;
					reset();
				}

			}
		}
		
		void reset(){
			currentRect.left = startRect.left
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animation;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	~AnimationComponent();

	void addAnimation(const std::string key, sf::Sprite& sprite, sf::Texture& texture_sheet, float animation_timer, int start_frame_x, int start_frame_y, int frame_x, int frame_y, int width, int height);

	void play(const std::string key, const float& dt);
};

