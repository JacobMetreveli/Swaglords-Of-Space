#include "Polygon.h"
#include <ctime>

void Polygon::initVariables() {
    this->movementSpeed = 2.f;
}

void Polygon::initPolygon(sf::RenderTarget* target) {
    this->polygon = sf::CircleShape(static_cast<float>(rand() % 40 + 25), rand() % 8 + 3);
    this->polygon.setFillColor(sf::Color::Red);
    this->polygon.setPosition(static_cast<float>(rand() % target->getSize().x - 80), static_cast<float>(rand() % 50 - 100));
}

Polygon::Polygon(sf::RenderTarget* target) {
    this->initVariables();
    this->initPolygon(target);
}


Polygon::~Polygon() {

}

sf::CircleShape Polygon::getPolygon() {
    return this->polygon;
}

void Polygon::update() {
    this->polygon.move(0.f, this->movementSpeed);
}

void Polygon::render(sf::RenderTarget *target) {
    target->draw(this->polygon);
}