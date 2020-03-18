# include<iostream>

using namespace std;

/*
ʹ��hash�����ж��Ƿ����ظ�
ʱ�临�Ӷ�ΪO(n) �ռ临�Ӷ�Ϊ O(n) 
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

	int *hashTable = new int[length](); // �����±�Ϊ numbers[] Ԫ��

	for (int i = 0; i < length; i++) {
		int num = numbers[i];
		if (hashTable[num]){	// ����±�Ϊ num �������ݱ������ظ�����
			*duplication = numbers[i];	// ��������
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
