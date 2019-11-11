#include <SFML/Graphics.hpp>

const float r = 20;
const float h = 600;
const float w = 600;
const float hspeed = 0.2;
const float wspeed = 0.1;

void step(float &x, bool &b, float speed, float sz)
{
	x += float(b) * speed + float(1 - b) * (-1) * speed;
	if (x < 1) b = true;
	else if (x > sz - 2 * r - 1) b = false;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(h, w), "SFML works!");
	sf::CircleShape shape(r);
	shape.setFillColor(sf::Color::Red);
	float x, y;
	x = w / 2 - r;
	y = h / 2 - r;
	bool b1 = true, b2 = true;
	while (window.isOpen())
	{

		step(x, b1, wspeed, w);
		step(y, b2, hspeed, h);
		/*
		x += float(b1) * wspeed + float(1 - b1) * (-1) * wspeed;
		if (x < 1) b1 = true;
		else if (x > w - 2 * r - 1) b1 = false;
		y += float(b2) * hspeed + float(1 - b2) * (-1) * hspeed;
		if (y < 1) b2 = true;
		else if (y > h - 2 * r - 1) b2 = false;
		*/
		shape.setPosition(float(x), float(y));
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}