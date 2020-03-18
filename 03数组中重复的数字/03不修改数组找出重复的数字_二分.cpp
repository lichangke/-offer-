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
	int end = length - 1;	// n+1����������������ֶ���1~n��Χ�ڣ� ����Ϊ length - 1

	while (end>=start)	// ѭ������  
	{	
		 //1���ҳ������м����� middle
		int middle = ((end - start) >> 1) + start; // ����˼��
		 //2��ͳ�� numbers �� ���� �� [start,middle] �����߽�ĸ��� count
		int count = countRange(numbers, length, start, middle);
		if (start == middle)	// ����ܻ�ȷ����һ����
		{
			if (count > 1)// ������ִ��� >1 ,������ظ�����
				return start;
			else
				return -1; // ���� ���������⣬û���ظ�����

		}
		 //��� count > middle-start+1 ��ô�� �ظ������� [start,middle] ֮��, ����������[start,middle] �ظ�1��2 ����
		 //��� count <= middle-start+1  ��ô�� �ظ������� [middle+1,end] ֮��, ����������[middle+1,end] �ظ�1��2 ����
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