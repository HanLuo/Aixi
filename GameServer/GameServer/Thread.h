#ifndef __THREAD_H__
#define __THREAD_H__

#include <thread>

class Thread
{

public:
	enum ThreadStatus
	{
		READY,		// ��ǰ�̴߳���׼��״̬
		RUNNING,	// ��������״̬
		EXITING,	// �߳������˳�
		EXIT		// �Ѿ��˳�
	};

public:

	Thread();

	virtual ~Thread();

public:
	void start();

	virtual void stop();

	void exit(void *retval = nullptr);

	virtual void run();

public:
	std::thread::id getTid() { return mTid; }

	ThreadStatus getStatus() { return mStatus; }

	void setStatus(ThreadStatus status) { mStatus = status; }

private:
	std::thread::id mTid;

	ThreadStatus mStatus;
};

std::thread::id myThreadProcess(void* derivedThread);

#endif