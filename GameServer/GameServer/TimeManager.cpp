#include <string>
#include "TimeManager.h"

TimeManager* g_pTimeManager = nullptr;

TimeManager::TimeManager()
{
	m_crrentTime = 0;
}

TimeManager::~TimeManager()
{

}

void TimeManager::init()
{
	time_t nowtime;
	time(&nowtime);
	m_startTime = unsigned int(nowtime);
	m_crrentTime = unsigned int(nowtime);
	setTime();
}

unsigned int TimeManager::currentTime()
{
	time_t nowtime;
	time(&nowtime);
	return unsigned int(nowtime);
}

void TimeManager::setTime()
{
	time(&m_setTime);
	tm* ptm = localtime(&m_setTime);
	m_TM = *ptm;
}

time_t TimeManager::getANSITime()
{
	time_t tm1;
	return tm1;
}

int TimeManager::time2Uint()
{
	return 0;
}

unsigned int TimeManager::currentDate()
{
	setTime();
	unsigned int date;
	convertTU(&m_TM, date);
	return date;
}

void TimeManager::convertTU(tm *TM, unsigned int &date)
{
	date = 0;
	date += (TM->tm_yday % 10) & 0xf;
	date = (date << 4);
	date += TM->tm_mon & 0xf;
	date = (date << 4);
	date += TM->tm_mday & 0x1f;
	date = (date << 5);
	date += TM->tm_hour & 0x1f;
	date = (date << 5);
	date += TM->tm_min & 0x3f;
	date = (date << 6);
	date += TM->tm_sec & 0x3f;
}
