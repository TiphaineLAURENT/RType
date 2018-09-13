/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Player
*/

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "Player.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"

namespace rtype
{

Player::Player(const sf::Texture &texture, RType *scene, RACE race)
	: Character(texture, scene, race), _fireSpecialSpeed(5),
	  _attackSpecialClock(),
	  _hearts(scene->getRessourcesManager().getTexture("hearts.png")),
	  _autoFire(false)
{
	showHitbox(true);
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::Up),
	                                      this, {&Player::moveUp});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::Down),
	                                      this, {&Player::moveDown});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::Left),
	                                      this, {&Player::moveLeft});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::Right),
	                                      this, {&Player::moveRight});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::Space),
	                                      this, {&Player::fireNormal});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::V),
	                                      this, {&Player::fireSpecial});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::T),
	                                      this, {&Player::toggleAutoFire});
	_attackSpecialClock.restart();
	scaleHitbox(0.2);
	_fireSpeed = 250;
}

void Player::update(std::vector<std::unique_ptr<Displayable>> &objects)
{
	Character::update(objects);
	_hearts.update(_lifePoints);
	if (_autoFire) {
		fireNormal();
		fireSpecial();
	}
}

void Player::moveUp()
{
	move(0, -_speed);
}

void Player::moveDown()
{
	move(0, _speed);
}

void Player::moveLeft()
{
	move(-_speed, 0);
}

void Player::moveRight()
{
	move(_speed, 0);
}

void Player::fireNormal()
{
	if (_attackClock.getElapsedTime().asMilliseconds() < _fireSpeed)
		return;
	Projectile *projectile = new Projectile(
		_scene->getRessourcesManager().getTexture
			("yellow_beam.png"), _scene, {1, 0}, ALLY);
	projectile->setPositions(getPosition());
	_scene->getObjects().emplace_back(projectile);
	_attackClock.restart();
}

void Player::fireSpecial()
{
	if (_attackSpecialClock.getElapsedTime().asSeconds() < _fireSpecialSpeed)
		return;
	Projectile *projectile = new Projectile(
		_scene->getRessourcesManager().getTexture
			("blue_beam.png"), _scene, {1, 0}, ALLY, 3);
	projectile->setPositions(getPosition());
	_scene->getObjects().emplace_back(projectile);
	_attackSpecialClock.restart();
}

Player::~Player()
{
	for (size_t i = 0; i < _scene->getObjects().size(); ++i) {
		auto casted = dynamic_cast<Object*>(_scene->getObjects()
		[i].get());
		if (casted == nullptr)
			auto casted = dynamic_cast<Enemy*>(_scene->getObjects()
			[i].get());
		if (casted == nullptr)
			continue;
		_scene->getObjects().erase(_scene->getObjects().begin() + i);
	}
	_scene->setStatus(RType::MENU);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(_hearts);
	Colisable::draw(target, states);
}

void Player::toggleAutoFire()
{
	static sf::Clock clock;
	if (clock.getElapsedTime().asMilliseconds() > 250)
		_autoFire = !_autoFire;
}

}
