#include "Game.h"
#include <iostream>

// Init functions
void Game::initVariables()
{
    this->projectileSpawnTimer = this->projectileMaxTimer;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->currEnemyCount = 0;
}

void Game::initWindow()
{
    this->videoMode = sf::VideoMode(600, 700);
    this->window = new sf::RenderWindow(videoMode, "Swaglords Of Space", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);

    if (!this->bgTexture.loadFromFile("../Assets/background/backgroundSpace_01.1.png"))
        std::cerr << "ERROR::BACKGROUND::THEME failed to load..." << std::endl;
    this->background.setTexture(this->bgTexture);
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

            default:
                break;
        }
    }
}


void Game::update()
{
    this->pollEvents();
    player.update(this->window);
    this->updateProjectiles();
    this->updatePolygons();
}


void Game::render()
{
    // Clear previous frame
    this->window->clear(sf::Color::Black);

    // Render stuff

    this->window->draw(this->background);
    player.render(this->window);
    // Render projectiles
    for (auto &projectile : this->projectiles)
        projectile.render(this->window);
    // Render enemy polygons
    for (auto &polygon : this->polygons)
        polygon.render(this->window);

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


void Game::updateProjectiles() {
    // Projectile spawn and movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (this->projectileSpawnTimer % this->projectileMaxTimer) == 0) {
        this->projectiles.emplace_back(this->player.getCurrentPosition(), this->player.getSprite().getGlobalBounds());
        this->projectileSpawnTimer = 1;
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->projectileSpawnTimer = this->projectileMaxTimer;
    else
        this->projectileSpawnTimer++;

    // Update all the projectiles
    for (int i = 0; i < projectiles.size(); i++) {
        if (projectiles[i].getProjectilePos().y < 0)
            projectiles.erase(projectiles.begin() + i);
        else
            projectiles[i].update();
    }
}

void Game::updatePolygons() {
    // Handle projectile spawn
    if (this->enemySpawnTimer >= this->enemySpawnTimerMax && this->currEnemyCount < this->maxEnemyCount) {
        polygons.emplace_back(this->window);
        this->enemySpawnTimer = 0;
        this->currEnemyCount++;
    } else {
        this->enemySpawnTimer++;
    }

    for (int i = 0; i < polygons.size(); i++)
        polygons[i].update();
}
