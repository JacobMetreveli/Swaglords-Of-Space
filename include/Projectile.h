#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include <vector>

class Projectile {
    private:
        sf::RectangleShape shape;
        float movementSpeed{};

        // Init functions
        void initVariables();
        void initShape(sf::Vector2f position, const sf::FloatRect &playerShape);

    public:
        // Constructor / Destructor
        explicit Projectile(sf::Vector2f position, const sf::FloatRect &playerShape);
        ~Projectile();

        // Accessors
        sf::Vector2f getProjectilePos() const;

        // Functions
        void update();
        void render(sf::RenderTarget* target);
};
