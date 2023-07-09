#include<iostream>
#include"howToPlay.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;


void howToPlay:: information ()
{
    RenderWindow window(VideoMode(1280, 800), "HOW TO PLAY!");

    Font font;
    if (!font.loadFromFile("sans.ttf")) {
        // handle error if the font file cannot be loaded
        cout<<"error";
    }
    Text text("Pong is a classic arcade game that simulates table tennis. Here's how to play:\n\n"
                   "1. Game Setup:\n"
                   "   - Pong is a two-player game, so you'll need another player or you can play against an AI opponent.\n"
                   "   - The game screen is divided into two halves, with a horizontal line in the middle representing the net.\n"
                   "   - Each player controls a paddle, which can move vertically within their half of the screen.\n"
                   "   - The objective is to score points by hitting the ball past the opponent's paddle.\n\n"
                   "2. Starting the Game:\n"
                   "   - The game begins with the ball placed at the center of the screen.\n"
                   "   - One player is designated to serve the ball first. They will hit the ball to start the game.\n\n"
                   "3. Playing the Game:\n"
                   "   - Each player moves their paddle up and down to hit the ball.\n"
                   "   - The ball will initially move towards the opposite side of the player who served it.\n"
                   "   - As the ball moves, players must position their paddles to intercept it and hit it back.\n"
                   "   - The ball can bounce off the paddles, walls, and the net.\n"
                   "   - If a player fails to hit the ball, the opponent scores a point.\n\n"
                   "4. Scoring:\n"
                   "   - If a player successfully hits the ball past the opponent's paddle, they score a point.\n"
                   "   - The ball will be reset to the center, and the player who was scored against will serve next.\n"
                   "   - The game continues until one player reaches a predetermined number of points or a specific time limit is reached.\n\n"
                   "5. Strategies and Tips:\n"
                   "   - Try to position your paddle to hit the ball at an angle that makes it difficult for your opponent to return.\n"
                   "   - Move your paddle swiftly but with control to react to the ball's movement.\n"
                   "   - Be mindful of the ball's speed and trajectory to anticipate its path.\n"
                   "   - Use the walls and angles strategically to make it challenging for your opponent to return the ball.\n"
                   "   - Practice your timing and coordination to improve your chances of hitting the ball successfully.\n\n"
                   "Remember, Pong is a simple game to learn but can be quite challenging as you play against more skilled opponents. Have fun playing and improving your skills!",font,18);
    
    text.setFillColor(Color::White);
    // text.setPosition(640, 300);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(11,47,94));

        window.draw(text);

        window.display();
    }

    
}