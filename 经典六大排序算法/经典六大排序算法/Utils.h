#ifndef _UTILS_H_
#define _UTILS_H_
#include <iostream>
#define  INTARRAY_LENGTH(array) (sizeof(array)/sizeof(array[0]))

using namespace std;
static void coutArray(int *array, int length)
{
	if (array == NULL)
	{
		return;
	}
	for (int i = 0; i < length; i++)
	{
		//std::cout << "array[i] = " << array[i] << std::endl;
		printf("array[%d] = %d \n",i,array[i]);
	}
	std::cout << std::endl;
}
/* 
	交换数组中的两个数
	@param:	array 一个 int 型 数组
	@param:	i 一个下标
	@param:	j 一个下标
*/
static void swapNum(int * array,int i,int j)
{
	if (array == NULL)
	{
		std::cout << "param error " << __FILE__ << __FUNCTION__ << __LINE__ << std::endl;
		return;
	}
	cout << "array[i] = " << array[i] << "array[j] = " << array[j] << endl;
/*	如果两个数相等不能用这种方法
	array[i] = array[i] + array[j];
	array[j] = array[i] - array[j];
	array[i] = array[i] - array[j];*/
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	cout << "array[i] = " << array[i] << "array[j] = " << array[j] << endl;
}


#endif // !_UTILS_H_
