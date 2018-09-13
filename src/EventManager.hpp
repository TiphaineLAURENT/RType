/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** EventManager
*/

#ifndef R_TYPE_EVENTMANAGER_HPP
# define R_TYPE_EVENTMANAGER_HPP

#include <ostream>
#include <functional>
#include <iostream>
#include "Event.hpp"

namespace rtype
{

class EventManager
{
public:
	EventManager() = default;
	//~EventManager() = default;
	EventManager(const EventManager &copy) = default;
	EventManager &operator=(const EventManager &other) = default;
	EventManager(EventManager &&) noexcept = default;
	EventManager &operator=(EventManager &&) = default;

public:
	static EventManager &getInstance();
	static void deleteInstance();
	void createEvent(const std::string &eventName);
	template <class T>
	void subscribe(const std::string &eventName, T *obj,
	               std::function<void(T*)> function)
	{
		bool subscribed = false;
		for (auto &event : _events) {
			if (event == eventName) {
				event.addListener(obj, function);
				subscribed = true;
				break;
			}
		}
		if (!subscribed) {
			createEvent(eventName);
			subscribe(eventName, obj, function);
		}
	}
	void publish(const std::string &eventName);
	void clearEvents();
	void clearListener(const std::string&);

private:
	static EventManager *_manager;
	std::vector<Event> _events;

private:
};

std::ostream &operator<<(std::ostream &out, const EventManager &);

}

#endif /* !R_TYPE_EVENTMANAGER_HPP */
