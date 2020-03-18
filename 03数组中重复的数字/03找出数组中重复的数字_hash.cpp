# include<iostream>

using namespace std;

/*
使用hash表来判断是否有重复
时间复杂度为O(n) 空间复杂度为 O(n) 
*/

bool duplicate(int nums[], int length, int* duplication);

int main()
{
	int a[] = { 2,1,3,1,4 };
	int *resu = new int(0);
	duplicate(a, sizeof(a) / sizeof(int), resu);
	cout << *resu << endl;
	system("pause");
	return 0;
}

bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == nullptr || length <= 1) 
		return false;

	int *hashTable = new int[length](); // 用于下标为 numbers[] 元素

	for (int i = 0; i < length; i++) {
		int num = numbers[i];
		if (hashTable[num]){	// 如果下标为 num 中有数据表明有重复数据
			*duplication = numbers[i];	// 传出数据
			delete[]hashTable;
			return true;
		}
		else {
			hashTable[numbers[i]] = 1;
		}
	}
	delete[]hashTable;
	return false;

}
