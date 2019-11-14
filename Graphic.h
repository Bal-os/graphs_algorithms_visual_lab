#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include"State.h"

class Graphic 
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	State* state;

	void initWindow();
public:
	
	Graphic();
	virtual ~Graphic();

	sf::Clock dtClock;
	float dt;

	void updateDt();
	void updateEvents();
	void update();
	void render();
	void run();
};

