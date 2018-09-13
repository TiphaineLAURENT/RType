/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Hearts
*/

#ifndef R_TYPE_HEARTS_HPP
# define R_TYPE_HEARTS_HPP

#include <ostream>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace rtype
{

class Hearts : public sf::Drawable, sf::Transformable
{
public:
	Hearts(const sf::Texture&);
	~Hearts() = default;
//	Hearts(const Hearts &copy) = default;
//	Hearts &operator=(const Hearts &other) = default;
//	Hearts(Hearts &&) noexcept = default;
//	Hearts &operator=(Hearts &&) = default;

public:
	void update(int life);
	void draw(sf::RenderTarget &target,
	          sf::RenderStates states) const override;

private:
	sf::Sprite _sprite;

private:
};

std::ostream &operator<<(std::ostream &out, const Hearts &);

}

#endif /* !R_TYPE_HEARTS_HPP */
