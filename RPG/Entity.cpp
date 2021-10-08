#include "Entity.h"

Entity::Entity() {
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Color(222, 107, 72));
	this->movementSpeed = 100.f;
}

Entity::~Entity()
{
}

void Entity::move(const float& dt, const float direction_x, const float direction_y) {
	this->shape.move(direction_x * this->movementSpeed * dt, direction_y * this->movementSpeed * dt);
}

void Entity::update(const float& dt) {
	
}

void Entity::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}


