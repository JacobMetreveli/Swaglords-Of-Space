#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>


class Player {
    private:
        // Player texture
        sf::Sprite sprite;
        sf::Texture texture;

        // Attributes
        float movementSpeed{};
        int hp{};
        int hpMax{};

        // Init functions
        void initVariables();
        void initSprite();

    public:
        // Constructors and Destructors
        Player();
        ~Player();

        // Accessors
        sf::Sprite getSprite() const;
        const int& getHP() const;
        const int& getHPMax() const;

        // Functions
        void setStartPosition(float x, float y);
        sf::Vector2f getCurrentPosition();

        void updateInput(sf::RenderTarget* target);

        void update(sf::RenderTarget* target);
        void render(sf::RenderTarget* target);
};