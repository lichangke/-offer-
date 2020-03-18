#include <iostream>
using namespace std;

int getDuplication(const int *numbers, int length);
int countRange(const int *numbers, int length, int start, int  middle);

int main()
{
	int a[] = { 2,3,5,4,3,2,6,7 };
	int a[] = { 1,2,3,4,5,6,7,8 };
	int a[] = { 2,3,5,4,3,1,6,7 };
	int resu = getDuplication(a, sizeof(a) / sizeof(int));
	cout << resu << endl;

	system("pause");
	return 0;
}

int getDuplication(const int *numbers, int length) {
	if (numbers == nullptr || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;	// n+1的数组里的所有数字都在1~n范围内， 最大就为 length - 1

	while (end>=start)	// 循环条件  
	{	
		 //1、找出区间中间数据 middle
		int middle = ((end - start) >> 1) + start; // 二分思想
		 //2、统计 numbers 中 数据 在 [start,middle] 包括边界的个数 count
		int count = countRange(numbers, length, start, middle);
		if (start == middle)	// 最后总会确定到一个数
		{
			if (count > 1)// 如果出现次数 >1 ,这就是重复的数
				return start;
			else
				return -1; // 否则 数据有问题，没有重复的数

		}
		 //如果 count > middle-start+1 那么， 重复数据在 [start,middle] 之间, 于是在区间[start,middle] 重复1、2 操作
		 //如果 count <= middle-start+1  那么， 重复数据在 [middle+1,end] 之间, 于是在区间[middle+1,end] 重复1、2 操作
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle+1;
	}
	return -1;

}

int countRange(const int *numbers, int length, int start, int  end)
{
	if (numbers == nullptr)
		return 0;

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		int num = numbers[i];
		if (num>=start && num<=end)
		{
			count++;
		}
	}
	return count;
}