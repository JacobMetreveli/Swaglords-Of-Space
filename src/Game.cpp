#include "Game.h"

// Init functions
void Game::initVariables()
{
}


void Game::initWindow()
{
    this->videoMode = sf::VideoMode(600, 700);
    this->window = new sf::RenderWindow(videoMode, "Swaglords Of Space", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

// Constructor and Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->player.setStartPosition(static_cast<float>(this->window->getSize().x) / 2.f, static_cast<float>(this->window->getSize().y));
}


Game::~Game()
{
    delete this->window;
}

// Functions
void Game::pollEvents()
{
    sf::Event sfmlEvent{};
    while (this->window->pollEvent(sfmlEvent)) {
        switch (sfmlEvent.type) {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if (sfmlEvent.key.code == sf::Keyboard::Escape)
                    this->window->close();

                if (sfmlEvent.key.code == sf::Keyboard::Space)
                    this->projectiles.push_back(Projectile(this->player.getCurrentPosition()));
                break;

            default:
                break;
        }
    }
}


void Game::update()
{
    this->pollEvents();
    player.update(this->window);
}


void Game::render()
{
    // Clear previous frame
    window->clear(sf::Color::Black);
    // Render stuff
    player.render(this->window);

    // Display the contents of the window
    this->window->display();
}

// Main game loop
void Game::run() {
    while (window->isOpen()) {
        this->update();
        this->render();
    }
}
