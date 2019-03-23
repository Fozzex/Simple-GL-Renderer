#pragma once
#include <sstream>

#include "Event.h"

class MouseButtonEvent : public Event
{
public:

	inline int GetMouseButton() const { return m_Button; }

protected:

	MouseButtonEvent(int button)
		: m_Button(button) {}

	int m_Button;

};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:

	MouseButtonPressedEvent(int button)
		: MouseButtonEvent(button) 
	{
		SetTypeIndex<MouseButtonPressedEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button;
		return ss.str();
	}

};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:

	MouseButtonReleasedEvent(int button)
		: MouseButtonEvent(button) 
	{
		SetTypeIndex<MouseButtonReleasedEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_Button;
		return ss.str();
	}

};

class MouseMovedEvent : public Event
{
public:

	MouseMovedEvent(double x, double y)
		: m_MouseX(x), m_MouseY(y) 
	{
		SetTypeIndex<MouseMovedEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	inline double GetX() const { return m_MouseX; }
	inline double GetY() const { return m_MouseY; }

private:

	double m_MouseX, m_MouseY;
};

class MouseScrolledEvent : public Event
{
public:

	MouseScrolledEvent(double xOffset, double yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset) 
	{
		SetTypeIndex<MouseScrolledEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return ss.str();
	}

	inline double GetXOffset() const { return m_XOffset; }
	inline double GetYOffset() const { return m_YOffset; }

private:

	double m_XOffset, m_YOffset;

};