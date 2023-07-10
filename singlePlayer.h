#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class SinglePlayer
{
public:
    SinglePlayer();
    void run();
    void selectLevel(int mouseX, int mouseY);
    void getScore(int score);

private:
    void processEvents();
    void update(Time deltaTime);
    void loadHighScore();
    void saveHighScore();
    void updateHighScore();
    void updateScoreText();
    void updateLifeText();
    void gameOverText();
    void render();
    void resetGame();

    RenderWindow s_window;
    int s_selectedLevel;
    Color s_backgroundColor;
    Color s_paddleColor;
    Color s_ballColor;
    RectangleShape s_playerPaddle;
    RectangleShape s_cpuPaddle;
    CircleShape s_ball;
    Vector2f s_ballVelocity;
    int s_paddleVelocity;
    int s_life;
    int s_highScore;
    int s_score;
    Font s_font;
    Text s_lifeText;
    Text s_highScoreText;
    Text s_scoreText;
    Text gameOver;
    Clock s_clock;
    struct LevelParameters
    {
        float s_ballVelocity;
        Vector2f s_playerPaddle;
        
    };

    LevelParameters s_levelParameters[3] = {
        {300.f, Vector2f(25, 120)},
        {500.f, Vector2f(25, 90)},
        {600.f, Vector2f(25, 70)},
    };
};
