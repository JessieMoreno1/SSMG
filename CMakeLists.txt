cmake_minimum_required(VERSION 3.23)
project(SimonSaysFinal)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimonSaysFinal main.cpp MouseEvents.cpp MouseEvents.h MainMenu.cpp MainMenu.h States.cpp States.h StatesEnum.h Fonts.cpp Fonts.h FontsEnum.h)
target_link_libraries(SimonSaysFinal sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)