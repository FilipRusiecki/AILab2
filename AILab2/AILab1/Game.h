
#ifndef GAME_HPP
#define GAME_HPP
#include "Player.h"
#include "npc.h"
#include "Alien.h"
#include "Arrive.h"
#include "Seek.h"
#include "Flee.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void run();
	Player myPlayer;
	npc myNpc;
	Alien myAlien;
	Arrive myArrive;
	Seek mySeek;
	Flee myFlee;
	void checkForOffScreen();
private:
	int npcCount= 4; 
	sf::Text nameTag[4];
	sf::Text info;
	sf::Font m_font;
	float playerOffScreenOffsetX;
	float playerOffScreenOffsetY;
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game
};

#endif // !GAME_HPP

