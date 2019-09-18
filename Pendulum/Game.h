#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "KeyboardManager.h"
#include "MouseManager.h"
#include "TextureManager.h"
//#include "SoundManager.h"
//#include "FontManager.h"
#include "Pendulum.h"


class Game {
	public:
		Game(unsigned int width, unsigned int height, std::string title);
		~Game();
		void run();

	private:
		void init();
		void handleKeyboard(const sf::Keyboard::Key key, bool state);
		void handleMouseClick(const sf::Mouse::Button btn, bool state);
		void handleMouseScrolled(const sf::Mouse::Wheel wheel , int deltascr);
		void update();
		void process();
		void render();
	private:
		
		sf::RenderWindow window ;
		std::string title;
		unsigned int width;
		unsigned int height;
		Pendulum pen;

		// object ;
};


#endif // !GAME_H



