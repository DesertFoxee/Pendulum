#ifndef PENDULUM_H
#define PENDULUM_H

#include "Object.h"
#include "KeyboardManager.h"
#include "Config.h"
#include "MouseManager.h"

class Pendulum : public Object
{
public:
	Pendulum(float x = float(SCREEN_WIDTH)/2 , float y = 200 , 
		float arm=200.f , float b_radius = 20.f);
	void init(float x = float(SCREEN_WIDTH) / 2, float y = 200, 
		float arm = 200.f , float b_radius =20.f);
	void render(sf::RenderWindow& window);
	void update();
	void process(sf::RenderWindow & window);
	void resetState();
	
private:
	static Vector2D gra;
	float arm;
	// using degree
	float angle;
	float aVec;
	float aAcc;
	Vector2D origin;
	sf::CircleShape ball;
	bool apply = true;
};

#endif // !PENDULUM_H

