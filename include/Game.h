#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Player.h"


class Game {
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window{};
        bool endGame{};
        sf::Event sfmlEvent{};

        // Player object
        Player player;

        // init functions
        void initVariables();
        void initWindow();
    public:
        // Constructor and Destructor
        Game();
        ~Game();

        // Functions
        bool running() const;
        void pollEvents();

        void update();
        void render();
};