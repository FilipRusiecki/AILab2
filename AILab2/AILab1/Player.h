#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{

public:
	sf::Texture m_playerTexture; // texture used for player
	sf::Sprite m_playerSprite; // sprite used for player
	Player();
	void update();
	void reder(sf::RenderWindow& t_window);

private:

	float speedX = 10.0f;
	float speedY = 0.0f;
	float maxSpeedRight = 15.0f;
	float maxSpeedLeft = -15.0f;
	bool turnLeft = false;
	bool turnRight = false;
	void changeDirection();
	void setupSprites();
	void playerMovement();

};

