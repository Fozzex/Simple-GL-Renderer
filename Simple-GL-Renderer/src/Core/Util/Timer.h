#pragma once
#include <chrono>

enum class Time : int
{
	Microseconds = 1,
	Milliseconds = 1000,
	Seconds = 1000000,
};

class Timer
{
public:

	Timer();

	float GetTime(Time timeType);
	void Restart();

private:

	std::chrono::steady_clock::time_point m_StartTime;

};