#include<SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"menu.h"
#include"howToPlay.h"
#include"singlePlayer.h"
#include"Score.h"


using namespace sf;

bool isMusicPlaying = true;
int changetheme = 1;


int menu :: options () {
    RenderWindow window(VideoMode(1300, 800), "PONG GAME");

    //background sound
    SoundBuffer soundbuffer1;
   if(!soundbuffer1.loadFromFile("bgmusic.wav"))
    {
    //error handling
    return -1;
    }
    Sound soundbg;
    soundbg.setBuffer(soundbuffer1);
    soundbg.play();
    soundbg.setVolume(5);



       //Click Sound
   
   SoundBuffer soundbuffer2;
   if(!soundbuffer2.loadFromFile("click.wav"))
    {
    //error handling
    return -1;
    }
    Sound soundclick;
    soundclick.setBuffer(soundbuffer2);



    //mute button
        Texture mutetexture;
        if(!mutetexture.loadFromFile("./images/mute-button.png"))
        {
            //error handling
            return -1;
        }

        Sprite mutebutton(mutetexture);
        mutebutton.setPosition(100,700);
        mutebutton.setScale(0.05,0.05);
        mutebutton.setColor(Color::Black);

        

//  //background theme
        
        Texture imagetexture1;
        if(!imagetexture1.loadFromFile("./images/theme2.jpg"))
        {
            //error handling
            return -1;
        }
                   
        Sprite imagesprite(imagetexture1);
        imagesprite.setScale(0.5,0.5);
    

//font
    Font font;
    if (!font.loadFromFile("sans.ttf")) {
        // handle error if the font file cannot be loaded
        return -1;
    }


//menu list
    Text title("PONG MENU",font,90);
    title.setFillColor(Color::White);
    title.setPosition(510, 80);

    Text single("Single Player",font,55);
    single.setFillColor(Color::White);
    single.setPosition(560, 200);

    Text multi("Multi Player",font,55);
    multi.setFillColor(Color::White);
    multi.setPosition(560, 270);

    Text info("How to play",font,55);
    info.setFillColor(Color::White);
    info.setPosition(560, 340);

    Text score("High Score",font,55);
    score.setFillColor(Color::White);
    score.setPosition(560,410);

    Text exit("Exit",font,55);
    exit.setFillColor(Color::White);
    exit.setPosition(640, 480);

    // Text Theme1 ("Theme1 ",font,20);
    // Theme1 .setFillColor(Color::White);
    // Theme1 .setPosition(300, 700);

    // Text Theme2("Theme2",font,20);
    // Theme2.setFillColor(Color::White);
    // Theme2.setPosition(390, 700);

    // Text Theme3("Theme3",font,20);
    // Theme3.setFillColor(Color::White);
    // Theme3.setPosition(480, 700);



//ui
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
             window.close();

            //click event

            else if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
                Vector2i mousePos = Mouse::getPosition(window);

                        

                         soundclick.play();
                         soundclick.setVolume(40);

                //to mute the sound

                    if(mutebutton.getGlobalBounds().contains(Vector2f(mousePos))){
                   
                        if(isMusicPlaying)
                        {
                            soundbg.pause();
                            isMusicPlaying = false;
                        }
                        else
                        {
                            soundbg.play();
                            isMusicPlaying = true;

                        }

                }



                // how to play

                else if(info.getGlobalBounds().contains(Vector2f(mousePos))){
                    howToPlay how;
                    how.information();


                }
            


                 //single player

                else if(single.getGlobalBounds().contains(Vector2f(mousePos))){
                    SinglePlayer playsingle;
                    playsingle.singleplay();
                    
                   

                }
            
        


        // //multi player

        //         else if(multi.getGlobalBounds().contains(Vector2f(mousePos))){
        //             multiPlayer playmulti;
        //             playmulti.multiplay();
        //         }
        //     }
        // }



        //high score

                else if(score.getGlobalBounds().contains(Vector2f(mousePos))){
                  Score score;
                    score.highscore();
                }

        //exit 

                else if(exit.getGlobalBounds().contains(Vector2f(mousePos))){
                    window.close();
                }


            }
        }


        






            
        



        window.clear();

        window.draw(imagesprite);
        window.draw(title);
        window.draw(single);
        window.draw(score);
        window.draw(info);
        window.draw(multi);
        window.draw(exit);
        // window.draw(Theme1);
        // window.draw(Theme2);
        // window.draw(Theme3);
        window.draw(mutebutton);

        
      
        window.display();
    }
    
            
    return 0;
}





