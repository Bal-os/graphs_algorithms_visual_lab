#pragma once
#include "GrapgAlgo.h"

class State
{
private:
	sf::RenderWindow* window;
	Graph graph;
	GrapgAlgo algoritms;
	Node* prev;
protected:
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
public:
	void render();
	void updateMousePosition();
	void updateMouseClick();
	void update();
	State();
	State(sf::RenderWindow*);
	~State();
};

