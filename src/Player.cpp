#include "Player.h"
#include <iostream>

// Init functions
void Player::initVariables()
{
    this->movementSpeed = 10.f;
    this->hpMax = 100;
    this->hp = hpMax;
}


void Player::initSprite()
{
    if (!texture.loadFromFile("/home/simteam-j/Workspaces/SFML_G3/Assets/spaceships/Spaceship_tut.png"))
        std::cerr << "ERROR::PLAYER::Failed to load texture\n";
    this->sprite.setTexture(texture);
    this->sprite.setScale(0.4f, 0.3f);
}


Player::Player() {
    this->initVariables();
    this->initSprite();
}


Player::~Player() {
    delete this;
}


sf::Sprite Player::getSprite() const {
    return this->sprite;
}

const int &Player::getHP() const {
    return this->hp;
}

const int &Player::getHPMax() const {
    return this->hpMax;
}

void Player::updateInput(sf::RenderTarget* target) {
    // Player position
    sf::Vector2f position = this->sprite.getPosition();
    sf::Vector2f border = static_cast<sf::Vector2f>(target->getSize());
    sf::FloatRect shapeSize = this->sprite.getGlobalBounds();

    // Player movement with keyboard
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && position.y >= this->movementSpeed)
        this->sprite.move(0.f, -this->movementSpeed);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y <= border.y - this->movementSpeed - shapeSize.height)
        this->sprite.move(0.f, this->movementSpeed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && position.x >= this->movementSpeed)
        this->sprite.move(-this->movementSpeed, 0.f);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.x <= border.x - this->movementSpeed - shapeSize.width)
        this->sprite.move(this->movementSpeed, 0.f);

}

void Player::update(sf::RenderTarget *target) {
    this->updateBorders(target);
    this->updateInput(target);
}

void Player::render(sf::RenderTarget *target) {
    target->draw(this->sprite);
}

void Player::setStartPosition(float x, float y) {
    sf::FloatRect shape_borders = this->sprite.getGlobalBounds();
    this->sprite.setPosition(x - shape_borders.width / 2.f, y - shape_borders.height);
}

void Player::updateBorders(sf::RenderTarget* target) {

}

sf::Vector2f Player::getCurrentPosition() {
    return this->sprite.getPosition();
}
