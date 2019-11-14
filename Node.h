#pragma once
#include <cmath>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

/*struct Colour {
	double red = 0, green = 0, blue = 0;
	explicit Colour(double red, double green, double blue) : red(red), green(green), blue(blue) {

	}
};*/

class Node {
private:
	double x;
	double y;
	double radius;
	long long distanse;
	int num = 0;
	bool visible = true;
	sf::CircleShape *shape;
	bool intersect(const Node& other) const;
private:
	const double STANDART_RADIUS = 15;
public:

	sf::Color color; 
	Node(double, double);
	Node(double, double, double& radius);
	Node(double, double, double& radius, sf::Color&);
	void moveTo(double, double);
	void moveByVector(double, double);

	bool operator== (const Node&) const;
	bool operator!= (const Node&) const;

	void setDist(long long&);
	void setVisible(bool&);
	void setNum(int&);
	void setX(double);
	void setY(double);
	void setRadius(double&);
	void update();

	double getX() const;
	double getY() const;
	int getNum() const;
	long long getDist() const;
	double getRadius() const;
	sf::CircleShape* getShape();

	bool isVisible() const;

};