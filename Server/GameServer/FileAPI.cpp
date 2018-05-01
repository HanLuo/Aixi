#include "FileAPI.h"

#if __WINDOWS__
#include <io.h>
#include <string.h>
#elif __LINUX__
#endif

int FileAPI::open_ex(const char *filename, int flags)
{
	return open(filename, flags);
}

int FileAPI::open_ex(const char *filename, int flags, int mode)
{
	return open(filename, flags, mode);
}

void FileAPI::close_ex(int fd)
{
	close(fd);
}

// read from fd to buf 
int FileAPI::read_ex(int fd, void *buf, int len)
{
	return read(fd, buf, len);
}

// write fd from buf
int FileAPI::write_ex(int fd, const char *buf, int len)
{
	return write(fd, buf, len);
}

long FileAPI::lseek_ex(int fd, long offset, int origin)
{
	return lseek(fd, offset, origin);
}

long FileAPI::tell_ex(int fd)
{
	return tell(fd);
}



