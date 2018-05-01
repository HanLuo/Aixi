#pragma once

// file 
#include "BaseType.h"

namespace FileAPI
{
	// open()
	int open_ex (const char *filename, int flags);

	int open_ex (const char *filename, int flags, int mode);

	// close()
	void close_ex (int fd);

	// read()
	int read_ex (int fd, void *buf, int len);

	// write()
	int write_ex(int fd, const char *buf, int len);

	// lseek_ex
	long lseek_ex(int fd, long offset, int origin);

	// tell
	long tell_ex(int fd);
}
