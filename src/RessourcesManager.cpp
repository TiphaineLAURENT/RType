/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** RessourcesManager
*/

#include "RessourcesManager.hpp"

namespace rtype
{

const sf::Texture &RessourcesManager::getTexture(const std::string &textureName)
{
	if (_textures.count(textureName) == 0) {
		auto *texture = new sf::Texture;
		texture->loadFromFile("ressources/textures/"+ textureName);
		_textures[textureName] = texture;
	}

	return *_textures[textureName];
}

const sf::Font &RessourcesManager::getFont(const std::string &fontName)
{
	if (_fonts.count(fontName) == 0) {
		auto *font = new sf::Font;
		font->loadFromFile("ressources/fonts/"+ fontName);
		_fonts[fontName] = font;
	}
	return *_fonts[fontName];
}

sf::Music *RessourcesManager::getMusic(const std::string &musicName)
{
	if (_musics.count(musicName) == 0) {
		auto *music = new sf::Music;
		music->openFromFile("ressources/musics/"+ musicName);
		_musics[musicName] = music;
	}
	return _musics[musicName];
}

RessourcesManager::~RessourcesManager()
{
	for (auto &texture : _textures)
		delete texture.second;
	for (auto &font : _fonts)
		delete font.second;
	for (auto &music : _musics)
		delete music.second;
}

}
