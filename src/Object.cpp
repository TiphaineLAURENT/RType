/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Object
*/

#include "Object.hpp"

namespace rtype
{

Object::Object(const sf::Texture &texture, RType *scene, RACE race)
	: Colisable(texture, scene, race)
{}

void Object::update(std::vector<std::unique_ptr<Displayable>> &objects)
{
	Colisable::update(objects);
}

}
