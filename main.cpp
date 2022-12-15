#include <iostream>
#include <algorithm> // needed for std::random_sequence
#include <vector> // needed to create the various vectors we need
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "MouseEvents.h"
#include "MainMenu.h"

int main() {

    sf::RectangleShape flashingSquare, squareOne, squareTwo, squareThree, squareFour;

    // create a vector of the available colors
    std::vector<sf::Color> availableColors = { sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Green};

    // create a vector to store the sequence of colors
    std::vector<sf::Color> colorSequence;

    // create a vector to store the player's input
    std::vector<sf::Color> playerInput;

    // create clock for delay purposes
    sf::Clock clock;

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

    MainMenu m(window);


    while (window.isOpen())
    {

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }


            if (MouseEvents::isClick(squareOne, window))
            {
                std::cout << "Blue square clicked\n";
                playerInput.push_back(sf::Color::Blue);
                // std::cout << playerInput.size() << std::endl;
            }
            if (MouseEvents::isClick(squareTwo, window))
            {
                std::cout << "Red square clicked\n";
                playerInput.push_back(sf::Color::Red);
                // std::cout << playerInput.size()<< std::endl;

            }
            if (MouseEvents::isClick(squareThree, window))
            {
                std::cout << "Yellow square clicked\n";
                playerInput.push_back(sf::Color::Yellow);
                // std::cout << playerInput.size()<< std::endl;

            }
            if (MouseEvents::isClick(squareFour, window))
            {
                std::cout << "Green square clicked\n";
                playerInput.push_back(sf::Color::Green);
                // std::cout << playerInput.size()<< std::endl;

            }

            if (MouseEvents::isClick(m.getStartText(), window))
            {
                m.enableState(HIDDEN);
            }

        }

        // shuffle the colors in the vector
        std::random_shuffle(availableColors.begin(), availableColors.end());

        if (colorSequence.size() <= 4)
        {
            // add 4 colors to the colorSequence
            sf::Color newColor = availableColors.at(0);
            colorSequence.push_back(newColor);
        }

        // Play the sequence of colors
        for (const sf::Color& color : colorSequence)
        {
            if (clock.getElapsedTime().asSeconds() >= .25f)
            {
                // flash the color on the screen
                flashingSquare.setFillColor(color);
                clock.restart();
            }
        }

        // check the players input and compare it to the sequence
        bool correctSequence = true;

        if (playerInput.size() == colorSequence.size()) {
            for (int i = 0; i < colorSequence.size(); i++) {
                // if the players input is not the same as the color
                // sequence then the correct sequence boolean turns false
                if (playerInput[i] != colorSequence[i]) {
                    std::cout << "Incorrect sequence\n";
                    correctSequence = false;
                    playerInput.clear();
                    colorSequence.clear();
                    break;
                }
            }
            // if the player has entered the correct sequence, update the score
            if (correctSequence) {
                std::cout << "Correct sequence found\n";
                score++;
                colorSequence.clear();
                playerInput.clear();
            }
            std::cout << "\nScore: " << score << std::endl;
        }
        // clear the window and draw the updated game state

        window.clear({58,64,90});
        window.draw(m);
        window.draw(flashingSquare);
        window.draw(squareOne);
        window.draw(squareTwo);
        window.draw(squareThree);
        window.draw(squareFour);
        window.display();
    }

    return 0;
}
