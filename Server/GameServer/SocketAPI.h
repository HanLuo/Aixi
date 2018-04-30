#pragma once

#include "BaseType.h"

#if defined(__WINDOWS__)
#include <WinSock.h>
#elif defined(__LINUX__)
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#endif

#define _ESIZE 256

#if defined(__LINUX__)
typedef int SOCKET;
#define INVALID_SOCKET	-1
#define SOCKET_ERROR	-1
#endif

static const int SOCKET_ERROR_WOULDBLOCK = -100;

namespace SocketAPI
{
	// 创建socket
	SOCKET socket_ex (int domain, int type, int protocol);

	// 绑定socket
	bool bind_ex (SOCKET s, const struct sockaddr *addr, int len);

	// 连接
	bool connect_ex (SOCKET s, const struct sockaddr *addr, int len);

	// 监听
	bool listen_ex (SOCKET s, int num);

	// 接受
	SOCKET accept_ex(SOCKET s, struct sockaddr *addr, int *addrlen);

	// 设置socket 参数
	int getsockopt_ex (SOCKET s, int level, int optname, void *optval, int *optlen);

	int setsocketopt_ex (SOCKET s, int level, int optname, void *optval, int *optlen);

	// send
	int send_ex (SOCKET s, const void *buf, int len, int flags);

	// sendto
	int sendto_ex (SOCKET s, const void *buf, int len, int flags, const struct sockaddr *addr, int tolen);

	// recv
	int recv_ex (SOCKET s, void *buf, int len, int flags);

	// recvfrom
	int recvfrom_ex(SOCKET s, void *buf, int len, int flags, struct sockaddr *from, int *fromlen);

	// close
	int closesocket_ex(SOCKET s);

	bool ioctlsocket_ex(SOCKET s, long cmd, long *arg);

	bool getsocketnonblocking_ex(SOCKET s);


	bool setsocketnonblocking_ex(SOCKET s, bool on);


	int availablesocket_ex(SOCKET s);

	bool shutdown_ex(SOCKET s);

	int select_ex(int maxfd, fd_set *readset, fd_set *writeset, fd_set *exceptset, struct timeval *timeout);

}