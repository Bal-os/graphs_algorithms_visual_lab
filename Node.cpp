#include"Node.h"
#include<iostream>

Node::Node(double x, double y){
	this->x = x - radius;
	this->y = y - radius;
	radius = STANDART_RADIUS;
	color = sf::Color(255, 0, 0);
	shape = new sf::CircleShape(radius);
	shape->setFillColor(color);
	shape->setPosition(x - radius, y - radius);
}

Node::Node(double x, double y, double& radius) : Node(x, y) {
	this->radius = radius;
}

Node::Node(double x, double y, double& radius, sf::Color& color) : Node(x, y, radius) {
	this->color = color;
}

void Node::moveTo(double x, double y) {
	this->x = x;
	this->y = y;
	shape->setPosition(x, y);
}

void Node::moveByVector(double x, double y)
{
	this->x += x;
	this->y += y;
	shape->move(x, y);
}

bool Node::intersect(const Node& other) const
{
	return sqrt(pow(this->x - other.getX(), 2) + pow(this->y - other.getY(), 2)) < 2 * radius;
}

bool Node::operator==(const Node& other) const
{
	return this->intersect(other);
}

bool Node::operator!=(const Node& other) const
{
	return !(*this == other);
}

void Node::setDist(long long& dist)
{
	this->distanse = dist;
}

void Node::setVisible(bool& vis)
{
	this->visible = vis;
}

void Node::setNum(int& nm)
{
	this->num = nm;
}

void Node::setX(double x)
{
	this->x = x;
	shape->setPosition(x,this->y);
}

void Node::setY(double y)
{
	this->y = y;
	shape->setPosition(this->x, y);
}

void Node::setRadius(double& r)
{
	this->radius = r;
	shape->setRadius(r);
}

double Node::getX() const
{
	return x;
}

double Node::getY() const
{
	return y;
}

int Node::getNum() const
{
	return num;
}

long long Node::getDist() const
{
	return distanse;
}

double Node::getRadius() const
{
	return radius;
}

sf::CircleShape* Node::getShape()
{
	return this->shape;
}

bool Node::isVisible() const
{
	return visible;
}

void Node::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->moveByVector(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->moveByVector(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->moveByVector(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->moveByVector(-1.f, 0.f);
}