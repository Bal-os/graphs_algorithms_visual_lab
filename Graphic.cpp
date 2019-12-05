#include "Graphic.h"

using namespace sf;
using namespace std;

void Graphic::initWindow(){
	string title = "None";
	VideoMode window_bounds(800, 600);


	this->window = new RenderWindow (VideoMode(800, 600), "SFML works!");
	this->window->setFramerateLimit(120);
}

Graphic::Graphic(){
	this -> initWindow();
	this->state = new State(this->window);
}

Graphic::~Graphic(){
	delete this->window;
}

void Graphic::updateEvents(){
	while (this->window->pollEvent(this->event)){
		if (this->event.type == Event::Closed)
			this->window->close();
		if (this->event.type == Event::MouseButtonPressed)
			this->state->mousePosition(this->event.mouseButton.button);
		if (this->event.type == Event::MouseButtonReleased)
			this->state->mouseClick(this->event.mouseButton.button);
		if (this->event.type == Event::KeyPressed)
			this->state->keyClick(this->event.key.code);
	}
}

void Graphic::updateDt(){
	this->dt = this->dtClock.restart().asSeconds();
}

void Graphic::update(){
	this->state->update();

	this->updateEvents();
}

void Graphic::render(){
	this->window->clear();

	this->state->render();

	this->window->display();
}

void Graphic::run(){
	while (this->window->isOpen()){
		this->updateDt();
		this->update();
		this->render();
	}
}
