/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include "src/RType.hpp"

int main()
{
	rtype::RType game;

	game.run();
	return game.getError();
}
