#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <vector>

#include "Player.h"
#include "Projectile.h"


class Game {
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window{};

        // Player object
        Player player;

        // Projectiles vector
        std::vector<Projectile> projectiles;

        // init functions
        void initVariables();
        void initWindow();
    public:
        // Constructor and Destructor
        Game();
        ~Game();

        // Functions
        void pollEvents();

        void update();
        void render();

        void run();
};