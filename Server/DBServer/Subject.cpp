#include "Subject.h"
#include "Observer.h"

Subject::Subject()
{

}

Subject::~Subject()
{

}

// 通知 当自身状态发生改变时，通知所有观察者进行更新
void Subject::Notify()
{
	for (ObserverList::iterator iter = m_kObserverList.begin(); iter != m_kObserverList.end(); ++iter)
	{
		Observer* pObserver = *iter;
		pObserver->Update(this);
	}
}

// 添加观察者
void Subject::AttachObserver(Observer* pObserver)
{
	for (ObserverList::iterator iter = m_kObserverList.begin(); iter != m_kObserverList.end(); ++iter)
	{
		Observer* pObsv = *iter;
		if (pObsv == pObserver)
		{
			return;
		}
	}
	m_kObserverList.push_back(pObserver);
}

// 移除观察者
void Subject::DetachObserver(Observer* pObserver)
{
	m_kObserverList.remove(pObserver);
}

