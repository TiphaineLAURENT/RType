/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Event
*/

#include <iostream>
#include "Event.hpp"

namespace rtype
{

Event::Event(const std::string &eventName)
	: _eventName(eventName)
{}

void Event::execute()
{
	for (auto &handler : _handlers)
		handler->execute();
}

bool Event::operator==(const std::string &str)
{
	return _eventName == str;
}

void Event::clearListener()
{
	_handlers.clear();
}

}
