#pragma once

#include "GrapgAlgo.h"

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
private:

	result_vector(GrapgAlgo::*f) (Graph*, Node*);
	Graph* graph;

protected:
	GrapgAlgo cppForGenius;

	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	sf::RenderTarget* window;
public:
	Button(Graph *graph, result_vector (GrapgAlgo::*)(Graph*, Node*), double lx, double y, double wight, double hight,sf::Font* font, const sf::String& text,
		sf::Color idleColor = sf::Color::White, sf::Color hoverColor = sf::Color(200, 200, 200), sf::Color activeColor = sf::Color(100, 100, 100));
	Button();
	const bool isPressed() const;

	void render(sf::RenderTarget* target);
	bool updateClick(sf::Vector2f MousePos, Node*, result_vector& );
	void update(sf::Vector2f MousePos);
	virtual bool updateClick(sf::Vector2f MousePos, int size);
	virtual Graph getGrph();

	~Button();
};

class ButtonSt : public Button
{
	private:
		Graph graph;
		Graph(GrapgAlgo::* f) (int, int, int, double);
	public:
		ButtonSt(Graph(GrapgAlgo::* f) (int, int, int, double), double x, double y, double wight, double hight, sf::Font* font, const sf::String& text, sf::RenderTarget* target,
			sf::Color idleColor = sf::Color::White, sf::Color hoverColor = sf::Color(200, 200, 200), sf::Color activeColor = sf::Color(100, 100, 100));
		bool updateClick(sf::Vector2f MousePos, int size) override;
		Graph getGrph();
};

