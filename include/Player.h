#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>


class Player {
    private:
        // Player texture
        sf::Sprite shape;
        sf::Texture texture;


        float movementSpeed{};
        int hp{};
        int hpMax{};


        // Init functions
        void initVariables();
        void initShape();

    public:
        // Constructors and Destructors
        Player();
        ~Player();

        // Accessors
        sf::Sprite getShape() const;
        const int& getHP() const;
        const int& getHPMax() const;

        // Functions
        void setStartPosition(float x, float y);

        void updateInput(sf::RenderTarget* target);
        void updateBorders(sf::RenderTarget* target);

        void update(sf::RenderTarget* target);
        void render(sf::RenderTarget* target);
};