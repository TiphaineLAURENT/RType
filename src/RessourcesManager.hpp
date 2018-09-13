/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** RessourcesManager
*/

#ifndef R_TYPE_RESSOURCEMANAGER_HPP
# define R_TYPE_RESSOURCEMANAGER_HPP

#include <ostream>
#include <map>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Music.hpp>

namespace rtype
{

class RessourcesManager
{
public:
	RessourcesManager() = default;
	~RessourcesManager();
	RessourcesManager(const RessourcesManager &copy) = default;
	RessourcesManager &operator=(const RessourcesManager &other) = default;
	RessourcesManager(RessourcesManager &&) noexcept = default;
	RessourcesManager &operator=(RessourcesManager &&) = default;

public:
	const sf::Texture &getTexture(const std::string &textureName);
	const sf::Font &getFont(const std::string &fontName);
	sf::Music *getMusic(const std::string &musicName);

private:
	std::map<std::string, sf::Texture*> _textures;
	std::map<std::string, sf::Font*> _fonts;
	std::map<std::string, sf::Music*> _musics;

private:
};

std::ostream &operator<<(std::ostream &out, const RessourcesManager &);

}

#endif /* !R_TYPE_RESSOURCEMANAGER_HPP */
