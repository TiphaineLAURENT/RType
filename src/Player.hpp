/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Player
*/

#ifndef R_TYPE_PLAYER_HPP
# define R_TYPE_PLAYER_HPP

#include <ostream>
#include "Character.hpp"
#include "Hearts.hpp"

namespace rtype
{

class Player : public Character
{
public:
	explicit Player(const sf::Texture &texture, RType*, RACE = ALLY);
	~Player() final;
	/*Player(const Player &copy) = default;
	Player &operator=(const Player &other) = default;
	Player(Player &&) noexcept = default;
	Player &operator=(Player &&) = default;*/

public:
	void update(std::vector<std::unique_ptr<Displayable>> &) final;
	void draw(sf::RenderTarget &target,
	          sf::RenderStates states) const override;
	void action(Character&) final{};

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void fireNormal() final;
	void fireSpecial();
	void toggleAutoFire();

private:
	std::map<std::string, Displayable*> *_objects;
	int _fireSpecialSpeed;
	sf::Clock _attackSpecialClock;
	Hearts _hearts;
	bool _autoFire;

private:
};

std::ostream &operator<<(std::ostream &out, const Player &);

}

#endif /* !R_TYPE_PLAYER_HPP */
