#/*!
 * \class Player
 *
 * \brief 指已经通过网络连接进入服务器端程序的客户
 *
 * \author shenwei
 * \date 七月 2017
 */

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Type.h"
#include "Socket.h"
#include "SocketInputStream.h"
#include "SocketOutputStream.h"
#include "Packet.h"

#define MAX_CACHE_SIZE 1024

// 一定时间客户端没有消息，断开连接
#define MAX_KICK_TIME 300000

// 排队消息发送时间
#define MAX_TRUN_MESSAGE_TIME	5000

enum PacketFlag
{
	PF_NONE   = 0,
	PF_REMOVE = 1,
};

struct AsyncPacket
{
	Packet* m_pPacket;
	int		m_PlayerID;
	unsigned int m_Flag;

	AsyncPacket()
	{
		m_pPacket = nullptr;
		m_PlayerID = -1;
		m_Flag = PF_NONE;
	};

	~AsyncPacket()
	{
		safe_delete(m_pPacket);
		m_PlayerID = -1;
		m_Flag = PF_NONE;
	}
};


class Player
{
public:
	Player(bool bIsServer = false);
	~Player();

	virtual bool processInput();
	virtual bool ProcessOutput();

	virtual bool processCommand(bool option = true);
};

#endif