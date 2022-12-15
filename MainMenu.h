//
// Created by Jessie Mejia on 12/14/22.
//

#ifndef SIMONSAYSFINAL_MAINMENU_H
#define SIMONSAYSFINAL_MAINMENU_H

#include <SFML/Graphics.hpp>
#include "States.h"

class MainMenu : public sf::Drawable, public States {
private:
    sf::Text title, startText;
public:
    MainMenu(sf::RenderWindow &window);
    sf::Text getStartText();


protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //SIMONSAYSFINAL_MAINMENU_H
