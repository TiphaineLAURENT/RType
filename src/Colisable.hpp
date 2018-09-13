/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Colisable
*/

#ifndef R_TYPE_COLISABLE_HPP
# define R_TYPE_COLISABLE_HPP

#include <ostream>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "Displayable.hpp"
#include "RType.hpp"

namespace rtype
{

class Character;

class Colisable : public Displayable
{
public:
	enum RACE {ALLY, NEUTRAL, ENEMY};
	explicit Colisable(const sf::Texture&, RType*, RACE = NEUTRAL);
	virtual ~Colisable() = default;
	/*Colisable(const Colisable &copy) = default;
	Colisable &operator=(const Colisable &other) = default;
	Colisable(Colisable &&) noexcept = default;
	Colisable &operator=(Colisable &&) = default;*/

public:
	void update(std::vector<std::unique_ptr<Displayable>> &) override;
	void draw(sf::RenderTarget &target,
	                  sf::RenderStates states) const override;

	const sf::FloatRect getHitbox() const;
	void showHitbox(bool = true);
	bool intersect(const sf::FloatRect&);
	bool intersect(const sf::Vector2f&);
	virtual void action(Character&) = 0;
	RACE getRace() const;

	virtual void setPositions(float x, float y);
	virtual void setPositions(const sf::Vector2f&);
	virtual void scaleHitbox(float scale);

private:
	sf::RectangleShape _hitboxView;
	bool _showHitbox;

protected:
	RACE _race;

private:
};

std::ostream &operator<<(std::ostream &out, const Colisable &);

}

#endif /* !R_TYPE_COLISABLE_HPP */
