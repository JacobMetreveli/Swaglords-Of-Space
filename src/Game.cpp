#include "Game.h"

// Init functions
void Game::initVariables()
{
    this->endGame = true;
}


void Game::initWindow()
{
    this->videoMode = sf::VideoMode(600, 700);
    this->window = new sf::RenderWindow(videoMode, "Swaglords Of Space", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

// Constructor and Destructor
Game::Game()
{
    this->initVariables();
    this->initWindow();

}


Game::~Game()
{
    delete this->window;
}

// Check if game is running
bool Game::running() const
{
    return this->endGame;
}

// Functions
void Game::pollEvents()
{
    while (this->window->pollEvent(sfmlEvent)) {
        switch (this->sfmlEvent.type) {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
                    this->window->close();
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
