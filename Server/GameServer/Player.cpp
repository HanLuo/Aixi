#include "Player.h"

Player::Player(bool bIsServer)
{
	m_Playerid = -1;
	m_Userid = -1;
	m_playerManagerid = -1;
	m_pSocket = new Socket();

}