// #include "MultiPlayer.h"
// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include<fstream>
// using namespace sf;

// MultiPlayer::MultiPlayer() : s_backgroundColor(Color::Black),
//                                s_paddleColor(Color::White),
//                                s_ballColor(Color::White),
//                                s_playerPaddleL(Vector2f(25, 70)),
//                                s_playerPaddleR(Vector2f(25, 120)),
                               
//                                s_paddleVelocity(7),
//                                s_ball(15),
//                                s_ballVelocity(200, 200),
                               
//                                s_selectedLevel(1)


// {
//     s_window.create(VideoMode(1280, 800), "Single Player Pong(Easy)"); // Initialize s_window
//     // setting up player paddle
//     s_playerPaddleL.setFillColor(s_paddleColor);
//     s_playerPaddleL.setPosition(10.f, s_window.getSize().y / 2 - s_playerPaddleL.getSize().y / 2);

//     // setting up opponents paddle
//     s_playerPaddleR.setFillColor(s_paddleColor);
//     s_playerPaddleR.setPosition(s_window.getSize().x - 35, s_window.getSize().y / 2 - s_playerPaddleR.getSize().y / 2);

//     // setting up ball
//     s_ball.setFillColor(s_ballColor);
//     s_ball.setPosition(s_window.getSize().x / 2 - s_ball.getRadius(), s_window.getSize().y / 2 - s_ball.getRadius());

//     // font
//     s_font.loadFromFile("arial.ttf");

    
//     //gameover
//     gameOver.setFont(s_font);
//     gameOver.setCharacterSize(36);
//     gameOver.setFillColor(Color::White);
//     gameOver.setPosition(s_window.getSize().x /2, s_window.getSize().y /2 );



// }

// void MultiPlayer ::run()
// {
//     while (s_window.isOpen())
//     {
//         processEvents();
//         update(s_clock.restart());
        
//         render();
//     }
    
// }


// void MultiPlayer::processEvents()
// {
//     Event event;
//     while (s_window.pollEvent(event))
//     {
//         if (event.type == Event::Closed)
//             s_window.close();
//         else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//         {
//             int mouseX = event.mouseButton.x;
//             int mouseY = event.mouseButton.y;

//             selectLevel(mouseX, mouseY);
//         }
//     }
// }

// void MultiPlayer :: loadHighScore(){
//     std::ifstream file("highscore.txt");
//     if(file.is_open()){
//         file >> s_highScore;
//         file.close();
//     }
// }

// void MultiPlayer :: saveHighScore(){
//     std::ofstream file("highscore.txt");
//     if(file.is_open()){
//         file << s_highScore;
//         file.close();
//     }   
// }

// void MultiPlayer :: updateHighScore(){
//     if(s_score > s_highScore){
//         s_highScore = s_score;
//     }

// }

// void MultiPlayer::update(Time deltaTime)
// {
//     if (Keyboard::isKeyPressed(Keyboard::Up) && s_playerPaddleL.getPosition().y > 0)
//         s_playerPaddleL.move(0, -450 * deltaTime.asSeconds());
//     if (Keyboard::isKeyPressed(Keyboard::Down) && s_playerPaddleL.getPosition().y < s_window.getSize().y - s_playerPaddleL.getSize().y)
//         s_playerPaddleL.move(0, 450 * deltaTime.asSeconds());

//     s_ball.move(s_ballVelocity * deltaTime.asSeconds());

//     // Collision detection with paddles
//     if (s_ball.getGlobalBounds().intersects(s_playerPaddleL.getGlobalBounds()))
//     {
//         s_ball.move(-s_ballVelocity * deltaTime.asSeconds());
//         s_ballVelocity.x *= -1; // Reverse the horizontal velocity of the ball
//     }
//     if (s_ball.getGlobalBounds().intersects(s_playerPaddleR.getGlobalBounds()))
//     {
//         s_ball.move(-s_ballVelocity * deltaTime.asSeconds());
//         s_ballVelocity.x *= -1; // Reverse the horizontal velocity of the ball
//     }

//     // Collision detection with walls
//     if (s_ball.getPosition().y < 0 || s_ball.getPosition().y > s_window.getSize().y - s_ball.getRadius() * 2)
//     {
//         s_ball.move(0, -s_ballVelocity.y * deltaTime.asSeconds());
//         s_ballVelocity.y *= -1; // Reverse the vertical velocity of the ball
//     }


//     if (s_ball.getPosition().x < 0)
//     {
//         // Ball hit the left wall, reset its position and reverse the horizontal velocity
        
//         s_life--;
//         updateLifeText();
//         if(s_life <= 0){
//             resetGame();
//             s_window.clear(sf::Color::Black);
//             gameOverText();

//             s_window.close();
//         }
//         s_ball.setPosition(s_window.getSize().x / 2 - s_ball.getRadius(), s_window.getSize().y / 2 - s_ball.getRadius());
//         s_ballVelocity.x *= -1;

        
//     }

//     if (s_ball.getPosition().x > s_window.getSize().x - s_ball.getRadius() * 2)
//     {
//         // Ball hit the right wall, reset its position and reverse the horizontal velocity
//         s_score++;

//         updateScoreText();
//         s_ball.setPosition(s_window.getSize().x / 2 - s_ball.getRadius(), s_window.getSize().y / 2 - s_ball.getRadius());
//         s_ballVelocity.x *= -1;
//     }

//     // AI / CPU

//     if (s_ball.getPosition().y > s_playerPaddleR.getPosition().y + s_playerPaddleR.getSize().y / 2)
//         s_playerPaddleR.move(0, 300 * deltaTime.asSeconds());
//     if (s_ball.getPosition().y < s_playerPaddleR.getPosition().y + s_playerPaddleR.getSize().y / 2)
//         s_playerPaddleR.move(0, -300 * deltaTime.asSeconds());

// }
// void MultiPlayer::updateScoreText()
// {
//     s_scoreText.setString("Score: " + std::to_string(s_score));
// }
// void MultiPlayer::updateLifeText(){
//     s_lifeText.setString("Life: " + std::to_string(s_life));
// }
// void MultiPlayer :: gameOverText(){
//     gameOver.setString("Game Over Fuck OFF");
// }

// void MultiPlayer::resetGame()
// {
//     s_score = 0;
//     s_life = 0;
//     // setting the ball speed and paddle size based on the selected level
//     s_ballVelocity.x = s_levelParameters[s_selectedLevel - 1].s_ballVelocity;
//     s_ballVelocity.y = s_levelParameters[s_selectedLevel - 1].s_ballVelocity;
//     s_playerPaddleL.setSize(s_levelParameters[s_selectedLevel - 1].s_playerPaddleL);
// }



// void MultiPlayer::render()
// {
//     s_window.clear(s_backgroundColor);
//     s_window.draw(s_playerPaddleL);
//     s_window.draw(s_playerPaddleR);
//     s_window.draw(s_ball);
//     updateScoreText();
//     s_window.draw(s_scoreText);
//     s_highScoreText.setString("High Score: " + std::to_string(s_highScore));
//     s_window.draw(s_highScoreText);
//     updateLifeText();
//     s_window.draw(s_lifeText);
//     gameOverText();
//     s_window.display();
// }
