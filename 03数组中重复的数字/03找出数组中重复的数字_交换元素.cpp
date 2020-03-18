# include<iostream>

using namespace std;

/*
����Ԫ��λ��
ʱ�临�Ӷ�ΪO(n) �ռ临�Ӷ�Ϊ O(1)
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

	for (int i = 0; i < length; i++) {	// ������Ч���
		int num = numbers[i];
		if (num < 0|| num > length-1){
			return false;
		}
	}

	for (int i = 0; i < length; i++) {
		while (numbers[i]!=i)	// numbers[i] �� i ���� һֱ���� numbers[i] �� numbers[numbers[i]]
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];	// ��������
				return true;
			}

			int temp = numbers[i];	
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;

}