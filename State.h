#pragma once
#include "GrapgAlgo.h"

class State
{
private:
	sf::RenderWindow* window;
	Graph graph;
	GrapgAlgo algoritms;
	Node* prev;
	Node* thisNode;
	std::vector<std::pair<std::pair<Node*, Node*>, long long> > cur;
	int pos = -1;
	bool isThisMove = false;
	bool isPrevMove = false;
protected:
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
public:
	void render();
	void mouseClick(sf::Mouse::Button);
	void keyClick(sf::Keyboard::Key);
	void mousePosition(sf::Mouse::Button);
	void updateMouseClick();
	void updateMousePosition();
	void update();
	State();
	State(sf::RenderWindow*);
	~State();
};

