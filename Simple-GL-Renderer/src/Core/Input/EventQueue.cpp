#include "EventQueue.h"

std::vector<Event> EventQueue::s_Queue;

void EventQueue::Add(const Event& e)
{
	s_Queue.push_back(e);
}

Event EventQueue::Next()
{
	Event e = *s_Queue.begin();
	s_Queue.erase(s_Queue.begin());
	return e;
}