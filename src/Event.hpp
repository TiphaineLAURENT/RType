/*
** EPITECH PROJECT, 2021
** R_type
** File description:
** Event
*/

#ifndef R_TYPE_EVENT_HPP
# define R_TYPE_EVENT_HPP

#include <ostream>
#include <functional>

namespace rtype
{

class EventHandlerBase
{
public:
	virtual void execute() = 0;
};

template <class T>
class EventHandler : public EventHandlerBase
{
public:
	EventHandler(T *obj, std::function<void(T*)> function)
		: _obj(obj), _function(function)
	{}

public:
	void execute() override
	{
		_function(_obj);
	}

private:
	T *_obj;
	std::function<void(T*)> _function;

private:
};

class Event
{
public:
	Event(const std::string &eventName);
	~Event() = default;
	Event(const Event &copy) = default;
	Event &operator=(const Event &other) = default;
	Event(Event &&) noexcept = default;
	Event &operator=(Event &&) = default;

public:
	template <class T>
	void addListener(T *obj, std::function<void(T*)> function)
	{
		auto *handler = new EventHandler<T>(obj, function);
		_handlers.push_back(handler);
	}
	void clearListener();
	void execute();

	bool operator==(const std::string &str);

private:
	std::vector<EventHandlerBase*> _handlers;
	std::string _eventName;

private:
};

std::ostream &operator<<(std::ostream &out, const Event &);

}

#endif /* !R_TYPE_EVENT_HPP */
