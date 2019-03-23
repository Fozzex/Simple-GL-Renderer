#pragma once
#include <sstream>

#include "Event.h"
#include "Core/Input/Keyboard.h"

class KeyEvent : public Event
{
public:

	KeyEvent(Keyboard::KeyCode keyCode) :
		m_KeyCode(keyCode) {}

	virtual ~KeyEvent() {}

	inline Keyboard::KeyCode GetKeyCode() const { return m_KeyCode; }

protected:

	Keyboard::KeyCode m_KeyCode;

};

class KeyPressedEvent : public KeyEvent
{
public:

	KeyPressedEvent(Keyboard::KeyCode keyCode, int repeatCount) :
		KeyEvent(keyCode), m_RepeatCount(repeatCount) 
	{
		SetTypeIndex<KeyPressedEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << (int)m_KeyCode << " (" << m_RepeatCount << " repeats)";
		return ss.str();
	}

	inline int GetRepeatCount() const { return m_RepeatCount; }

private:

	int m_RepeatCount;

};

class KeyReleasedEvent : public KeyEvent
{
public:

	KeyReleasedEvent(Keyboard::KeyCode keyCode) :
		KeyEvent(keyCode) 
	{
		SetTypeIndex<KeyReleasedEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << (int)m_KeyCode;
		return ss.str();
	}

};

class KeyTypedEvent : public Event
{
public:

	KeyTypedEvent(char key) :
		m_Key(key) 
	{
		SetTypeIndex<KeyTypedEvent>();
	}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyTypedEvent: " << m_Key;
		return ss.str();
	}

	inline char GetKey() const { return m_Key; }

private:

	char m_Key;

};