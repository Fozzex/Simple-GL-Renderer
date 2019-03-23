#pragma once
#include <typeindex>
#include <functional>

class EventDispatcher
{
public:

	EventDispatcher(Event& e) :
		m_Event(e) {}

	template<class TEvent, class = std::enable_if<std::is_convertible<TEvent, Event>::value>>
	void Dispatch(const std::function<bool(TEvent&)>& callback)
	{
		if (m_Event.GetTypeIndex() == typeid(TEvent))
		{
			callback(*reinterpret_cast<TEvent*>(&m_Event));
		}
	}

	inline bool Handled() const { return m_Event.handled; }

private:

	Event& m_Event;

};