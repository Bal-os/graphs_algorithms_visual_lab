#include "Button.h"

Button::Button(Graph* graph, result_vector(GrapgAlgo::*f) (Graph*, Node*), double lx, double y, double wight, double hight, sf::Font* font, const sf::String& text,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor){

	this->buttonState = BTN_IDLE;
	this->graph = graph;
	this->f = f;
	ff = nullptr;
	shape.setPosition(sf::Vector2f(lx - wight, y));
	shape.setSize(sf::Vector2f(wight, hight));
	shape.setFillColor(idleColor);

	this->font = font;
	this->text.setFont(*font);
	this->text.setString(text);
	this->text.setCharacterSize(14);
	this->text.setFillColor(sf::Color::Yellow);
	this->text.setPosition(
		this->shape.getPosition().x  - this->text.getGlobalBounds().width / 2.f + 10,
		this->shape.getPosition().y  - this->text.getGlobalBounds().height / 2.f
	);

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;


}

Button::Button(Graph* graph, result_vector(GrapgAlgo::* f) (Graph*, Node*, Node*), double lx, double y, double wight, double hight, sf::Font* font, const sf::String& text,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {

	this->buttonState = BTN_IDLE;
	this->graph = graph;
	this->ff = f;
	f = nullptr;
	shape.setPosition(sf::Vector2f(lx - wight, y));
	shape.setSize(sf::Vector2f(wight, hight));
	shape.setFillColor(idleColor);

	this->font = font;
	this->text.setFont(*font);
	this->text.setString(text);
	this->text.setCharacterSize(14);
	this->text.setFillColor(sf::Color::Yellow);
	this->text.setPosition(
		this->shape.getPosition().x - this->text.getGlobalBounds().width / 2.f + 10,
		this->shape.getPosition().y - this->text.getGlobalBounds().height / 2.f
	);

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;


}

const bool Button::isPressed() const
{
	return buttonState == BTN_ACTIVE;
}

void Button::render(sf::RenderTarget* target){
	target->draw(this->shape);
	target->draw(this->text);
}

void Button::update(sf::Vector2f MousePos){
	this->buttonState = BTN_IDLE;

	if (this->shape.getGlobalBounds().contains(MousePos)) {
		buttonState = BTN_HOVER;
		shape.setFillColor(hoverColor);
	}
	if (buttonState == BTN_IDLE)
		shape.setFillColor(idleColor);
}

bool Button::updateClick(sf::Vector2f MousePos, Node* thisNode, Node* prevNode, result_vector& cur) {
	if (!(this->graph->edges.empty())) {
		if (this->shape.getGlobalBounds().contains(MousePos)) {
			this->buttonState = BTN_ACTIVE;
			shape.setFillColor(activeColor);
			if (ff == nullptr)
				cur = (cppForGenius.*f)(this->graph, thisNode);
			else if (f == nullptr)
			{
				if(prevNode != nullptr)
					cur = (cppForGenius.*ff)(this->graph, thisNode, prevNode);
			}	
			else __ExceptionPtrRethrow;
		}
		else return false;
	}
	else return false;
	return true;
}

bool Button::updateClick(sf::Vector2f MousePos, int size) {
	return true;
}

Button::Button() {
}

Button::~Button(){
}


ButtonSt::ButtonSt(Graph(GrapgAlgo::* f) (int, int, int, double), double x, double y, double wight, double hight, sf::Font* font, const sf::String& text, sf::RenderTarget* target, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;
	this->f = f;

	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(wight, hight));
	shape.setFillColor(idleColor);

	this->font = font;
	this->text.setFont(*font);
	this->text.setString(text);
	this->text.setCharacterSize(14);
	this->text.setFillColor(sf::Color::Yellow);
	this->text.setPosition(
		this->shape.getPosition().x - this->text.getGlobalBounds().width / 2.f + 10,
		this->shape.getPosition().y - this->text.getGlobalBounds().height / 2.f
	);

	this->activeColor = activeColor;
	this->hoverColor = hoverColor;
	this->idleColor = idleColor;

	window = target;
}

bool ButtonSt::updateClick(sf::Vector2f MousePos, int size) {
		if (this->shape.getGlobalBounds().contains(MousePos)) {
			this->buttonState = BTN_ACTIVE;
			shape.setFillColor(activeColor);
			graph = (cppForGenius.*f)(size, window->getSize().x, window->getSize().y, 0.15);
		}
		else return false;
	return true;
}

Graph Button::getGrph()
{
	return *graph;
}

Graph ButtonSt::getGrph()
{
	return graph;
}
