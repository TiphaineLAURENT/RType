/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Menu
*/

#ifndef R_TYPE_MENU_HPP
# define R_TYPE_MENU_HPP

#include <SFML/System/Clock.hpp>
#include "Option.hpp"

namespace rtype
{

class Menu : public sf::Drawable
{
public:
	Menu(RType*);
	~Menu() = default;
	/*Menu(const Menu &copy) = default;
	Menu &operator=(const Menu &other) = default;
	Menu(Menu &&) noexcept = default;
	Menu &operator=(Menu &&) = default;*/

public:
	virtual void update();
	void draw(sf::RenderTarget &target,
	          sf::RenderStates states) const final;

	void addOption(Option);
	void addOptions(std::vector<Option>&);

	void selectDown();
	void selectUp();
	void action();

	bool isActive();
	void setActive(bool);

private:
	std::vector<Option> _options;
	int _idx;
	sf::Clock _clock;
	RType *_scene;
	bool _isActive;

private:
};

std::ostream &operator<<(std::ostream &out, const Menu &);

}

#endif /* !R_TYPE_MENU_HPP */
