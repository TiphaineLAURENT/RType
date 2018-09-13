/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** RType
*/

#ifndef R_TYPE_RTYPE_HPP
# define R_TYPE_RTYPE_HPP

#include <ostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "RessourcesManager.hpp"
#include "EventManager.hpp"
#include "Displayable.hpp"
#include "Menu.hpp"

namespace rtype
{

# define EnumToString(enum) std::to_string(int(enum))

class RType
{
public:
	explicit RType();
	RType(unsigned int width, unsigned int height, unsigned int bpp = 32);
	~RType();
//	RType(const RType &copy) = default;
//	RType &operator=(const RType &other) = default;
//	RType(RType &&) noexcept = default;
//	RType &operator=(RType &&) = default;

public:
	enum STATUS { LOADING, ENDED, PLAYING, MENU, START, PAUSE };
	void run();

	int getStatus() const noexcept;
	int getError() const noexcept;
	std::vector<std::unique_ptr<Displayable>> &getObjects();
//	void addObject(Displayable*);
	RessourcesManager &getRessourcesManager();
	sf::RenderWindow &getWindow();

	void setStatus(STATUS);

private:
	sf::RenderWindow _window;
	int _status;
	int _error;
	sf::Sprite _background;

	RessourcesManager _rmanager;
	std::vector<std::unique_ptr<Displayable>> _objects;
	Menu _menu;

private:
	void manageEvents();
	void update();
	void display();

	void start();
	void pause();
};

std::ostream &operator<<(std::ostream &out, const RType &);

}

#endif /* !R_TYPE_RTYPE_HPP */
