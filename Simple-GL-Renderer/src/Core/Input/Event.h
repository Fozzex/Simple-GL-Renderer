#pragma once
#include <typeindex>
#include <string>

class Event
{
	std::type_index m_TypeIndex = typeid(Event);
public:

	Event() = default;
	virtual ~Event() = default;

	virtual std::string ToString() const = 0;

	inline std::type_index GetTypeIndex() const { return m_TypeIndex; }
	
	template<class TEvent>
	inline void SetTypeIndex() { m_TypeIndex = typeid(TEvent); }

public:

	bool handled = false;

};