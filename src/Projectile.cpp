#include "Projectile.h"


void Projectile::initVariables() {
    this->movementSpeed = -20.f;
}

void Projectile::initShape(sf::Vector2f position, const sf::FloatRect &playerShape) {
    this->shape.setSize(sf::Vector2f(5.f, 20.f));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(position.x + playerShape.width / 2, position.y);
}

Projectile::Projectile(sf::Vector2f position, const sf::FloatRect &playerShape) {
    this->initVariables();
    this->initShape(position, playerShape);
}

Projectile::~Projectile() {

}

void Projectile::update() {
    this->shape.move(0.f, this->movementSpeed);
}

void Projectile::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

sf::Vector2f Projectile::getProjectilePos() const {
    return this->shape.getPosition();
}

sf::RectangleShape Projectile::getProjectileShape() const {
    return this->shape;
}
