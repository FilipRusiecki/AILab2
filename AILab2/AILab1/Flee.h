#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
class Flee
{

public:
	sf::Texture m_fleeTexture; // texture used for alien
	sf::Sprite m_fleeSprite; // sprite used for alien

	void update(sf::Time& t_deltaTime, Player& t_player);
	void render(sf::RenderWindow& t_window);
	Flee();


private:
	float speed = 2.0f;
	void setupSprites();
	void flee(sf::Time& t_deltaTime, Player& t_player);
	sf::Vector2f vel;

};