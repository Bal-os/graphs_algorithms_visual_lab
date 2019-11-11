#pragma once

#include <cmath>

struct Color {
	double red = 0, green = 0, blue = 0;
	explicit Color(double red, double green, double blue) : red(red), green(green), blue(blue) {

	}
};



class Vertex {
private:
	double x;
	double y;
	double radius;
	long long distanse;
	int num = 0;
	bool visible = true;
private:
	const long long MAX_COST = 1000000000;
	const long long MIN_COST = -MAX_COST;
	const double STANDART_RADIUS = 15;
public:
	Color color;
	Vertex(double&, double&, double&);
	Vertex(double&, double&, double&, Color&);
	void moveTo(double&, double&);
	void moveByVector(double&, double&);
	
	bool operator== (const Vertex&) const;
	bool operator!= (const Vertex&) const;

	void setDist(long long&);
	void setVisible(bool&);
	void setNum(int&);
	void setX(double&);
	void setY(double&);
	void setRadius(double &);

	double getX() const;
	double getY() const;
	int getNum() const;
	long long getDist() const;
	double getRadius() const;

	bool isVisible() const;
	bool intersect(double &x, double &y) const;
	
};

class Graph
{
public:
	Graph();
	Graph(int size);
    Graph(int size, bool oriented);
	~Graph();
};

