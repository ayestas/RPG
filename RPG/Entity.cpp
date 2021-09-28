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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->move(dt, 0.f, 1.f);

}

void Entity::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}


