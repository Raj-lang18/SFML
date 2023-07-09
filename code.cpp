// #include<iostream>
// #include"singlePlayer.h"
// #include<SFML/Graphics.hpp>
// using namespace std;
// using namespace sf;

// void singlePlayer :: singleplay()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Render Window");

//     sf::Font font;
//     if (!font.loadFromFile("path/to/font.ttf")) {
//         // Handle font loading error
        
//     }


//     //GAME
//     //ball
//     CircleShape ball(15.f);
//     ball.setFillColor(Color::White);
//     ball.setPosition(640.f - 15.f, 400.f);

//     //paddle
//     RectangleShape paddleLeft(Vector2f(25.f, 120.f));
//     paddleLeft.setFillColor(Color::White);
//     paddleLeft.setPosition(10.f, 400.f - 60.f);

//     RectangleShape paddleRight(Vector2f(25.f, 120.f));
//     paddleRight.setFillColor(Color::White);
//     paddleRight.setPosition(1270.f - 25.f, 400.f - 60.f);

//     RectangleShape Line(Vector2f(2.f, 680.f));
//     Line.setFillColor(Color::White);
//     Line.setPosition(640.f - 2.f, 60.f);

//     //border
//     RectangleShape BorderLeft(Vector2f(2.f, 680.f));
//     BorderLeft.setFillColor(Color::White);
//     BorderLeft.setPosition(10.f - 2.f, 60.f);

//     RectangleShape BorderRight(Vector2f(2.f, 680.f));
//     BorderRight.setFillColor(Color::White);
//     BorderRight.setPosition(1280.f - 10.f - 2.f, 60.f);
    
//     RectangleShape BorderTop(Vector2f(1260.f, 2.f));
//     BorderTop.setFillColor(Color::White);
//     BorderTop.setPosition(10.f - 2.f, 60.f);

//     RectangleShape BorderBottom(Vector2f(1260.f, 2.f));
//     BorderBottom.setFillColor(Color::White);
//     BorderBottom.setPosition(10.f - 2.f, 740.f);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
        
//         window.draw(ball);
//         window.draw(paddleLeft);
//         window.draw(paddleRight);
//         window.draw(Line);
//         window.draw(BorderLeft);
//         window.draw(BorderRight);
//         window.draw(BorderTop);
//         window.draw(BorderBottom);

//         window.display();
//     }

    
// }
