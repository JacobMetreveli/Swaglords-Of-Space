#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>


class Projectile {
    private:
        sf::RectangleShape shape;
        float movementSpeed{};

        // Init functions
        void initVariables();
        void initShape(float x, float y);

    public:
        // Constructor / Destructor
        Projectile(float x, float y);
        ~Projectile();

        // Functions
        sf::Vector2f getProjectilePos() const;

        void update();
        void render(sf::RenderTarget* target);
};
