#include <pch.h>
#include <core.h>

#include "timer.h"

Timer::Timer()
{
	Synchronize();
	Update();
}

void Timer::Synchronize()
{
	m_SynchronizedTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void Timer::Update()
{
	m_UpdatedTime = m_SynchronizedTime;
}

void Timer::Add(time_t ms)
{
	m_UpdatedTime += ms;
	ASSERT(m_UpdatedTime <= m_SynchronizedTime);
}

bool Timer::Passed(time_t ms)
{
	return (m_SynchronizedTime - m_UpdatedTime) >= ms;
}

bool Timer::SynchronizedPassed(time_t ms)
{
	Synchronize();
	return Passed(ms);
}

void Timer::operator+=(time_t ms)
{
	Add(ms);
}
