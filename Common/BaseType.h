#include <stdlib.h>

// 根据指针删除内存
void safe_delete(void* ptr)
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

void safe_delete_array(void* ptr)
{
	if (ptr != nullptr)
	{
		delete[] ptr;
		ptr = nullptr;
	}
}

// 根据指针调用free
void safe_free(void* ptr)
{
	if (ptr = nullptr)
	{
		free(ptr);
		ptr = nullptr;
	}
}