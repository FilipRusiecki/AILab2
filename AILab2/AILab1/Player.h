#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{

public:
	sf::Texture m_playerTexture; // texture used for player
	sf::Sprite m_playerSprite; // sprite used for player
	sf::VertexArray playerLine{ sf::Lines };
	sf::CircleShape linePoint;
	sf::CircleShape radius;
	sf::CircleShape radiusSmaller;

	float radiusF= 100.0f;
	float radiusFSmall = 30.0f;

	Player();
	void update(sf::Time& t_deltaTime);
	void reder(sf::RenderWindow& t_window);

private:
	sf::Vector2f vel;
	sf::Vector2f vel2;
	float pi = 3.141592653589793238f;
	float speed = 0.0f;
	float speedX = 10.0f;
	float speedY = 0.0f;
	float maxSpeedRight = 8.0f;
	float maxSpeedLeft = -8.0f;
	float rotation = 90;
	bool turnLeft = false;
	bool turnRight = false;
	void changeDirection();
	void setupSprites();
	void playerMovement(sf::Time& t_deltaTime);

};

