#/*!
 * \class Player
 *
 * \brief ָ�Ѿ�ͨ���������ӽ���������˳���Ŀͻ�
 *
 * \author shenwei
 * \date ���� 2017
 */

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Type.h"
#include "Socket.h"
#include "SocketInputStream.h"
#include "SocketOutputStream.h"
#include "Packet.h"

#define MAX_CACHE_SIZE 1024

// һ��ʱ��ͻ���û����Ϣ���Ͽ�����
#define MAX_KICK_TIME 300000

// �Ŷ���Ϣ����ʱ��
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

	// ����
	virtual void encrypt_S2C(char* header, unsigned int len, unsigned int beginplace) = 0;

	// ����
	virtual void decryptHead_C2S(char* header) = 0;

	virtual void decrypt_C2S(char* header, unsigned int len, unsigned int beginplace) = 0;

public:
	// ͨ�ýӿ�
	virtual bool isLoginPlayer() = 0;
	virtual bool isServerPlayer() = 0;

	// ������ҵ�player id ��PlayerPool��������������ֵ
	// playerid ���ڱ�ʾһ���ͻ���������ϵͳ�е�����λ����Ϣ
	int getPlayerID() { return m_Playerid; }

	void setPlayerID(int id) { m_Playerid = id; }


private:
	bool m_isEmpty;
	bool m_isDisconnect;

protected:
	// Player id ͳһ��PlayerPool����
	int m_Playerid;

	// User id
	// ͬ����UserPool����
	int m_Userid;

	// ��PlayerManager����player id������±�
	int m_playerManagerid;

	// �������Ӿ��
	Socket* m_pSocket;

	// ����������ݻ���
	SocketInputStream* m_pSocketInputStream;

	SocketOutputStream* m_pSocketOutputStream;
};

#endif