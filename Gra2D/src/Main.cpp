#include <SFML/Graphics.hpp>
#include <vector>
#include "Camera.hpp"
#include "Object.hpp"
#include "DynamicObject.hpp"

std::map<std::string, sf::Texture> textures;

std::vector<Object*> objects;
std::vector<DynamicObject*> dynamicObjects;

void drawAll(sf::RenderWindow& window) {
    for (Object* object : objects) {
        object->draw(window);
	}
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 360), "Test");


    objects.push_back(new Object("polana_360x180", textures));
    objects.push_back(new Object("polana_360x180", textures,720));


    DynamicObject *player = new DynamicObject("ludzik", textures, { 200, -30 }, -100, 240);

    objects.push_back(player);

    dynamicObjects.push_back(player);

	Camera camera(player, sf::Vector2f(720, 360), sf::Vector2f(1420, 360));

	sf::Clock clock;
	float deltaTime;
	float spr = 4.0f; // do wywalenia

    while (window.isOpen())
    {
		deltaTime = clock.restart().asSeconds();
		spr -= deltaTime; // do wywalenia
        if (spr < 0) { // do wywalenia
            player->setVelocity({ 100, -10 }); // do wywalenia
		} // do wywalenia
        if (spr < -5) { // do wywalenia
            player->setVelocity({ -100, 20 }); // do wywalenia
        } // do wywalenia
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(164,221,219));

		player->update(deltaTime);

        drawAll(window);

		camera.follow(deltaTime);
		camera.apply(window);

        window.display();
    }

    for (Object* object : objects) {
        delete object;
    }
    objects.clear();
    dynamicObjects.clear();

    return 0;
}