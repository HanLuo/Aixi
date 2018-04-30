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

}

