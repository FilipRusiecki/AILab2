#include "Flee.h"

Flee::Flee()
{
	setupSprites();
}
void Flee::update(sf::Time& t_deltaTime, Player& t_player)
{
}

void Flee::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_fleeSprite);
}


void Flee::setupSprites()
{
	if (!m_fleeTexture.loadFromFile("ASSETS\\IMAGES\\fleeShip.png"))
	{

		std::cout << "problem loading player" << std::endl;
	}

	m_fleeSprite.setTexture(m_fleeTexture);

	//college pc
	//m_playerSprite.setPosition(1800.0f, 1800.0f);
	//m_playerSprite.scale(5.0f, 5.0f);

	//my pc 
	m_fleeSprite.setPosition(100.0f, 200.0f);
	m_fleeSprite.scale(3.0f, 3.0f);
	m_fleeSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_fleeSprite.setOrigin(16.0f, 16.0f);
}

void Flee::flee(sf::Time& t_deltaTime, Player& t_player)
{
}
