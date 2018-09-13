/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** RType
*/

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include <cmath>
#include "RType.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"
#include "WorldBorder.hpp"

namespace rtype
{

# define IntToKey(i) static_cast<sf::Keyboard::Key>(i)

RType::RType()
	: _window(sf::VideoMode::getDesktopMode(), "R-Type"), _status(LOADING),
	  _error(0), _menu(this)
{
	_window.setFramerateLimit(60);
	for (int key = sf::Keyboard::A; key != sf::Keyboard::KeyCount; key++)
		EventManager::getInstance().createEvent(EnumToString(key));

	auto background = std::make_unique<Displayable>
		(_rmanager.getTexture("background.png"), this);
	background->setSize(_window.getSize().x, _window.getSize().y);
	background->setCenter();
	_objects.push_back(std::move(background));

	_objects.emplace_back(new WorldBorder(WorldBorder::LEFT, this));
//	_objects.emplace_back(new WorldBorder(WorldBorder::TOP, this));
	_objects.emplace_back(new WorldBorder(WorldBorder::RIGHT, this));
//	_objects.emplace_back(new WorldBorder(WorldBorder::BOT, this));

	_menu.addOption({"Play", _rmanager.getFont("kurale-regular.otf"),
	                 [](RType *scene){scene->setStatus(RType::START);}});
	_menu.addOption({"Quit", _rmanager.getFont("kurale-regular.otf"),
	                 [](RType *scene){scene->setStatus(RType::ENDED);}});

	sf::Music *music = _rmanager.getMusic("8 Bit  Desmeon - Back from the"
	                                      " Dead  NCS.ogg");
	music->setVolume(0);
	music->play();
	music->setLoop(true);
}

RType::RType(unsigned int width, unsigned int height, unsigned int bpp)
	: _window(sf::VideoMode(width, height), "R-Type"), _status(MENU),
	_error(0), _menu(this)
{
}

void RType::run()
{
	setStatus(MENU);
	while (_window.isOpen() && _status != ENDED) {
		manageEvents();
		update();
		display();
	}
	_objects.clear();
	_window.close();
}

int RType::getStatus() const noexcept
{
	return _status;
}

int RType::getError() const noexcept
{
	return _error;
}

RType::~RType()
{
	EventManager::deleteInstance();
}

void RType::manageEvents()
{
	sf::Event event;
	while (_window.pollEvent(event)) {
		if  (event.type == sf::Event::Closed
		     || event.key.code == sf::Keyboard::Escape)
			setStatus(ENDED);
		else if (event.key.code == sf::Keyboard::F11)
			_window.create(sf::VideoMode::getFullscreenModes()[1],
			               "R-Type");
		else if (event.key.code == sf::Keyboard::P)
			pause();
	}

	for (int key = sf::Keyboard::A; key != sf::Keyboard::KeyCount; key++)
		if (sf::Keyboard::isKeyPressed(IntToKey(key)))
			EventManager::getInstance().publish(EnumToString(key));
}

void RType::update()
{
	if (!_window.hasFocus()) {
		_window.setFramerateLimit(1);
		return;
	} else
		_window.setFramerateLimit(60);

	switch (_status) {
	case MENU:
		_menu.update();
		break;
	case START:
		start();
		break;
	case PAUSE:
		break;
	case PLAYING:
		for (unsigned long i = 0; i < _objects.size(); ++i) {
			if (_objects[i]->isActive()) {
				_objects[i]->update(_objects);
			} else {
				_objects.erase(_objects.begin() + i);
			}
		}
		break;
	default:
		break;
	}
}

void RType::display()
{
	_window.clear();

	switch (_status) {
	case MENU:
		_window.draw(_menu);
		break;
	case START:
		break;
	case PLAYING: case PAUSE:
		for (auto &object : _objects) {
			if (object->isActive())
				_window.draw(*object);
		} break;
	default:
		break;
	}
	_window.display();
}

std::vector<std::unique_ptr<Displayable>> &RType::getObjects()
{
	return _objects;
}

RessourcesManager &RType::getRessourcesManager()
{
	return _rmanager;
}

sf::RenderWindow &RType::getWindow()
{
	return _window;
}

void RType::setStatus(RType::STATUS status)
{
	_status = status;
	_menu.setActive(status == MENU);
}

void RType::start()
{
	EventManager::getInstance().clearListener(EnumToString
	                                          (sf::Keyboard::Left));
	EventManager::getInstance().clearListener(EnumToString
	                                          (sf::Keyboard::Right));
	EventManager::getInstance().clearListener(EnumToString
	                                          (sf::Keyboard::Up));
	EventManager::getInstance().clearListener(EnumToString
	                                          (sf::Keyboard::Down));

	for (unsigned long i = 0; i < _objects.size(); ++i) {
		if (!_objects[i]->isActive())
			_objects.erase(_objects.begin() + i);
	}
	auto *player = new Player
		(_rmanager.getTexture("spaceship_1.png"), this);
	player->setLeft();
	_objects.emplace_back(player);

	auto *enemy = new Enemy(_rmanager.getTexture("spaceship_1.png"),
	                        [](float x, float speed)
	                        {return sinf(x / (100 / speed)) * 5;}, this);
	enemy->setRight();
	_objects.emplace_back(enemy);

	setStatus(PLAYING);
}

void RType::pause()
{
	static sf::Clock clock;
	if (clock.getElapsedTime().asMilliseconds() < 250)
		return ;
	setStatus(_status == PAUSE ? PLAYING : PAUSE);
	clock.restart();
}

}
