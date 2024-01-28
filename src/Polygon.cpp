#include "Polygon.h"
#include <ctime>

void Polygon::initVariables() {
    this->movementSpeed = 1.f;
}

void Polygon::initPolygon(sf::RenderTarget* target) {
    this->polygon = sf::CircleShape(static_cast<float>(rand() % 60 + 25), rand() % 8);
    this->polygon.setFillColor(
            sf::Color(rand() % 255, rand() % 255, rand() % 255)
            );
    this->polygon.setPosition(static_cast<float>(rand() % target->getSize().x), 0);
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