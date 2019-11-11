#include "graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}

Vertex::Vertex(double& x, double& y, double &radius) : x(x), y(y), radius(radius), color(0, 0, 0){
}

Vertex::Vertex(double& x, double& y, double& radius, Color color) : Vertex(x, y, radius){
	this->color = color;
}

void Vertex::moveTo(double& x, double& y){
	this->x = x;
	this->y = y;
}

void Vertex::moveByVector(double &x, double &y)
{
}

bool Vertex::operator==(const Vertex& other) const
{
	return false;
}

bool Vertex::operator!=(const Vertex& other) const
{
	return false;
}

void Vertex::setDist(long long& dist)
{
}

void Vertex::setVisible(bool&)
{
}

void Vertex::setNum(int& nm)
{
}
