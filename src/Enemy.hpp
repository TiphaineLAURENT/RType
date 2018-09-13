/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Enemy
*/

#ifndef R_TYPE_ENEMY_HPP
# define R_TYPE_ENEMY_HPP

#include "Character.hpp"

namespace rtype
{

class Enemy : public Character
{
public:
	Enemy(const sf::Texture &texture,
	      std::function<float(float, float)>, RType*, RACE = ENEMY);
	virtual ~Enemy();
	/*Enemy(const Enemy &copy) = default;
	Enemy &operator=(const Enemy &other) = default;
	Enemy(Enemy &&) noexcept = default;
	Enemy &operator=(Enemy &&) = default;*/

public:
	void update(std::vector<std::unique_ptr<Displayable>> &) final;
	void action(Character&) final;

	void takeDamage(int damage) final;
	void fireNormal() final;

private:
	std::function<float(float, float)> _movement;

private:
	void newEnemy();
};

std::ostream &operator<<(std::ostream &out, const Enemy &);

}

#endif /* !R_TYPE_ENEMY_HPP */
