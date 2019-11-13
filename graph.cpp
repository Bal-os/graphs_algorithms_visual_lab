#include "graph.h"

using namespace std;

void Graph::renumerate(){
	for (int i = 0; i < vertexes.size(); ++i)
		vertexes[i]->setNum(i);
}

void Graph::resize(int size){
	edges.assign(size, vector<int>());
	costs.assign(size, vector<long long>());
	vertexes.assign(size, nullptr);
	for (size_t i = 0; i < size; ++i)vertexes[i] = new Vertex(0, 0);
	renumerate();
}

Graph::Graph(int size) {
	resize(size);
}

Graph::Graph(int size, bool oriented) : Graph(size) {
	this->oriented = oriented;
}

Vertex::Vertex(double, double) : x(x), y(y), radius(STANDART_RADIUS), color(0, 0, 0) {
}

Vertex::Vertex(double x, double y, double &radius) : Vertex(x , y){
	this->radius = radius;
}

Vertex::Vertex(double x, double y, double& radius, Color &color) : Vertex(x, y, radius){
	this->color = color;
}

void Vertex::moveTo(double& x, double& y){
	this->x = x;
	this->y = y;
}

void Vertex::moveByVector(double &x, double &y)
{
	this->x += x;
	this->y += y;
}

bool Vertex::operator==(const Vertex& other) const
{
	return this->num == other.num;
}

bool Vertex::operator!=(const Vertex& other) const
{
	return !(*this == other);
}

void Vertex::setDist(long long& dist)
{
	this->distanse = dist;
}

void Vertex::setVisible(bool& vis)
{
	this->visible = vis;
}

void Vertex::setNum(int& nm)
{
	this->num = nm;
}

void Vertex::setX(double& x)
{
	this->x = x;
}

void Vertex::setY(double& y)
{
	this->y = y;
}

void Vertex::setRadius(double& r)
{
	this->radius = r;
}

double Vertex::getX() const
{
	return x;
}

double Vertex::getY() const
{
	return y;
}

int Vertex::getNum() const
{
	return num;
}

long long Vertex::getDist() const
{
	return distanse;
}

double Vertex::getRadius() const
{
	return radius;
}

bool Vertex::isVisible() const
{
	return visible;
}

bool Vertex::intersect(double& xa, double& ya) const
{
	return sqrt(pow(x - xa, 2) + pow(y - ya, 2)) < radius;;
}
