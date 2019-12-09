#include "State.h"

sf::RectangleShape Line(double x1, double y1, double x2, double y2, sf::Color color = sf::Color(100, 100, 100), double thickness = 1.3){
	sf::RectangleShape line;
	double len, angle;

	line.setPosition(x1, y1);
	len = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	angle = atan((y2 - y1) / (x2 - x1)) * 180 / (acos(-1));

	if (x2 - x1 < 0) angle += 180;

	line.setSize(sf::Vector2f(len, thickness));
	line.setFillColor(color);
	line.setRotation(angle);
	return line;
}

void State::startAlgo()
{
	pos = 0;
}

void State::updateMouseClick(){
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*(this->window));
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
#include<iostream>
void State::mouseClick(sf::Mouse::Button click){
		if (click == sf::Mouse::Button::Left) {
			bool isButtonClick = false;
			isButtonClick = buttons[0]->updateClick(mousePosView, 10);
			if (isButtonClick)
			{
				graph = buttons[0]->getGrph();
				thisNode = nullptr;
				prev = nullptr;
				pos = -1;
			}
			else
			if (!graph.edges.empty() && thisNode != nullptr)
			{
				for (int i = 1; i < buttons.size(); i++)
				{
						isButtonClick = buttons[i]->updateClick(mousePosView, thisNode, cur);
						if (isButtonClick)
						{
							startAlgo();
							// /*
							for (int i = 0; i < graph.costs.size(); i++)
								for (int j = 0; j < graph.costs[i].size(); j++)
								{
									std::cout << i << " " << j << " " << graph.costs[i][j] << std::endl;
								}
							//*/
							break;
						}
				}
			}
			if (!isButtonClick)
			{
				isThisMove = false;
				Node* X = new Node(mousePosView.x, mousePosView.y);
				if (this->graph.Nodees.empty())
					this->graph.addNode(thisNode = X);
				else
				{
					bool isNew = true;
					for (auto i : this->graph.Nodees)
						if (*i == *X) {
							isNew = false;
							thisNode = i;
							break;
						}
					if (isNew)
						this->graph.addNode(thisNode = X);
				}
				if (prev != nullptr && *X == *prev)
					prev = nullptr;
			}
		}
		if (click == sf::Mouse::Button::Right) 
			if(thisNode != nullptr || prev != nullptr){
			isPrevMove = false;
			Node* X = new Node(mousePosView.x, mousePosView.y);
			if (prev != nullptr && *X == *prev)
				prev = nullptr;
			else
			{
				if (thisNode == nullptr || *X != *thisNode) {
					for (auto i : this->graph.Nodees)
						if (*i == *X) {
							if (thisNode != nullptr)
							{
								int x1 = thisNode->getX();
								int x2 = i->getX();
								int y1 = thisNode->getY();
								int y2 = i->getY();
								graph.addEdge(thisNode, i, int(sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)))));
								prev = i;
							}

							break;
						}
				}
				else if (*X == *thisNode)
				{
					if (thisNode != nullptr && prev != nullptr)
						graph.addEdge(prev, thisNode);
				}
			}
		}
}

void State::keyClick(sf::Keyboard::Key click){
	if (click == sf::Keyboard::Key::Enter)
		if (!graph.edges.empty()) {
			cur = algoritms.prima(&graph, thisNode);
		}
	
	if (click == sf::Keyboard::Key::Right){
		if (pos < cur.size() - 1)
		{
			pos++;
			std::cout << cur[pos].second << std::endl;
		}
	}
	if (click == sf::Keyboard::Key::Left){
		if (pos > 0)
			pos--;
	}
	if (click == sf::Keyboard::Key::Delete) {
		if (thisNode != nullptr)
		{
			graph.deleteNode(thisNode);
			thisNode = prev;
		}
	}
}

void State::mousePosition(sf::Mouse::Button click)
{
	if (click == sf::Mouse::Button::Left)
	{
		Node* X = new Node(mousePosView.x, mousePosView.y);
		if (thisNode != nullptr && *X == *thisNode)
		{
			isThisMove = true;
		}
	}
	if (click == sf::Mouse::Button::Right)
	{
		Node* X = new Node(mousePosView.x, mousePosView.y);
		if (prev != nullptr && *X == *prev)
		{
			isPrevMove = true;
		}
	}
}

void State::updateMousePosition()
{
	if (isThisMove && thisNode != nullptr)
	{
		thisNode->moveTo(mousePosView.x, mousePosView.y);
	}
	if (isPrevMove && prev != nullptr)
	{
		prev->moveTo(mousePosView.x, mousePosView.y);
	}
}

void State::update(){
	this->updateMousePosition();
	for (auto i : buttons)
	{
		i->update(mousePosView);
	}
	this->updateMouseClick();
}

void State::render() {
	for (auto i = 0; i < this->graph.edges.size(); i++){
		Node* X = graph.Nodees[i];
		for (auto j : this->graph.edges[i]){
			Node* Y = graph.Nodees[j];

			this->window->draw(Line(X->getX(), X->getY(), Y->getX(), Y->getY()));
		}
	}
	if (pos != -1){
		for (auto i = 0; i <= pos; i++){
			Node* X = cur[i].first.first;
			Node* Y = cur[i].first.second;
			this->window->draw(Line(X->getX(), X->getY(), Y->getX(), Y->getY(), sf::Color(200, 0, 0), 3));
		}
	}
	if (thisNode != nullptr)
	{
		double radius = 1.5 * thisNode->getRadius();
		sf::CircleShape shape(radius);
		shape.setFillColor(sf::Color(255, 0, 0));
		shape.setPosition(thisNode->getX() - radius, thisNode->getY() - radius);
		this->window->draw(shape);
	}
	if (prev != nullptr)
	{
		double radius = 1.5 * prev->getRadius();
		sf::CircleShape shape(radius);
		shape.setFillColor(sf::Color(0, 255, 0));
		shape.setPosition(prev->getX() - radius, prev->getY() - radius);
		this->window->draw(shape);
	}
	for (auto i : this->graph.Nodees) {
		sf::CircleShape shape(i->getRadius());
		shape.setFillColor(sf::Color(100, 100, 100));
		shape.setPosition(i->getX() - i->getRadius(), i->getY() - i->getRadius());
		this->window->draw(shape);
	}
	for (auto i: buttons)
	{
		i->render(window);
	}
}

State::State(){

}

#include <iostream>

State::State(sf::RenderWindow* window){
	srand(time(0));
	this->window = window;
	font = new sf::Font();
	font->loadFromFile("arial.ttf");
	buttons.push_back(new ButtonSt(&(GrapgAlgo::generateComponent), 0, 0, 60., 20., font, L"new Graph", window));
	buttons.push_back(new Button(&graph, &GrapgAlgo::dijkstra, window->getSize().x * 1., 0., 60., 20.,font , L"dijkstra"));
	buttons.push_back(new Button(&graph, &GrapgAlgo::prima, window->getSize().x * 1., 21., 60., 20., font, L"prima"));

}


State::~State(){
}
