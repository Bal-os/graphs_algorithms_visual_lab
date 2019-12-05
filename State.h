#pragma once
#include "Button.h"

sf::RectangleShape Line(double x1, double y1, double x2, double y2, sf::Color color, double thickness);

class State
{
private:
	sf::RenderWindow* window;
	sf::Font* font;
	Graph graph;
	GrapgAlgo algoritms;
	Node* prev;
	Node* thisNode;
	result_vector cur;
	int pos = -1;
	bool isThisMove = false;
	bool isPrevMove = false;
	std::vector<Button*> buttons;
protected:
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	void startAlgo();
	void updateMouseClick();
	void updateMousePosition();
public:
	void render();
	void mouseClick(sf::Mouse::Button);
	void keyClick(sf::Keyboard::Key);
	void mousePosition(sf::Mouse::Button);
	void update();
	State();
	State(sf::RenderWindow*);
	~State();
};

