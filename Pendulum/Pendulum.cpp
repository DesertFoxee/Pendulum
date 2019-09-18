#include "Pendulum.h"

Pendulum::Pendulum(float x, float y, float arm ,float b_radius )
{
	this->origin = Vector2D(x, y);
	this->arm = arm;
	this->ball.setRadius(b_radius);
	this->ball.setFillColor(sf::Color(200 ,100 ,100));
	this->angle = 45.f;
	this->aAcc = 0;
	this->aVec = 0;
}

void Pendulum::init(float x, float y, float arm , float b_radius)
{
	this->origin = Vector2D(x, y);
	this->arm = arm;
	this->ball.setRadius(b_radius);
	this->ball.setFillColor(sf::Color(200, 100, 100));
	this->angle = 70.f;
	this->aAcc = 0;
	this->aVec = 0;
	this->apply = true;
}

void Pendulum::render(sf::RenderWindow& window)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].position = sf::Vector2f(this->origin.x, this->origin.y);
	line[1].position = sf::Vector2f(obj.loc.x , obj.loc.y);

	window.draw(line);
	auto bound = ball.getGlobalBounds();

	std::cout << angle << std::endl;

	ball.setPosition((obj.loc - Vector2D(bound.width/2 , bound.height/2)).toVec2f());

	window.draw(ball);
	

}

void Pendulum::update()
{

	// why float not sf::Vector2f ?

	// not sinf , cosf using radius ;

	if (apply == true) {
		aAcc = sinf(Convert::DegreeToRadius(angle)) * DataConfig::OutOfForce::gravity * -1/(arm);
		this->aVec += aAcc * obj.mass;
		this->aVec *= 0.999f;
		this->angle += aVec;
		std::cout << angle << std::endl;
		obj.loc = this->origin + 
			Vector2D(arm * sinf(Convert::DegreeToRadius(angle)), 
				arm * cosf(Convert::DegreeToRadius(angle)));
		this->aAcc = 0;
	}

	
}

void Pendulum::process(sf::RenderWindow& window)
{

	// handle catch ball

	if (Mouse::getIntance().getStateMouse(MOUSE::MOUSE_B::LEFT)) {
		auto bound = ball.getGlobalBounds();

		auto mouse = Mouse::getIntance().getMouseWindow(window);
		sf::Vector2f mouse_(float(mouse.x), float(mouse.y));
		if (bound.contains(mouse_.x , mouse_.y)) {
			obj.loc = mouse_;
			this->apply = false;
		}
	}
	else if (!apply) {
		
		Vector2D t_arm = obj.loc - origin;
		float mt_arm = t_arm.mag();
		
		// thrust
		if (mt_arm > arm) {
			obj.loc -= t_arm.normalize();
		}
		// free fall 
		else if (mt_arm < arm) {
			obj.loc += Vector2D(0, 0.1f);
		}
		else {
			this->aAcc = 0;
			this->aVec = 0;
			// because : angle with x ; (horizotal)
			this->angle = 90 - Convert::RadiusToDegree((obj.loc - origin).angle());
		}
		
	}
		



	
}
