#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Alien
{
public:
	sf::Texture m_alienTexture; // texture used for alien
	sf::Sprite m_alienSprite; // sprite used for alien
	void update();
	void render(sf::RenderWindow& t_window);
	Alien();

private:
	
	void setupSprites();
	void kinematicWander();

};

