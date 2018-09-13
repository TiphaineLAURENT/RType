/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Option
*/

#include "Option.hpp"

namespace rtype
{

Option::Option(const std::string &title, const sf::Font &font,
               std::function<void(RType*)>action)
	: _title(title, font), _action(std::move(action))
{
	_title.setOutlineThickness(2);
}

void Option::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform = getTransform();
	states.texture = &_title.getFont()
	                        ->getTexture(_title.getCharacterSize());

	target.draw(_title, states);
}

void Option::action(RType *scene)
{
	_action(scene);
}

void Option::setSelected(bool state)
{
	if (state)
		_title.setOutlineColor(sf::Color::Red);
	else
		_title.setOutlineColor(sf::Color::Black);
}

}
