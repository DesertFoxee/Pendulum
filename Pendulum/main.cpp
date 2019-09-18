#include <iostream>

#include "Game.h"
#include "SoundManager.h"



int main()
{
	Game game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game tempalte");
	game.run();
	return EXIT_SUCCESS;
}
