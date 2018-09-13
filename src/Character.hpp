/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Character
*/

#ifndef R_TYPE_CHARACTER_HPP
# define R_TYPE_CHARACTER_HPP

#include <ostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "EventManager.hpp"
#include "Colisable.hpp"

namespace rtype
{

class Character : public Colisable
{
public:
	Character(const sf::Texture &texture, RType*, RACE = NEUTRAL);
	virtual ~Character() = default;
	/*Character(const Character &copy) = default;
	Character &operator=(const Character &other) = default;
	Character(Character &&) noexcept = default;
	Character &operator=(Character &&) = default;*/

public:
	virtual void update(std::vector<std::unique_ptr<Displayable>> &);
	virtual void action(Character&) = 0;

	virtual void takeDamage(int damage);
	virtual void fireNormal() = 0;

protected:
	float _speed;
	int _lifePoints;
	sf::Clock _attackClock;
	int _fireSpeed;

private:
};

std::ostream &operator<<(std::ostream &out, const Character &);

}

#endif /* !R_TYPE_CHARACTER_HPP */
