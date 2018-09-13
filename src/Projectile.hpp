/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Projectile
*/

#ifndef R_TYPE_PROJECTILE_HPP
# define R_TYPE_PROJECTILE_HPP

#include "Object.hpp"

namespace rtype
{

class Projectile : public Object
{
public:
	Projectile(const sf::Texture&, RType*, const sf::Vector2f& = {1, 0},
	           RACE = NEUTRAL, int damage = 1);
	virtual ~Projectile() = default;
	/*Projectile(const Projectile &copy) = default;
	Projectile &operator=(const Projectile &other) = default;
	Projectile(Projectile &&) noexcept = default;
	Projectile &operator=(Projectile &&) = default;*/

public:
	void update(std::vector<std::unique_ptr<Displayable>> &) override;
	void action(Character&) override;

private:
	float _speed;
	sf::Vector2f _dir;
	int _damage;

private:
};

std::ostream &operator<<(std::ostream &out, const Projectile &);

}

#endif /* !R_TYPE_PROJECTILE_HPP */
