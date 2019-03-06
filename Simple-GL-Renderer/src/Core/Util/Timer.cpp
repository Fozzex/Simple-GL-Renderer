#include "Core/Util/Timer.h"

Timer::Timer()
{
	m_StartTime = std::chrono::steady_clock::now();
}

float Timer::GetTime(Time timeType)
{
	std::chrono::steady_clock::time_point time;
	time = std::chrono::steady_clock::now();

	return std::chrono::duration_cast<std::chrono::microseconds>(time - m_StartTime).count() / static_cast<float>(timeType);
}

void Timer::Restart()
{
	m_StartTime = std::chrono::steady_clock::now();
}