#ifndef __TIMEMANAGER_H__
#define __TIMEMANAGER_H__

#include <ctime>

class TimeManager
{
public:
	TimeManager();
	~TimeManager();

	void init();

	// ��ʱʱ�����ֵ����ʼֵ����ϵͳ��ͬ��������
	// ���ص�ֵΪ��΢�λ��ʱ��ֵ
	unsigned int currentTime();

	// ֱ�ӷ��أ�������ϵͳ�ӿ�
	inline unsigned int currentSaveTime() { return m_crrentTime; }

	// ȡ�÷������˳�������ʱ��ʱ�����ֵ
	inline unsigned int startTime() { return m_startTime; }

	// ����ǰ��ϵͳʱ���ʽ�����¼���������
	void setTime();

	// �õ���׼ʱ��
	time_t getANSITime();

public:
	// ������ϵͳ���ã�ֻ���ʱ��������ڵ�����
	
	//ȡ������ʱ��ʱ��ġ��ꡢ�¡��ա�Сʱ���֡��롢���ڵ�ֵ��
	inline int getYear()	{ return m_TM.tm_year + 1900; }	// [1900, ~]
	inline int getMonth()	{ return m_TM.tm_mon + 1; }		// [1, 12]
	inline int getDay()	{ return m_TM.tm_mday; }		// [1, 31]
	inline int getHour()	{ return m_TM.tm_hour; }		// [0, 23]
	inline int getMinute()	{ return m_TM.tm_min; }		// [0, 59]
	inline int getSecond()	{ return m_TM.tm_sec; }			// [0, 59]

	// ȡ�õ��������ڼ�: 1-7 ����һ��������
	inline int getWeek() { return m_TM.tm_wday + 1; }

	// ����ǰʱ��ת��Ϊʱ���
	int time2Uint();

	// ȡ�õ�ǰ������[4bit 0-9][4bit 0-11][5bit 0-30][5bit 0-23][6bit 0-59][6bit 0-59]
	unsigned int currentDate();

	// ȡ�÷����������������ʱ��
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

	// ȡ����������ʱ���ʱ���(��λ������)
	unsigned int diffTime(unsigned int date1, unsigned int date2);

	// ��һ�� unsigned int ������ת��Ϊһ��tm�ṹ
	void convertUT(unsigned int date, tm* TM);

	//��һ��tm�ṹת����һ��UINT������
	void convertTU(tm* TM, unsigned int &date);

	//ȡ������Ϊ��λ��ʱ��ֵ, ǧλ��������ݣ�������λ����ʱ�䣨������
	unsigned int getDayTime();

	//�õ���ǰ�ǽ����ʲôʱ��2310��ʾ23��10��
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