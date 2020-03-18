# include<iostream>

using namespace std;

/*
交换元素位置
时间复杂度为O(n) 空间复杂度为 O(1)
*/

bool duplicate(int nums[], int length, int* duplication);

int main()
{
	int a[] = { 2,1,3,1,4 };
	int *resu = new int(-1);
	if (!duplicate(a, sizeof(a) / sizeof(int), resu))
	{
		cout << "fail" << endl;
	}
	cout << *resu << endl;
	system("pause");
	return 0;
}

bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == nullptr || length <= 1)
		return false;

	for (int i = 0; i < length; i++) {	// 数据有效检查
		int num = numbers[i];
		if (num < 0|| num > length-1){
			return false;
		}
	}

	for (int i = 0; i < length; i++) {
		while (numbers[i]!=i)	// numbers[i] 与 i 不等 一直交换 numbers[i] 和 numbers[numbers[i]]
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];	// 传出数据
				return true;
			}

			int temp = numbers[i];	
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;

}