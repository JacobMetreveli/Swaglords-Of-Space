#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Polygon {
    private:
        sf::CircleShape polygon;
        float movementSpeed{};

        void initVariables();
        void initPolygon(sf::RenderTarget* target);
    public:
        Polygon(sf::RenderTarget* target);
        ~Polygon();

        // accessors
        sf::CircleShape getPolygon();

        // Functions
        void update();
        void render(sf::RenderTarget* target);
};


