#include "Alien.h"


Alien::Alien()
{
	setupSprites();
}

void Alien::update()
{
}

void Alien::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_alienSprite);
}

void Alien::setupSprites()
{
	if (!m_alienTexture.loadFromFile("ASSETS\\IMAGES\\alienShip.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading npc" << std::endl;
	}
	m_alienSprite.setTexture(m_alienTexture);
	m_alienSprite.setPosition(500.0f, 500.0f);
	m_alienSprite.scale(5.0f, 5.0f);
	m_alienSprite.rotate(180);
	m_alienSprite.setOrigin(16.0f, 16.0f);
	m_alienSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

}

void Alien::kinematicWander()
{

}
