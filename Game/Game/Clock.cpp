
#include "Clock.h"
#include <windows.h>
#include <stdio.h>

float CClock::UpdateGame()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_iCurrentTime);
	__int64 DeltaCount = m_iCurrentTime - m_iPrevTime;

	if (m_dSPF <= (double)DeltaCount / (double)m_iPerformance)
	{
		m_dDeltaTime += (double)DeltaCount / (double)m_iPerformance;

		double DeltaTime=m_dDeltaTime;

		m_dDeltaTime = 0;
		m_iPrevTime = m_iCurrentTime;


		int fps = (int)1.f / DeltaTime;
		printf("%d\n", fps);


		return DeltaTime;
	}
	else
		return false;

}



CClock::CClock(int FPS)
{
	m_iFPS = FPS;
	m_dSPF = 1 / FPS;
	QueryPerformanceCounter((LARGE_INTEGER*)&m_iPrevTime);
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_iPerformance);
	m_dDeltaTime = 0;
}


CClock::~CClock()
{
}
