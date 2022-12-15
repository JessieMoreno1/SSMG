//
// Created by Jessie Mejia on 12/14/22.
//

#ifndef SIMONSAYSFINAL_FONTS_H
#define SIMONSAYSFINAL_FONTS_H

#include "FontsEnum.h"
#include <SFML/Graphics.hpp>
#include <map>

class Fonts {
private:
    static std::map<FontsEnum, sf::Font> map;
    static void load(FontsEnum font);
    static std::string getPath(FontsEnum font);
public:
    static sf::Font& getFont(FontsEnum font);
};


#endif //SIMONSAYSFINAL_FONTS_H
