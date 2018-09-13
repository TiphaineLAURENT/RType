/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Projectile
*/

#include "Projectile.hpp"

namespace rtype
{

Projectile::Projectile(const sf::Texture &texture, RType *scene,
                       const sf::Vector2f &dir, RACE race, int damage)
	: Object(texture, scene, race), _speed(10), _dir(dir), _damage(damage)
{
}

void Projectile::update(std::vector<std::unique_ptr<Displayable>> &objects)
{
	Object::update(objects);
	move(_speed * _dir.x, _dir.y);
}

void Projectile::action(Character &other)
{
	other.takeDamage(_damage);
	_isActive = false;
}

}
