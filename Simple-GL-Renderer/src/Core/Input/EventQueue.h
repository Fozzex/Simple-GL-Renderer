#pragma once
#include <vector>

#include "Core/Input/Event.h"
#include "Core/Util/Singleton.h"

class EventQueue : public Singleton
{
public:

	static void Add(const Event& e);
	static Event Next();

	inline static bool Empty() { return s_Queue.empty(); }

private:

	static std::vector<Event> s_Queue;

};