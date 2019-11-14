#include "State.h"

void State::updateMouseClick()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*(this->window));
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::updateMousePosition()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		Node* X = new Node(mousePosView.x, mousePosView.y);
		if (this->graph.Nodees.empty())
			this->graph.addNode(X);
		else
			if (*this->graph.Nodees.back() != *X)
				this->graph.addNode(X);
		prev = nullptr;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		Node* X = new Node(mousePosView.x, mousePosView.y);
		if(prev == nullptr || *X != *prev)
		for (auto i : this->graph.Nodees)
			if (*i == *X)
			{
				if (prev != nullptr)
					graph.addEdge(prev, i);
				prev = i;
				break;
			}
	}
}

void State::update()
{
	this->updateMouseClick();
	this->updateMousePosition();
}

void State::render() 
{
	for(auto i: this->graph.Nodees)
		this->window->draw(*(i->getShape()));
	for (auto i = 0; i < this->graph.edges.size(); i++)
	{
		Node* X = graph.Nodees[i];
		float x = X->getX(),
			y = X->getY();
		for (auto j : this->graph.edges[i])
		{
			Node* Y = graph.Nodees[j];
			sf::ConvexShape convex;
			convex.setPointCount(4);
			convex.setFillColor(sf::Color(255, 0, 0));
			convex.setPoint(0, sf::Vector2f(x - 1, y - 1));
			convex.setPoint(1, sf::Vector2f(Y->getX() - 1, Y->getY() - 1));
			convex.setPoint(2, sf::Vector2f(Y->getX() + 1, Y->getY() + 1));
			convex.setPoint(3, sf::Vector2f(x + 1, y + 1));
			
			
			this->window->draw(convex);
		}
	}
}

State::State()
{

}

State::State(sf::RenderWindow* window)
{
	this->window = window;
}


State::~State()
{
}
