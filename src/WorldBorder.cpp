/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** WorldBorder
*/

#include "WorldBorder.hpp"

namespace rtype
{

WorldBorder::WorldBorder(WorldBorder::SIDE side, RType *scene)
	: Colisable(scene->getRessourcesManager().getTexture("border.png"),
	            scene, NEUTRAL), _side(side)
{
	switch (_side) {
	case LEFT:
		setRotation(90);
		setPositions(-1000,//-_sprite.getTexture()->getSize().x / 2,
		             scene->getWindow().getSize().y / 2);
		break;
	case TOP:
		setPositions(scene->getWindow().getSize().x / 2, -10);
		break;
	case RIGHT:
		setRotation(90);
		setPositions(scene->getWindow().getSize().x + 10,
		             scene->getWindow().getSize().y / 2);
		break;
	case BOT:
		setPositions(scene->getWindow().getSize().x / 2,
		             scene->getWindow().getSize().y + 10);
		break;
	}
}

void WorldBorder::update(std::vector<std::unique_ptr<Displayable>> &objects)
{
	Colisable::update(objects);
	for (auto &object : objects) {
		auto casted = dynamic_cast<Colisable*>(object.get());
		if (casted == nullptr || casted == this)
			continue;
		if (casted->getRace() != _race)
			if (casted->intersect(getHitbox()))
				casted->setActive(false);
	}
}

void WorldBorder::action(Character &other)
{

}

}
