#include <stdlib.h>

// ����ָ��ɾ���ڴ�
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

// ����ָ�����free
void safe_free(void* ptr)
{
	if (ptr = nullptr)
	{
		free(ptr);
		ptr = nullptr;
	}
}