/*!
 * \file Observer.h
 * \date 2017/10/09 22:26
 *
 * \author shenwei
 * Contact: user@company.com
 *
 * \brief 观察者模式中的观察者
 *
 * TODO: long description
 *
 * \note
*/

#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "Subject.h"

class Observer
{
public:
	virtual ~Observer();
	virtual void Update(Subject* pSubject) = 0;

protected:
	Observer();
};

#endif