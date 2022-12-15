//
// Created by Jessie Mejia on 12/14/22.
//

#include "MainMenu.h"
#include "Fonts.h"
#include "SFML/Graphics.hpp"

MainMenu::MainMenu(sf::RenderWindow& window)
{
    title.setFont(Fonts::getFont(EightBITIN));
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition({360,200});
    title.setString("Simon Says Memory Game");

    startText.setFont(Fonts::getFont(EightBITIN));
    startText.setCharacterSize(100);
    startText.setLetterSpacing(2);
    startText.setFillColor(sf::Color::Yellow);
    startText.setPosition({static_cast<float>(window.getSize().x) / 2 - 160,500});
    startText.setString("Start");
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!checkState(HIDDEN))
    {
        target.draw(title);
        target.draw(startText);
    }
}

sf::Text MainMenu::getStartText() {
    return startText;
}
