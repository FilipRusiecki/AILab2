#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Alien
{
public:
	sf::Texture m_alienTexture; // texture used for alien
	sf::Sprite m_alienSprite; // sprite used for alien

	void update(sf::Time& t_deltaTime);
	void render(sf::RenderWindow& t_window);
	Alien();
	void kinematicWander(sf::Time& t_deltaTime);
private:
	float angle = 0.0f;
	float pi = 3.141592653589793238f;
	sf::Vector2f vel;
	float speed = 2.0f;
	float maxSpeed = 5.0f;
	int randomInt = 0;
	void setupSprites();
	void randomNum();
};

