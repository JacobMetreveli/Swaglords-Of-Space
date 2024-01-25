#include "Projectile.h"

void Projectile::initVariables() {
    this->movementSpeed = 15.f;
}

void Projectile::initShape(position) {
    this->shape.setSize(sf::Vector2f(5.f, 20.f));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition()
}

Projectile::Projectile(sf::Vector2f position) {
    this->initVariables();
    this->initShape(position);
}

Projectile::~Projectile() {

}

void Projectile::update() {
    this->shape.move(0.f, -this->movementSpeed);
}

void Projectile::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

sf::Vector2f Projectile::getProjectilePos() const {
    return this->shape.getPosition();
}
