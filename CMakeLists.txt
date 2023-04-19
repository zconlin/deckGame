cmake_minimum_required(VERSION 3.23)
project(deckGame)

set(CMAKE_CXX_STANDARD 17)

# Add the source files
add_executable(deckGame
        src/main.cpp
        src/Card.cpp
        src/Deck.cpp
        src/Player.cpp
        src/Game.cpp)