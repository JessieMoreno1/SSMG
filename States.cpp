//
// Created by Jessie Mejia on 12/14/22.
//

#include "States.h"

bool States::checkState(StatesEnum state) const {
    return map.at(state);
}

void States::enableState(StatesEnum state) {
    setState(state,true);
}

void States::disableState(StatesEnum state) {
    setState(state,false);
}

void States::setState(StatesEnum state, bool value) {
    map.at(state) = value;
}

void States::toggleState(StatesEnum state) {
    setState(state, !map.at(state));
}

States::States() {
    load();
}

void States::load() {
    for (int i = 0; i < LAST_STATE; i++)
    {
        map[static_cast<StatesEnum>(i)] = false;
    }
}