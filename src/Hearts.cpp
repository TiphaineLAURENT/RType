/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Hearts
*/

#include "Hearts.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace rtype
{

Hearts::Hearts(const sf::Texture &texture)
	: _sprite(texture)
{
	scale(0.25, 0.25);
}

void Hearts::update(int life)
{
	_sprite.setTextureRect({0, 0,
	                        (int(_sprite.getTexture()->getSize().x) / 4) *
	                        life,
	                        int(_sprite.getTexture()->getSize().y)});
}

void Hearts::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform = getTransform();
	states.texture = _sprite.getTexture();

	target.draw(_sprite, states);
}

}
