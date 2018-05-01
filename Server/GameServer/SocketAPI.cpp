#include "SocketAPI.h"


SOCKET SocketAPI::socket_ex(int domain, int type, int protocol)
{
	SOCKET s = socket(domain, type, protocol);
	return (INVALID_SOCKET == s) ? INVALID_SOCKET : s;
}

bool SocketAPI::bind_ex(SOCKET s, const struct sockaddr *addr, int addrlen)
{

	return (SOCKET_ERROR == bind(s, addr, addrlen)) ? false : true;
}

bool SocketAPI::connect_ex(SOCKET s, const struct sockaddr *addr, int len)
{
	return (SOCKET_ERROR == connect(s, addr, len)) ? false : true;
}

bool SocketAPI::listen_ex(SOCKET s, int num)
{
	return (SOCKET_ERROR == listen(s, num)) ? false : true;
}

SOCKET SocketAPI::accept_ex(SOCKET s, struct sockaddr *addr, int *addrlen)
{
	SOCKET client_sock = accept(s, addr, addrlen);
	return (INVALID_SOCKET == client_sock) ? INVALID_SOCKET : client_sock;
}

int SocketAPI::getsockopt_ex(SOCKET s, int level, int optname, void *optval, int *optlen)
{
#if __LINUX__
	return (getsockopt(s, level, optname, optval, optlen) == SOCKET_ERROR) ? false : true;
#elif __WINDOWS__
	return (getsockopt(s, level, optname, (char*)optval, optlen) == SOCKET_ERROR) ? false : true;
#endif
	return false;
}

int SocketAPI::setsocketopt_ex(SOCKET s, int level, int optname, void *optval, int *optlen)
{
#if __LINUX__
	return (getsockopt(s, level, optname, optval, optlen) == SOCKET_ERROR) ? false : true;
#elif __WINDOWS__
	return (getsockopt(s, level, optname, (char*)optval, optlen) == SOCKET_ERROR) ? false : true;
#endif
	return false;
}

int SocketAPI::send_ex(SOCKET s, const void *buf, int len, int flags)
{
	int nlen = 0;
#if __LINUX__
	nlen = send(s, buf, len, flags);
#elif __WINDOWS__
	nlen = send(s, (const char*)buf, len, flags);	
#endif
	return (nlen == SOCKET_ERROR) ? SOCKET_ERROR : nlen;
}

int SocketAPI::sendto_ex(SOCKET s, const void *buf, int len, int flags, const struct sockaddr *addr, int tolen)
{
	int nlen = 0;
#if __LINUX__
	nlen = sendto(s, buf, len, flags, addr, tolen);
#elif __WINDOWS__
	nlen = sendto(s, (const char*)buf, len, flags, addr, tolen);
#endif
	return (nlen == SOCKET_ERROR) ? SOCKET_ERROR : nlen;
}

int SocketAPI::recv_ex(SOCKET s, void *buf, int len, int flags)
{
	int nlen = 0;
#if __LINUX__
	nlen == recv(s, buf, len, flags);
#elif __WINDOWS__
	nlen == recv(s, (char*)buf, len, flags);
#endif
	return (nlen == SOCKET_ERROR) ? SOCKET_ERROR : nlen;
}

int SocketAPI::recvfrom_ex(SOCKET s, void *buf, int len, int flags, struct sockaddr *from, int *fromlen)
{
	int nlen = 0;
#if __LINUX__
	nlen = recvfrom(s, buf, len, flags, from, fromlen);
#elif __WINDOWS__
	nlen = recvfrom(s, (char*)buf, len, flags, from, fromlen);
#endif
	return (nlen == SOCKET_ERROR) ? SOCKET_ERROR : nlen;
}

bool SocketAPI::closesocket_ex(SOCKET s)
{
#if __LINUX__
	close(s);
	return true;
#elif __WINDOWS__
	return (closesocket(s) == SOCKET_ERROR) ? false : true;
#endif
	return false;
}

bool SocketAPI::ioctlsocket_ex(SOCKET s, long cmd, unsigned long *arg)
{
#if __LINUX__
#elif __WINDOWS__
	return (ioctlsocket(s, cmd, arg) == SOCKET_ERROR) ? false : true;
#endif
	return false;
}

bool SocketAPI::getsocketnonblocking_ex(SOCKET s)
{

}

bool SocketAPI::setsocketnonblocking_ex(SOCKET s, bool on)
{

}

int SocketAPI::availablesocket_ex(SOCKET s)
{

}

bool SocketAPI::shutdown_ex(SOCKET s)
{

}

int SocketAPI::select_ex(int maxfd, fd_set *readset, fd_set *writeset, fd_set *exceptset, struct timeval *timeout)
{

}

