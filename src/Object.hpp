/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Object
*/

#ifndef R_TYPE_OBJECT_HPP
# define R_TYPE_OBJECT_HPP

#include <ostream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Colisable.hpp"
#include "Character.hpp"

namespace rtype
{

class Object : public Colisable
{
public:
	explicit Object(const sf::Texture&, RType*, RACE = NEUTRAL);
	~Object() = default;
	/*Object(const Object &copy) = default;
	Object &operator=(const Object &other) = default;
	Object(Object &&) noexcept = default;
	Object &operator=(Object &&) = default;*/

public:
	virtual void update(std::vector<std::unique_ptr<Displayable>> &);
	virtual void action(Character&) = 0;

private:
private:
};

std::ostream &operator<<(std::ostream &out, const Object &);

}

#endif /* !R_TYPE_OBJECT_HPP */
