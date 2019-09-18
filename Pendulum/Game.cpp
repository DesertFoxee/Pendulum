#include "Game.h"



Game::Game(unsigned int width, unsigned int height, std::string title) {
	this->width = width;
	this->title = title;
	this->height = height;
}


Game::~Game() {
}

void Game::init() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	this->window.create(sf::VideoMode(width, height), title ,sf::Style::Default , settings);
	Keyboard::getIntance();
	Mouse::getIntance();

	this->pen.init();
}

void Game::handleKeyboard(const sf::Keyboard::Key key, bool state) {
	switch(key) {
		case sf::Keyboard::W:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::UP, state);
			break;
		case sf::Keyboard::S:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::DOWN, state);
			break;
		case sf::Keyboard::A:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::LEFT, state);
			break;
		case sf::Keyboard::D:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::RIGHT, state);
			break;
		case sf::Keyboard::LControl:
		case sf::Keyboard::RControl:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::CONTROL, state);
			break;
		case sf::Keyboard::LShift:
		case sf::Keyboard::RShift:
			Keyboard::getIntance().setStateKeyboard(KEYBOARD::KEY_B::SHIFT, state);
			break;
		default:
			break;
	}
}

void Game::handleMouseClick(const sf::Mouse::Button btn, bool state) {
	switch(btn) {
		case sf::Mouse::Left:
			Mouse::getIntance().setStateMouse(MOUSE::MOUSE_B::LEFT, state);
			break;
		case sf::Mouse::Right:
			Mouse::getIntance().setStateMouse(MOUSE::MOUSE_B::RIGHT, state);
			break;
		case sf::Mouse::Middle:
			Mouse::getIntance().setStateMouse(MOUSE::MOUSE_B::MIDDLE, state);
			break;
		default:
			break;
	}
}

void Game::handleMouseScrolled(const sf::Mouse::Wheel wheel , int deltascr) {
	switch(wheel) {
		case sf::Mouse::VerticalWheel:
			// do something
			break;
		case sf::Mouse::HorizontalWheel:
			// do something
			break;
		default:
			break;
	}
	Mouse::getIntance().Zoom(deltascr);
}

void Game::update() {
	pen.update();
}

void Game::process() {
	sf::Event event;
	while(window.pollEvent(event)) {
		switch(event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				this->handleKeyboard(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				this->handleKeyboard(event.key.code, false);
				break;
			case sf::Event::MouseButtonPressed:
				this->handleMouseClick(event.mouseButton.button, true);
				break;
			case sf::Event::MouseButtonReleased:
				this->handleMouseClick(event.mouseButton.button, false);
				break;
			case sf::Event::MouseWheelScrolled:
				this->handleMouseScrolled(event.mouseWheelScroll.wheel ,event.mouseWheel.delta);
				break;
			default:
				break;
		}
	}
	pen.process(window);
}

void Game::render() {
	this->window.clear();
	pen.render(window);
	this->window.display();
}

void Game::run() {
	this->init();

	while(this->window.isOpen()) {
		
		this->process();
		this->update();
		this->render();
	}	
}
