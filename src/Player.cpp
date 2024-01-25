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
    this->shape.setScale(0.4f, 0.3f);
}


Player::Player() {
    this->initVariables();
    this->initShape();
}


Player::~Player() {
    delete this;
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

void Player::updateInput(sf::RenderTarget* target) {
    // Player position
    sf::Vector2f position = this->shape.getPosition();
    sf::Vector2f border = static_cast<sf::Vector2f>(target->getSize());
    sf::FloatRect shapeSize = this->shape.getGlobalBounds();

    // Player movement with keyboard
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && position.y >= this->movementSpeed)
        this->shape.move(0.f, -this->movementSpeed);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y <= border.y - this->movementSpeed - shapeSize.height)
        this->shape.move(0.f, this->movementSpeed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && position.x >= this->movementSpeed)
        this->shape.move(-this->movementSpeed, 0.f);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.x <= border.x - this->movementSpeed - shapeSize.width)
        this->shape.move(this->movementSpeed, 0.f);
}

void Player::update(sf::RenderTarget *target) {
    this->updateBorders(target);
    this->updateInput(target);
}

void Player::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

void Player::setStartPosition(float x, float y) {
    sf::FloatRect shape_borders = this->shape.getGlobalBounds();
    this->shape.setPosition(x - shape_borders.width / 2.f, y - shape_borders.height);
}

void Player::updateBorders(sf::RenderTarget* target) {

}




