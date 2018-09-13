/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Character
*/

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Character.hpp"
#include "Projectile.hpp"

namespace rtype
{

Character::Character(const sf::Texture &texture, RType *scene, RACE race)
	: Colisable(texture, scene, race), _speed(10), _lifePoints(3),
	_attackClock(), _fireSpeed(500)
{
	_attackClock.restart();
}

void Character::update(std::vector<std::unique_ptr<Displayable>> &objects)
{
	Colisable::update(objects);
	for (auto &object : objects) {
		auto casted = dynamic_cast<Colisable*>(object.get());
		if (casted == nullptr || casted == this)
			continue;
		if (casted->getRace() != _race)
			if (casted->intersect(getHitbox()))
				casted->action(*this);
	}
	sf::Vector2f position(getPosition());
	if (position.y > _scene->getWindow().getSize().y)
		setPositions(position.x, 0);
	else if (position.y < 0)
		setPositions(position.x, _scene->getWindow().getSize().y);
}

void Character::takeDamage(int damage)
{
	_lifePoints -= damage;
	if (_lifePoints <= 0)
		_isActive = false;
}

}
