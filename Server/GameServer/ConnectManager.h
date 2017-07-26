#ifndef __CONNECT_MANAGER_H__
#define __CONNECT_MANAGER_H__

#include "Thread.h"

// 负责管理连接进入的客户端
class ConnectManager : public Thread
{
public:
	ConnectManager();
	~ConnectManager();

	// 初始化模块
	bool init();

	// 模块循环处理
	virtual void run();

	// 模块退出
	virtual void stop() { m_Active = false; }

	// 模块退出处理
	void quit();

	// 判断当时是够处于活动状态
	bool isActive() { return m_Active; }

private:
	bool m_Active;	//是否是活动的标志


};

extern ConnectManager* g_pConnectManager;

#endif