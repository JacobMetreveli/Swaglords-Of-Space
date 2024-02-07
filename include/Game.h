#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <vector>

#include "Player.h"
#include "Projectile.h"
#include "Polygon.h"


class Game {
    private:
        // Window
        sf::VideoMode videoMode;
        sf::RenderWindow* window{};
        sf::Texture bgTexture{};
        sf::Sprite background{};

        // Player object
        Player player;

        // Projectiles
        std::vector<Projectile> projectiles;
        const int projectileMaxTimer{30};
        int projectileSpawnTimer{};

        // Enemy Polygons
        std::vector<Polygon> polygons;
        const int enemySpawnTimerMax{25};
        int enemySpawnTimer{};
        const int maxEnemyCount{12};
        int currEnemyCount{};

        // init functions
        void initVariables();
        void initWindow();

        // Functions
        void pollEvents();

        void handle_collision();

        void updateProjectiles();
        void updatePolygons();
        void update();

        void render();


    public:
        // Constructor and Destructor
        Game();
        ~Game();

        void run();
};