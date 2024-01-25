#include "Player.h"
#include <iostream>

// Init functions
void Player::initVariables()
{
    this->movementSpeed = 10.f;
    this->hpMax = 100;
    this->hp = hpMax;
}


void Player::initShape() 
{
    if (!texture.loadFromFile("/home/simteam-j/Workspaces/SFML_G3/Assets/spaceships/Spaceship_tut.png"))
        std::cerr << "ERROR::PLAYER::Failed to load texture\n";
    this->shape.setTexture(texture);
    this->shape.setPosition(300.f, 300.f);
    this->shape.setScale(0.5f, 0.5f);
}


Player::Player() {
    this->initVariables();
    this->initShape();
}


Player::~Player() {

}


sf::Sprite Player::getShape() const {
    return this->shape;
}

const int &Player::getHP() const {
    return this->hp;
}

const int &Player::getHPMax() const {
    return this->hpMax;
}

void Player::updateInput() {
    // Player position
    sf::Vector2f position = this->shape.getPosition();

    // Player movement with keyboard
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        this->shape.move(0.f, -this->movementSpeed);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->shape.move(0.f, this->movementSpeed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        this->shape.move(-this->movementSpeed, 0.f);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->shape.move(this->movementSpeed, 0.f);
}

void Player::update(const sf::RenderTarget *target) {
    this->updateInput();
}

void Player::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}




