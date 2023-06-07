#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "SFML works!");
    sf::CircleShape ball(15.f);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(640.f - 15.f, 400.f);


    sf::RectangleShape paddleLeft(sf::Vector2f(25.f, 120.f));
    paddleLeft.setFillColor(sf::Color::White);
    paddleLeft.setPosition(10.f, 400.f - 60.f);

    sf::RectangleShape paddleRight(sf::Vector2f(25.f, 120.f));
    paddleRight.setFillColor(sf::Color::White);
    paddleRight.setPosition(1270.f - 25.f, 400.f - 60.f);

    sf::RectangleShape Line(sf::Vector2f(2.f, 680.f));
    Line.setFillColor(sf::Color::White);
    Line.setPosition(640.f - 2.f, 60.f);

    //border
    sf::RectangleShape BorderLeft(sf::Vector2f(2.f, 680.f));
    BorderLeft.setFillColor(sf::Color::White);
    BorderLeft.setPosition(10.f - 2.f, 60.f);

    sf::RectangleShape BorderRight(sf::Vector2f(2.f, 680.f));
    BorderRight.setFillColor(sf::Color::White);
    BorderRight.setPosition(1280.f - 10.f - 2.f, 60.f);
    
    sf::RectangleShape BorderTop(sf::Vector2f(1260.f, 2.f));
    BorderTop.setFillColor(sf::Color::White);
    BorderTop.setPosition(10.f - 2.f, 60.f);

    sf::RectangleShape BorderBottom(sf::Vector2f(1260.f, 2.f));
    BorderBottom.setFillColor(sf::Color::White);
    BorderBottom.setPosition(10.f - 2.f, 740.f);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(ball);
        window.draw(paddleLeft);
        window.draw(paddleRight);
        window.draw(Line);
        window.draw(BorderLeft);
        window.draw(BorderRight);
        window.draw(BorderTop);
        window.draw(BorderBottom);

        window.display();
    }

    return 0;
}