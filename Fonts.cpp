//
// Created by Jessie Mejia on 12/14/22.
//

#include "Fonts.h"

std::map<FontsEnum, sf::Font> Fonts::map;

void Fonts::load(FontsEnum font) {

    map[font].loadFromFile(getPath(font));
}

std::string Fonts::getPath(FontsEnum font) {
    switch(font)
    {
        case EightBITOUT: return "Fonts/8-bit Arcade Out.ttf";
        case EightBITIN: return "Fonts/8-bit Arcade In.ttf";
            // add path if adding new fonts and add in fontEnum.h
        case LAST_FONT: return "";

    }

    return std::string();
}

sf::Font &Fonts::getFont(FontsEnum font) {
    load(font);
    return map[font];
}