#include "Subject.h"
#include "Observer.h"

Subject::Subject()
{

}

Subject::~Subject()
{

}

// ֪ͨ ������״̬�����ı�ʱ��֪ͨ���й۲��߽��и���
void Subject::Notify()
{
	for (ObserverList::iterator iter = m_kObserverList.begin(); iter != m_kObserverList.end(); ++iter)
	{
		Observer* pObserver = *iter;
		pObserver->Update(this);
	}
}

// ��ӹ۲���
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

// �Ƴ��۲���
void Subject::DetachObserver(Observer* pObserver)
{
	m_kObserverList.remove(pObserver);
}

