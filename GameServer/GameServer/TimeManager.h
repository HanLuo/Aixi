#ifndef __TIMEMANAGER_H__
#define __TIMEMANAGER_H__

#include <ctime>

class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	void init();

	// 当时时间计数值，起始值根据系统不同有所区别
	// 返回的值为：微妙单位的时间值
	unsigned int currentTime();

	// 直接返回，不调用系统接口
	inline unsigned int currentSaveTime() { return m_crrentTime; }

	// 取得服务器端程序启动时的时间计数值
	inline unsigned int startTime() { return m_startTime; }

	// 将当前的系统时间格式化到事件管理器里
	void setTime();

	// 得到标准时间
	time_t getANSITime();

public:
	// 不调用系统调用，只针对时间管理器内的数据
	
	//取得设置时间时候的“年、月、日、小时、分、秒、星期的值”
	inline int getYear()	{ return m_TM.tm_year + 1900; }	// [1900, ~]
	inline int getMonth()	{ return m_TM.tm_mon + 1; }		// [1, 12]
	inline int getDay()	{ return m_TM.tm_mday; }		// [1, 31]
	inline int getHour()	{ return m_TM.tm_hour; }		// [0, 23]
	inline int getMinute()	{ return m_TM.tm_min; }		// [0, 59]
	inline int getSecond()	{ return m_TM.tm_sec; }			// [0, 59]

	// 取得当天是星期几: 1-7 星期一到星期天
	inline int getWeek() { return m_TM.tm_wday + 1; }

	// 将当前时间转换为时间戳
	int time2Uint();

	// 取得当前的日期[4bit 0-9][4bit 0-11][5bit 0-30][5bit 0-23][6bit 0-59][6bit 0-59]
	unsigned int currentDate();

	// 取得服务器启动后的运行时间
	inline unsigned int runTime()
	{
		currentTime();
		return (m_crrentTime - m_startTime);
	}

	inline unsigned int runTick()
	{
		currentTime();
		return (m_crrentTime - m_startTime);
	}

	// 取得两个日期时间的时间差(单位：毫秒)
	unsigned int diffTime(unsigned int date1, unsigned int date2);

	// 将一个 unsigned int 的日期转换为一个tm结构
	void convertUT(unsigned int date, tm* TM);

	//将一个tm结构转换成一个UINT的日期
	void convertTU(tm* TM, unsigned int &date);

	//取得已天为单位的时间值, 千位数代表年份，其他三位代表时间（天数）
	unsigned int getDayTime();

	//得到当前是今天的什么时间2310表示23点10分
	unsigned int getTodayTime();

	bool formatTodayTime(unsigned int &ntime);

private:
	unsigned int m_startTime;
	unsigned int m_crrentTime;
	time_t	m_setTime;
	tm		m_TM;

};

extern  TimeManager* g_pTimeManager;
#endif