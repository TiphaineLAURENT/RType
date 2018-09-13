/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** EventManager
*/

#include "EventManager.hpp"

namespace rtype
{

EventManager *EventManager::_manager;

EventManager &EventManager::getInstance()
{
	if (!_manager)
		_manager = new EventManager();
	return *_manager;
}

void EventManager::createEvent(const std::string &eventName)
{
	for (auto &event : _events)
		if (event == eventName)
			return;
	_events.emplace_back(eventName);
}

void EventManager::publish(const std::string &eventName)
{
	for (auto &event : _events) {
		if (event == eventName) {
			event.execute();
			break;
		}
	}
}

void EventManager::deleteInstance()
{
	delete _manager;
}

void EventManager::clearEvents()
{
	_events.clear();
}

void EventManager::clearListener(const std::string &eventName)
{
	for (auto &event : _events) {
		if (event == eventName) {
			event.clearListener();
			break;
		}
	}
}

}
