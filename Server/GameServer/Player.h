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

	virtual bool heartBeat(unsigned int uTime = 0);

	virtual bool sendPacket(Packet* pPacket);

	// 加密
	virtual void encrypt_S2C(char* header, unsigned int len, unsigned int beginplace) = 0;

	// 解密
	virtual void decryptHead_C2S(char* header) = 0;

	virtual void decrypt_C2S(char* header, unsigned int len, unsigned int beginplace) = 0;

public:
	// 通用接口
	virtual bool isLoginPlayer() = 0;
	virtual bool isServerPlayer() = 0;

	// 设置玩家的player id 由PlayerPool类分配出来的索引值
	// playerid 用于表示一个客户端在整个系统中的数据位置信息
	int getPlayerID() { return m_Playerid; }

	void setPlayerID(int id) { m_Playerid = id; }


private:
	bool m_isEmpty;
	bool m_isDisconnect;

protected:
	// Player id 统一由PlayerPool管理
	int m_Playerid;

	// User id
	// 同意由UserPool管理
	int m_Userid;

	// 在PlayerManager类中player id数组的下标
	int m_playerManagerid;

	// 网络连接句柄
	Socket* m_pSocket;

	// 输入输出数据缓存
	SocketInputStream* m_pSocketInputStream;

	SocketOutputStream* m_pSocketOutputStream;
};

#endif