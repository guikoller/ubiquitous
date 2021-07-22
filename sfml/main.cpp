#include "Engine.h"

int main()
{
    Engine::RenderWindow window(Engine::VideoMode(200, 200), "SFML works!");
    Engine::CircleShape shape(100.f);
    shape.setFillColor(Engine::Color::Green);

    while (window.isOpen())
    {
        Engine::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Engine::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}