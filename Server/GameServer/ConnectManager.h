#ifndef __CONNECT_MANAGER_H__
#define __CONNECT_MANAGER_H__

#include "Thread.h"

// ����������ӽ���Ŀͻ���
class ConnectManager : public Thread
{
public:
	ConnectManager();
	~ConnectManager();

	// ��ʼ��ģ��
	bool init();

	// ģ��ѭ������
	virtual void run();

	// ģ���˳�
	virtual void stop() { m_Active = false; }

	// ģ���˳�����
	void quit();

	// �жϵ�ʱ�ǹ����ڻ״̬
	bool isActive() { return m_Active; }

private:
	bool m_Active;	//�Ƿ��ǻ�ı�־


};

extern ConnectManager* g_pConnectManager;

#endif