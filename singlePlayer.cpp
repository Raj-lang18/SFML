#include "SinglePlayer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<fstream>
using namespace sf;

SinglePlayer::SinglePlayer() : s_backgroundColor(Color::Black),
                               s_paddleColor(Color::White),
                               s_ballColor(Color::White),
                               s_playerPaddle(Vector2f(25, 70)),
                               s_cpuPaddle(Vector2f(25, 120)),
                               
                               s_paddleVelocity(7),
                               s_ball(15),
                               s_ballVelocity(450, 450),
                               s_life(2),
                               s_score(0),
                               s_highScore(0),
                               s_selectedLevel(1)


{
    s_window.create(VideoMode(1280, 800), "Single Player Pong(Easy)"); // Initialize s_window
    // setting up player paddle
    s_playerPaddle.setFillColor(s_paddleColor);
    s_playerPaddle.setPosition(10.f, s_window.getSize().y / 2 - s_playerPaddle.getSize().y / 2);

    // setting up opponents paddle
    s_cpuPaddle.setFillColor(s_paddleColor);
    s_cpuPaddle.setPosition(s_window.getSize().x - 35, s_window.getSize().y / 2 - s_cpuPaddle.getSize().y / 2);

    // setting up ball
    s_ball.setFillColor(s_ballColor);
    s_ball.setPosition(s_window.getSize().x / 2 - s_ball.getRadius(), s_window.getSize().y / 2 - s_ball.getRadius());

    // font
    s_font.loadFromFile("arial.ttf");

    // score
    s_scoreText.setFont(s_font);
    s_scoreText.setCharacterSize(36);
    s_scoreText.setFillColor(Color::White);
    s_scoreText.setPosition(10, 10);

    // high score:
    s_highScoreText.setFont(s_font);
    s_highScoreText.setCharacterSize(36);
    s_highScoreText.setFillColor(Color::White);
    s_highScoreText.setPosition(s_window.getSize().x - 300, 0);

    // life
    s_lifeText.setFont(s_font);
    s_lifeText.setCharacterSize(36);
    s_lifeText.setFillColor(Color::White);
    s_lifeText.setPosition(s_window.getSize().x /2, s_window.getSize().y - 50  );
    
    //gameover
    gameOver.setFont(s_font);
    gameOver.setCharacterSize(36);
    gameOver.setFillColor(Color::White);
    gameOver.setPosition(s_window.getSize().x /2, s_window.getSize().y /2 );

    loadHighScore();


}

void SinglePlayer ::run()
{
    while (s_window.isOpen())
    {
        processEvents();
        update(s_clock.restart());
        updateHighScore();
        render();
    }
    saveHighScore();
}
void SinglePlayer ::selectLevel(int mouseX, int mouseY)
{
    int levelWidth = s_window.getSize().x / 3;
    int selectedLevel = mouseX / levelWidth + 1;

    if (selectedLevel >= 1 && selectedLevel <= 3)
    {
        s_selectedLevel = selectedLevel;
        resetGame();
    }
}

void SinglePlayer::processEvents()
{
    Event event;
    while (s_window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            s_window.close();
        else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            int mouseX = event.mouseButton.x;
            int mouseY = event.mouseButton.y;

            selectLevel(mouseX, mouseY);
        }
    }
}

void SinglePlayer :: loadHighScore(){
    std::ifstream file("highscore.txt");
    if(file.is_open()){
        file >> s_highScore;
        file.close();
    }
}

void SinglePlayer :: saveHighScore(){
    std::ofstream file("highscore.txt");
    if(file.is_open()){
        file << s_highScore;
        file.close();
    }   
}

void SinglePlayer :: updateHighScore(){
    if(s_score > s_highScore){
        s_highScore = s_score;
    }

}

