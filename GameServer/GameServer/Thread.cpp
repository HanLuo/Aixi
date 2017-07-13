#include "Thread.h"
#include <mutex>

unsigned int g_thread_count = 0;

std::mutex g_thread_lock;

Thread::Thread()
{
	mTid = std::thread::id();
	mStatus = Thread::READY;
}

Thread::~Thread()
{

}

void Thread::start()
{
	if (mStatus != Thread::READY)
		return;
	std::thread t1(myThreadProcess, this);
}

void Thread::stop()
{

}

void Thread::exit(void* retval)
{
	
}

void Thread::run()
{

}

std::thread::id myThreadProcess(void* derivedThread)
{
	Thread* thread = (Thread*)derivedThread;

	if (thread == nullptr)
		return std::thread::id();

	thread->setStatus(Thread::RUNNING);

	thread->run();

	thread->setStatus(Thread::EXIT);

	thread->exit(nullptr);

	g_thread_lock.lock();
	g_thread_count++;
	g_thread_lock.unlock();
}