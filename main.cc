#include <SFML/Graphics.hpp>
#include <iostream>

struct Point {float x; float y;};

Point attractors[3] {{40,40}, {500, 850}, {900, 95}};

void new_point(sf::RenderWindow &window, Point &point) {
    int attractor_n = rand() % 3;
    point.x = (point.x + attractors[attractor_n].x) / 2.;point.y = (point.y + attractors[attractor_n].y) / 2.;
    sf::RectangleShape shape(sf::Vector2f(1., 1.));
    shape.setFillColor(sf::Color::White);
    shape.setPosition(point.x, point.y);
    window.draw(shape);
}

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(1000, 900), "Sierpinski triangle", sf::Style::Close | sf::Style::Titlebar);
    window.setVerticalSyncEnabled(true);
    
    Point point {attractors[0]};
    float speed = 0.01;
    sf::Time elapsed = sf::seconds(0);
    sf::Clock clock;

    sf::RectangleShape shape(sf::Vector2f(3., 3.));
    shape.setFillColor(sf::Color::Yellow);
    for (int i = 0; i < 3; i++) {
        shape.setPosition(attractors[i].x, attractors[i].y);
        window.draw(shape);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        new_point(window, point);
        window.display();
    }

    return 0;
}