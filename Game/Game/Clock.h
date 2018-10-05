#pragma once
class CClock
{
private:

	int m_iFPS;
	__int64 m_iPerformance;

	__int64 m_iPrevTime;
	__int64 m_iCurrentTime;

	double m_dSPF;
	double m_dDeltaTime;

public:
	float GetDelta();

	

public:
	CClock(int FPS);
	~CClock();
};

