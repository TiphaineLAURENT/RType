#include <utility>

/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Enemy
*/

#include <cmath>
#include "Enemy.hpp"
#include "Projectile.hpp"

namespace rtype
{

Enemy::Enemy(const sf::Texture &texture,
             std::function<float(float, float)> movement, RType* scene,
             RACE race)
	: Character(texture, scene, race), _movement(std::move(movement))
{
	setRotation(180);
	_speed = 1;
	_lifePoints = 2;
	std::cout << "constructed enemy" << std::endl;
}

void Enemy::update(std::vector<std::unique_ptr<Displayable>> &objects)
{
	Character::update(objects);
	move(-_speed, _movement(getPosition().x, _speed));

	fireNormal();
}

void Enemy::action(Character &other)
{
	other.setActive(false);
}

void Enemy::fireNormal()
{
	if (_attackClock.getElapsedTime().asMilliseconds() < _fireSpeed)
		return;
	Projectile *projectile = new Projectile(
		_scene->getRessourcesManager().getTexture
			("little_yellow_beam.png"), _scene, {-1, 0}, ENEMY);
	projectile->setPositions(getPosition());
	_scene->getObjects().emplace_back(projectile);
	_attackClock.restart();
}

Enemy::~Enemy()
{
	std::cout << "destroyed enemy" << std::endl;
}

void Enemy::newEnemy()
{
	auto *enemy1 = new Enemy(_scene->getRessourcesManager().getTexture
		                         ("spaceship_1.png"),
	                         [](float x, float speed)
	                         {return sinf(x / (100 / speed)) * 5;}, _scene);
	enemy1->setRight();
	enemy1->move(0, random() % 1000);
	_scene->getObjects().emplace_back(enemy1);
}

void Enemy::takeDamage(int damage)
{
	Character::takeDamage(damage);
	if (!_isActive) {
		newEnemy();
		newEnemy();
	}
}

}
