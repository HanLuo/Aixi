#pragma once

// file 

namespace FileAPI
{
	// open()
	int open_ex (const char *filename, int flags);

	int open_ex(const char *filename, int flags, int mode);

	// close()
	void close_ex(int fd);
}
