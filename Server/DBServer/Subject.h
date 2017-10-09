/*!
 * \file Subject.h
 * \date 2017/10/09 22:25
 *
 * \author shenwei
 * Contact: user@company.com
 *
 * \brief 观察者模式中被观察的对象
 *
 * TODO: long description
 *
 * \note
*/

#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <list>

class Observer;

class Subject
{
public:
	Subject();
	virtual ~Subject();

public:
	virtual void Notify();

	void AttachObserver(Observer* pObserver);
	void DetachObserver(Observer* pObserver);

private:
	typedef std::list<Observer*> ObserverList;
	ObserverList m_kObserverList;

};

#endif