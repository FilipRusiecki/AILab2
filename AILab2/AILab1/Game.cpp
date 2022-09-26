
#include "Game.h"
#include <iostream>




Game::Game() :
	m_window{ sf::VideoMode{ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().bitsPerPixel}, "AILab1" },
	m_exitGame{ false } //when true game will exit
{
	playerOffScreenOffsetX = myPlayer.m_playerSprite.getGlobalBounds().width;
	playerOffScreenOffsetY = myPlayer.m_playerSprite.getGlobalBounds().height;
	if (!m_font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading font" << std::endl;

	}
	for (size_t i = 0; i < npcCount; i++)
	{
		nameTag[i].setFont(m_font);
		nameTag[i].setScale(0.5f, 0.5f);
	}

	nameTag[0].setString("Wander");
	nameTag[1].setString("NPC");
	nameTag[2].setString("Seek");


	//line[1].position = sf::Vector2f(20, 0);
	//line[1].color = sf::Color::Red;
}


Game::~Game()
{

}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps

	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps

		}
		render(); // as many as possible
	}
}

void Game::checkForOffScreen()
{
	//player moving left off screen
	if (myPlayer.m_playerSprite.getPosition().x > sf::VideoMode::getDesktopMode().width)
	{
		myPlayer.m_playerSprite.setPosition(0 - playerOffScreenOffsetX, myPlayer.m_playerSprite.getPosition().y);
	}

	//player moving right of screen 
	if (myPlayer.m_playerSprite.getPosition().x < 0 - playerOffScreenOffsetX)
	{
		myPlayer.m_playerSprite.setPosition(sf::VideoMode::getDesktopMode().width, myPlayer.m_playerSprite.getPosition().y);
	}

	//player moving top of screen 
	if (myPlayer.m_playerSprite.getPosition().y < 0 - playerOffScreenOffsetY)
	{
		myPlayer.m_playerSprite.setPosition(myPlayer.m_playerSprite.getPosition().x, sf::VideoMode::getDesktopMode().height);
	}

	//playe rmoving bottom of screen 
	if (myPlayer.m_playerSprite.getPosition().y > sf::VideoMode::getDesktopMode().height)
	{
		myPlayer.m_playerSprite.setPosition(myPlayer.m_playerSprite.getPosition().x, 0 - playerOffScreenOffsetY);
	}





	//npc moving top of screen 
	if (myNpc.m_npcSprite.getPosition().y > sf::VideoMode::getDesktopMode().height)
	{
		myNpc.m_npcSprite.setPosition(myNpc.m_npcSprite.getPosition().x, 0 - playerOffScreenOffsetY);
	}




	//aline moving off screen
	//aline moving left off screen
	if (myAlien.m_alienSprite.getPosition().x > sf::VideoMode::getDesktopMode().width)
	{
		myAlien.m_alienSprite.setPosition(0 - playerOffScreenOffsetX, myAlien.m_alienSprite.getPosition().y);
	}

	//aline moving right of screen 
	if (myAlien.m_alienSprite.getPosition().x < 0 - playerOffScreenOffsetX)
	{
		myAlien.m_alienSprite.setPosition(sf::VideoMode::getDesktopMode().width, myAlien.m_alienSprite.getPosition().y);
	}

	//aline moving top of screen 
	if (myAlien.m_alienSprite.getPosition().y < 0 - playerOffScreenOffsetY)
	{
		myAlien.m_alienSprite.setPosition(myAlien.m_alienSprite.getPosition().x, sf::VideoMode::getDesktopMode().height);
	}

	//aline rmoving bottom of screen 
	if (myAlien.m_alienSprite.getPosition().y > sf::VideoMode::getDesktopMode().height)
	{
		myAlien.m_alienSprite.setPosition(myAlien.m_alienSprite.getPosition().x, 0 - playerOffScreenOffsetY);
	}


}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}



void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

}


void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	checkForOffScreen();
	myPlayer.update(t_deltaTime);
	myNpc.update();
	myAlien.update(t_deltaTime);
	myArrive.update(t_deltaTime,myPlayer);
	mySeek.update(t_deltaTime, myPlayer);


	nameTag[0].setPosition(myAlien.m_alienSprite.getPosition());
	nameTag[1].setPosition(myNpc.m_npcSprite.getPosition());
	nameTag[2].setPosition(mySeek.m_seekSprite.getPosition());


}


void Game::render()
{
	m_window.clear(sf::Color::Black);
	myNpc.reder(m_window);
	myPlayer.reder(m_window);
	myAlien.render(m_window);
	//myArrive.render(m_window);
	mySeek.render(m_window);

	for (size_t i = 0; i < npcCount; i++)
	{
		m_window.draw(nameTag[i]);

	}
	m_window.display();
}



