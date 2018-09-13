/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Option
*/

#ifndef R_TYPE_OPTION_HPP
# define R_TYPE_OPTION_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <functional>
#include "SFML/Graphics/RenderTarget.hpp"

namespace rtype
{

class RType;

class Option : public sf::Drawable, public sf::Transformable
{
public:
	Option(const std::string &title, const sf::Font&,
	       std::function<void(RType*)>);
	~Option() = default;
	/*Option(const Option &copy) = default;
	Option &operator=(const Option &other) = default;
	Option(Option &&) noexcept = default;
	Option &operator=(Option &&) = default;*/

public:
	void draw(sf::RenderTarget &target,
	          sf::RenderStates states) const final;
	void action(RType*);

	void setSelected(bool);

private:
	std::function<void(RType*)> _action;
	sf::Text _title;

private:
};

std::ostream &operator<<(std::ostream &out, const Option &);

}

#endif /* !R_TYPE_OPTION_HPP */
