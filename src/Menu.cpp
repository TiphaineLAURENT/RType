/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Menu
*/

#include <SFML/Window/Keyboard.hpp>
#include "Menu.hpp"
#include "EventManager.hpp"

namespace rtype
{

# define EnumToString(enum) std::to_string(int(enum))

Menu::Menu(RType *scene)
	: _idx(0), _options(), _clock(), _scene(scene),  _isActive(false)
{
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::PageDown),
	                                      this, {&Menu::selectDown});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::PageUp),
	                                      this, {&Menu::selectUp});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::Return),
	                                      this, {&Menu::action});
	EventManager::getInstance().subscribe(EnumToString(sf::Keyboard::Right),
	                                      this, {&Menu::action});
	_clock.restart();
}

void Menu::update()
{
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (auto &option : _options)
		option.draw(target, states);
}

void Menu::addOption(Option option)
{
	option.setPosition(100, _options.size() * 100);
	if (_options.size() == 0)
		option.setSelected(true);
	_options.push_back(std::move(option));
}

void Menu::addOptions(std::vector<Option> &options)
{
	_options.insert(_options.end(), options.begin(), options.end());
}

void Menu::selectDown()
{
	if (!_isActive)
		return;
	if (_clock.getElapsedTime().asMilliseconds() < 100)
		return;
	if (!_options.size())
		return;
	_options[_idx].setSelected(false);
	_idx += 1;
	_idx %= _options.size();
	_options[_idx].setSelected(true);
	_clock.restart();
}

void Menu::selectUp()
{
	if (!_isActive)
		return;
	if (_clock.getElapsedTime().asMilliseconds() < 100)
		return;
	if (!_options.size())
		return;
	_options[_idx].setSelected(false);
	_idx -= 1;
	_idx %= _options.size();
	_options[_idx].setSelected(true);
	_clock.restart();
}

void Menu::action()
{
	if (!_isActive)
		return;
	_options[_idx].action(_scene);
}

bool Menu::isActive()
{
	return _isActive;
}

void Menu::setActive(bool state)
{
	_isActive = state;
}

}
