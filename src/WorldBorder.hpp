/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** WorldBorder
*/

#ifndef R_TYPE_WORLDBORDER_HPP
# define R_TYPE_WORLDBORDER_HPP

#include "Colisable.hpp"

namespace rtype
{

class WorldBorder : public Colisable
{
public:
	enum SIDE {LEFT, TOP, RIGHT, BOT};

	explicit WorldBorder(SIDE, RType*);
	~WorldBorder() final = default;
	/*WorldBorder(const WorldBorder &copy) = default;
	WorldBorder &operator=(const WorldBorder &other) = default;
	WorldBorder(WorldBorder &&) noexcept = default;
	WorldBorder &operator=(WorldBorder &&) = default;*/

public:
	void update(std::vector<std::unique_ptr<Displayable>> &) final;
	void action(Character&) final;

private:
	SIDE _side;

private:
};

std::ostream &operator<<(std::ostream &out, const WorldBorder &);

}

#endif /* !R_TYPE_WORLDBORDER_HPP */
