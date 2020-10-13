#pragma once

class Timer
{
public:
	Timer();
	
	void Synchronize();
	void Update();
	void Add(time_t ms);

	bool Passed(time_t ms);
	bool SynchronizedPassed(time_t ms);

	void operator+=(time_t ms);
private:
	time_t m_UpdatedTime;
	time_t m_SynchronizedTime;
};
