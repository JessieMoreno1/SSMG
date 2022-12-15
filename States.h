//
// Created by Jessie Mejia on 12/14/22.
//

#ifndef SIMONSAYSFINAL_STATES_H
#define SIMONSAYSFINAL_STATES_H

#include <SFML/Graphics.hpp>
#include <map>
#include "StatesEnum.h"

class States {
private:
    std::map<StatesEnum, bool> map;
    void load();
public:
    States();
    bool checkState(StatesEnum state) const;
    void enableState(StatesEnum state);
    void disableState(StatesEnum state);
    void setState(StatesEnum state, bool value);
    void toggleState(StatesEnum state);
};


#endif //SIMONSAYSFINAL_STATES_H
