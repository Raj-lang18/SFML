// #include <iostream>
// #include <fstream>

// using namespace std;

// int main(){
//     int initialScore = 0; 

//     ofstream file("High_Score.txt");
//     file<<initialScore;

//     if(!ifstream("High_Score.txt"))
//     {
//         cout<<"The file is not created.";
//     }
//     else
//     {
//         ifstream file("High_Score.txt");
//         if(initialScore<=0)
//         {
//             cout<<initialScore;
//         }


//     }
// }






// int Score :: highscore () {
//     RenderWindow window(VideoMode(1300, 800), "PONG GAME");

// //font
//     Font font;
//     if (!font.loadFromFile("sans.ttf")) {
//         // handle error if the font file cannot be loaded
//        return -1;
//     }

// //menu list
//     Text highscore("HIGH SCORE",font,75);
//     highscore.setFillColor(Color::White);
//     highscore.setPosition(540, 80);


//     while (window.isOpen()) {
//         Event event;
//         while (window.pollEvent(event)) 
//         {
//             if (event.type == Event::Closed)
//             { 
//                 window.close();
            
//             }

//       }
//         window.clear(Color(11,47,94));

//         window.draw(highscore);

//         window.display();


//     }


//     return 0;

// }


#include<iostream>
#include <fstream>
#include"Score.h"
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int Score:: highscore ()

{
    int initialScore = 0;

    //Rendering
    RenderWindow window(VideoMode(1300, 800), "HIGH SCORE");

    //font
    Font font;
    if (!font.loadFromFile("sans.ttf")) {
        // handle error if the font file cannot be loaded
       return -1;
    }

    //menu list
    Text highscore("HIGH SCORE",font,75);
    highscore.setFillColor(Color::White);
    highscore.setPosition(540, 80);


    Text text;
    text.setString(to_string(initialScore));
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(100, 100);


    //file handling
    ofstream file("High_Score.txt");
    file<<initialScore;

    if(!ifstream("High_Score.txt"))
    {
        cout<<"The file is not found.";
    }


    //WINDOWS LOOPING

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(11,47,94));

        window.draw(highscore);
        window.draw(text);
        

        window.display();
    }

    return 0;
    
}