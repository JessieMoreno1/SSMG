#include <iostream>
#include <algorithm> // needed for std::random_sequence
#include <vector> // needed to create the various vectors we need
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "MouseEvents.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    sf::RectangleShape flashingSquare, squareOne, squareTwo, squareThree, squareFour;

    // create a vector to store the sequence of colors
    std::vector<sf::Color> colorSequence;

    // create an array to store the player's input
    sf::Color playerInput[100];
    int inputIndex = 0;

    // create a variable that keeps track of the player's score
    int score = 0;

    flashingSquare.setSize({100,100});
    flashingSquare.setPosition({570,200});

    squareOne.setSize({100,100});
    squareOne.setFillColor(sf::Color::Blue);
    squareOne.setPosition({350,360});

    squareTwo.setSize({100,100});
    squareTwo.setFillColor(sf::Color::Red);
    squareTwo.setPosition({500, 360});

    squareThree.setSize({100,100});
    squareThree.setFillColor(sf::Color::Yellow);
    squareThree.setPosition({650,360});

    squareFour.setSize({100,100});
    squareFour.setFillColor(sf::Color::Green);
    squareFour.setPosition({800,360});

    sf::RenderWindow window({1280, 720, 32}, "Simon Says Game");

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

    // 1. update the game state

            // 1.1. update the game state
            sf::Clock clock;
            sf::Time getElapsedSeconds = clock.getElapsedTime();

            // 1.2 Check if the player has entered the correct
            // sequence of colors


           bool correctSequence = true;
           for (int i = 0; i < colorSequence.size(); i++)
           {
               // if the players input is not the same as the color
               // sequence then the correct sequence boolean turns false
               if (playerInput[i] != colorSequence[i])
               {
                   correctSequence = false;
                   break;
               }
           }

           // if the player has entered the correct sequence, update the score
           if (correctSequence)
           {
               score++;
               colorSequence.clear();
           }



    // 2. generate a new color for the sequence

            // create a vector of the available colors
            std::vector<sf::Color> availableColors = { sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Green};

            // shuffle the colors in the vector
            std::random_shuffle(availableColors.begin(), availableColors.end());

             // add 4 colors to the colorSequence
             for (int i = 0; i < 4; i++) {
                 sf::Color newColor = availableColors.at(i);
                 colorSequence.push_back(newColor);
             }

            // Play the sequence of colors
           // for (const sf::Color& color : colorSequence)
           // {
           //      // flash the color on the screen
           //      flashingSquare.setFillColor(color);
           //      if (getElapsedSeconds.asSeconds() == 5000)
           //      {
           //          flashingSquare.setFillColor(sf::Color::White);
           //      }
           // }
            if (MouseEvents::isClick(squareOne, window))
            {
                std::cout << "Blue square clicked\n";
                playerInput[inputIndex++] == sf::Color::Blue;
            }
            if (MouseEvents::isClick(squareTwo, window))
            {
                std::cout << "Red square clicked\n";
                playerInput[inputIndex++] == sf::Color::Red;
            }
            if (MouseEvents::isClick(squareThree, window))
            {
                std::cout << "Yellow square clicked\n";
                playerInput[inputIndex++] == sf::Color::Yellow;
            }
            if (MouseEvents::isClick(squareFour, window))
            {
                std::cout << "Green square clicked\n";
                playerInput[inputIndex++] == sf::Color::Green;
            }



        }

        // Play the sequence of colors
        for (const sf::Color& color : colorSequence)
        {
            // flash the color on the screen
            flashingSquare.setFillColor(color);
            sf::sleep(sf::milliseconds(30));
            //flashingSquare.setFillColor(sf::Color::White);
            //sf::sleep(sf::microseconds(100));
        }

        // check the players input and compare it to the sequence
        bool correctSequence = true;
        for (int i = 0; i < colorSequence.size(); i++)
        {
            // if the players input is not the same as the color
            // sequence then the correct sequence boolean turns false
            if (playerInput[i] != colorSequence[i])
            {
                correctSequence = false;
                break;
            }
        }

        // if the player has entered the correct sequence, update the score
        if (correctSequence)
        {
            score++;
            colorSequence.clear();
        }

        // clear the window and draw the updated game state

        window.clear({58,64,90});
        window.draw(flashingSquare);
        window.draw(squareOne);
        window.draw(squareTwo);
        window.draw(squareThree);
        window.draw(squareFour);
        window.display();
    }

    return 0;
}
