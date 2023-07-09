
#include<SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include"singlePlayer.h"
#include<SFML/Audio.hpp>

using namespace sf;

int SinglePlayer :: singleplay () {
    RenderWindow window(VideoMode(1300, 800), "PONG GAME");
//font
    Font font;
    if (!font.loadFromFile("sans.ttf")) {
        // handle error if the font file cannot be loaded
       return -1;
    }

   


       //Click Sound
   
   SoundBuffer soundbuffer;
   if(!soundbuffer.loadFromFile("click.wav"))
    {
    //error handling
    return -1;
    }
    Sound soundclick;
    soundclick.setBuffer(soundbuffer);

//menu list
    Text level("CHOOSE LEVEL",font,49);
    level.setFillColor(Color::White);
    level.setPosition(540, 80);

    Text level1("Level 1",font,43);
    level1.setFillColor(Color::White);
    level1.setPosition(580, 170);

    Text level2("Level 2",font,43);
    level2.setFillColor(Color::White);
    level2.setPosition(580, 220);

    Text level3("Level 3",font,43);
    level3.setFillColor(Color::White);
    level3.setPosition(580, 270);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
            { 
                window.close();
            
            }



        //single player
            if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
                Vector2i mousePos = Mouse::getPosition(window);
                soundclick.play();
                

        //         if(level1.getGlobalBounds().contains(Vector2f(mousePos))){

        //             singleplayerlevel1 playsinglelevel1;
        //             playsinglelevel1.render();
        //         }
        //     }
        }

        }

        window.clear(Color(11,47,94));

        window.draw(level1);
        window.draw(level2);
        window.draw(level3);
        window.draw(level);
        window.display();
    
    }

    return 0;
    
            
    
}