void SinglePlayer::update(Time deltaTime)
{
    if (Keyboard::isKeyPressed(Keyboard::Up) && s_playerPaddle.getPosition().y > 0)
        s_playerPaddle.move(0, -450 * deltaTime.asSeconds());
    if (Keyboard::isKeyPressed(Keyboard::Down) && s_playerPaddle.getPosition().y < s_window.getSize().y - s_playerPaddle.getSize().y)
        s_playerPaddle.move(0, 450 * deltaTime.asSeconds());

    s_ball.move(s_ballVelocity * deltaTime.asSeconds());

    // Collision detection with paddles
    if (s_ball.getGlobalBounds().intersects(s_playerPaddle.getGlobalBounds()))
    {
        s_ball.move(-s_ballVelocity * deltaTime.asSeconds());
        s_ballVelocity.x *= -1; // Reverse the horizontal velocity of the ball
    }
    if (s_ball.getGlobalBounds().intersects(s_cpuPaddle.getGlobalBounds()))
    {
        s_ball.move(-s_ballVelocity * deltaTime.asSeconds());
        s_ballVelocity.x *= -1; // Reverse the horizontal velocity of the ball
    }

    // Collision detection with walls
    if (s_ball.getPosition().y < 0 || s_ball.getPosition().y > s_window.getSize().y - s_ball.getRadius() * 2)
    {
        s_ball.move(0, -s_ballVelocity.y * deltaTime.asSeconds());
        s_ballVelocity.y *= -1; // Reverse the vertical velocity of the ball
    }


    if (s_ball.getPosition().x < 0)
    {
        // Ball hit the left wall, reset its position and reverse the horizontal velocity
        
        s_life--;
        updateLifeText();
        if(s_life <= 0){
            resetGame();
            s_window.clear(sf::Color::Black);
            gameOverText();

            s_window.close();
        }
        s_ball.setPosition(s_window.getSize().x / 2 - s_ball.getRadius(), s_window.getSize().y / 2 - s_ball.getRadius());
        s_ballVelocity.x *= -1;

        
    }

    if (s_ball.getPosition().x > s_window.getSize().x - s_ball.getRadius() * 2)
    {
        // Ball hit the right wall, reset its position and reverse the horizontal velocity
        s_score++;

        updateScoreText();
        s_ball.setPosition(s_window.getSize().x / 2 - s_ball.getRadius(), s_window.getSize().y / 2 - s_ball.getRadius());
        s_ballVelocity.x *= -1;
    }

    // AI / CPU

    if (s_ball.getPosition().y > s_cpuPaddle.getPosition().y + s_cpuPaddle.getSize().y / 2)
        s_cpuPaddle.move(0, 300 * deltaTime.asSeconds());
    if (s_ball.getPosition().y < s_cpuPaddle.getPosition().y + s_cpuPaddle.getSize().y / 2)
        s_cpuPaddle.move(0, -300 * deltaTime.asSeconds());

}
void SinglePlayer::updateScoreText()
{
    s_scoreText.setString("Score: " + std::to_string(s_score));
}
void SinglePlayer::updateLifeText(){
    s_lifeText.setString("Life: " + std::to_string(s_life));
}
void SinglePlayer :: gameOverText(){
    gameOver.setString("Game Over");
}

void SinglePlayer::resetGame()
{
    s_score = 0;
    s_life = 0;
    // setting the ball speed and paddle size based on the selected level
    s_ballVelocity.x = s_levelParameters[s_selectedLevel - 1].s_ballVelocity;
    s_ballVelocity.y = s_levelParameters[s_selectedLevel - 1].s_ballVelocity;
    s_playerPaddle.setSize(s_levelParameters[s_selectedLevel - 1].s_playerPaddle);
}



void SinglePlayer::render()
{
    s_window.clear(s_backgroundColor);
    s_window.draw(s_playerPaddle);
    s_window.draw(s_cpuPaddle);
    s_window.draw(s_ball);
    updateScoreText();
    s_window.draw(s_scoreText);
    s_highScoreText.setString("High Score: " + std::to_string(s_highScore));
    s_window.draw(s_highScoreText);
    updateLifeText();
    s_window.draw(s_lifeText);
    gameOverText();
    s_window.display();
}
