#ifndef _UTILS_H_
#define _UTILS_H_
#include <iostream>
static void coutArray(int *array, int length)
{
	if (array == NULL)
	{
		return;
	}
	for (int i = 0; i < length; i++)
	{
		std::cout << "array[i] = " << array[i] << std::endl;
	}
}

#endif // !_UTILS_H_
