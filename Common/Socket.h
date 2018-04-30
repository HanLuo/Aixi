#ifndef __SOCKET_H__
#define __SOCKET_H__

class Socket
{
public:

	Socket();
	Socket(const char* host, int port);

	virtual ~Socket();

public:
	// 
	bool create();

	// close connection
	void close();

	// 
	bool connect ();
	bool connect (const char* host, int port);

	bool reconnect(const char* host, int port);

	int send(const void *buf, int len, int flags);

	int receive(void *buf, int len, int flags);

	int available() const;
};



#endif