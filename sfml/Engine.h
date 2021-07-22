#pragma once
#include <SFML/Graphics.hpp>

namespace Engine {
	//Vectors and var types
	class Vector2f: public sf::Vector2f{
	public:
		using sf::Vector2f::Vector2f;
	};
	class Vector2i : public sf::Vector2i{
	public:
		using sf::Vector2i::Vector2i;
	};
	class FloatRect : public sf::FloatRect{
	public:
		using sf::FloatRect::FloatRect;
	};
	class IntRect : public sf::IntRect {
	public:
		using sf::IntRect::IntRect;
	};
	class Keyboard : public sf::Keyboard{
	public:
		using sf::Keyboard::Keyboard;
	};

	//Window, view and event stuff
	class RenderWindow : public sf::RenderWindow{
	public:
		using sf::RenderWindow::RenderWindow;
	};
	class VideoMode : public sf::VideoMode{
	public:
		using sf::VideoMode::VideoMode;
	};
	class View : public sf::View{
	public:
		using sf::View::View;
	};
	class Clock: public sf::Clock{
	public:
		using sf::Clock::Clock;
	};
	class Event : public sf::Event{
	public:
		using sf::Event::Event;
	};

	//Shapes
	class RectangleShape : sf::RectangleShape{
	public:
		using sf::RectangleShape::RectangleShape;

	};
	class CircleShape : public sf::CircleShape{
	public:
		using sf::CircleShape::CircleShape;
	};
	class Color : public sf::Color	{
	public:
		using sf::Color::Color;
	};

	//Texture and Sprites
	class Texture : public sf::Texture{
	public:
		using sf::Texture::Texture;
	};

	class Sprite : sf::Sprite{
	public:
		using sf::Sprite::Sprite;
	};
}