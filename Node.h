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
	int num = 0;
	bool visible = true;
	sf::Color color; 
	bool intersect(const Node& other) const;
private:
	const double STANDART_RADIUS = 5;
public:
	Node(double, double);
	Node(double, double, double& radius);
	Node(double, double, double& radius, sf::Color&);
	void moveTo(double, double);
	void moveByVector(double, double);

	bool operator== (const Node&) const;
	bool operator!= (const Node&) const;

	void setVisible(bool);
	void setNum(int);
	void setX(double);
	void setY(double);
	void setRadius(double);

	double getX() const;
	double getY() const;
	int getNum() const;
	double getRadius() const;
	sf::Color getColor();

	bool isVisible() const;

};