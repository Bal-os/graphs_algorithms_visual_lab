#include"Node.h"
#include<iostream>

Node::Node(double x, double y) : x(x),y(y){
	this->radius = STANDART_RADIUS;
	this->color = sf::Color(100, 100, 100);
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
}

void Node::moveByVector(double x, double y)
{
	this->x += x;
	this->y += y;
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


void Node::setVisible(bool vis)
{
	this->visible = vis;
}

void Node::setNum(int nm)
{
	this->num = nm;
}

void Node::setX(double x)
{
	this->x = x;
}

void Node::setY(double y)
{
	this->y = y;
}

void Node::setRadius(double r)
{
	this->radius = r;
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

double Node::getRadius() const
{
	return radius;
}

sf::Color Node::getColor()
{
	return color;
}

bool Node::isVisible() const
{
	return visible;
}