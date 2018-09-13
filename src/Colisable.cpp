/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Colisable
*/

#include "Colisable.hpp"

namespace rtype
{

Colisable::Colisable(const sf::Texture &texture, RType *scene, RACE race)
	: Displayable(texture, scene),
	  _hitboxView({_sprite.getGlobalBounds().width,
	               _sprite.getGlobalBounds().height}),
	  _showHitbox(false), _race(race)
{
	_hitboxView.setFillColor(sf::Color::Transparent);
	_hitboxView.setOutlineThickness(2);
	_hitboxView.setOutlineColor(sf::Color::Red);
	_hitboxView.setRotation(getRotation());
	_hitboxView.setOrigin(getOrigin());
}

const sf::FloatRect Colisable::getHitbox() const
{
	return _hitboxView.getGlobalBounds();
}

void Colisable::showHitbox(bool state)
{
	_showHitbox = state;
}

bool Colisable::intersect(const sf::FloatRect &other)
{
	if (!_isActive)
		return false;
	return getHitbox().intersects(other);
}

bool Colisable::intersect(const sf::Vector2f &other)
{
	return getHitbox().contains(other);
}

void Colisable::update(std::vector<std::unique_ptr<Displayable>> &objects)
{
	_hitboxView.setPosition(getPosition());
	_hitboxView.setRotation(getRotation());
}

void Colisable::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Displayable::draw(target, states);
	if (_showHitbox)
		target.draw(_hitboxView);
}

void Colisable::setPositions(float x, float y)
{
	setPosition(x, y);
	_hitboxView.setPosition(x, y);
}

void Colisable::setPositions(const sf::Vector2f &pos)
{
	setPositions(pos.x, pos.y);
}

Colisable::RACE Colisable::getRace() const
{
	return _race;
}

void Colisable::scaleHitbox(float x)
{
	_hitboxView.scale({x, x});
}

}
