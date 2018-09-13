/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Displayable
*/

#ifndef R_TYPE_DISPLAYABLE_HPP
# define R_TYPE_DISPLAYABLE_HPP

#include <ostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

namespace rtype
{

class RType;

class Displayable : public sf::Drawable, public sf::Transformable
{
public:
	explicit Displayable(const sf::Texture &texture, RType*);
	virtual ~Displayable() = default;
	/*Displayable(const Displayable &copy) = default;
	Displayable &operator=(const Displayable &other) = default;
	Displayable(Displayable &&) noexcept = default;
	Displayable &operator=(Displayable &&) = default;*/

public:
	virtual void update(std::vector<std::unique_ptr<Displayable>> &){};
	virtual void draw(sf::RenderTarget &target,
	                  sf::RenderStates states) const;
	void setSize(unsigned int width, unsigned int height);
	void setActive(bool = false);
	bool isActive() const;

	void setLeft();
	void setTop();
	void setRight();
	void setBot();
	void setCenter();

protected:
	sf::Sprite _sprite;
	bool _isActive;
	RType *_scene;

private:
};

std::ostream &operator<<(std::ostream &out, const Displayable &);

}

#endif /* !R_TYPE_DISPLAYABLE_HPP */
