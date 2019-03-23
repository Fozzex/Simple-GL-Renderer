#pragma once
#include <sstream>

#include "Event.h"

class WindowResizedEvent : public Event
{
public:

	WindowResizedEvent(unsigned int width, unsigned int height) :
		m_Width(width), m_Height(height) 
	{
		SetTypeIndex<WindowResizedEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowResizedEvent: " << m_Width << ", " << m_Height;
		return ss.str();
	}

	inline unsigned int GetWidth() const { return m_Width; }
	inline unsigned int GetHeight() const { return m_Height; }

private:

	unsigned int m_Width, m_Height;

};

class WindowClosedEvent : public Event
{
public:

	WindowClosedEvent() 
	{
		SetTypeIndex<WindowClosedEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowClosedEvent";
		return ss.str();
	}

};