# include<iostream>

using namespace std;

bool Find(int* matrix, int rows, int columns, int number);

int main()
{
	int matrix[4][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	// ����ά���鵱һά�������
	bool ret = Find(*matrix, 4, 4, 17);
	if (ret)
		cout << "found" << endl;
	else
		cout << "not found" << endl;
	system("pause");
	return 0;
}

bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;
		
	if (matrix != nullptr&&rows>0&&columns>0)
	{
		// �����Ͻǿ�ʼ Ҳ���� 0�� columns - 1 ��
		int row = 0;
		int column = columns - 1;
		// �������� ���ݷ�Χ �������½�
		while (row < rows && column > 0)
		{
			// ���Ͻǵ���
			int test_num = matrix[row * columns + column]; // ��һά�������
			// �ҵ�
			if (test_num == number) {
				found = true;
				break;
			}
			// ���� test_num �� number ��С��ϵ ���ƶ� row column(�޳��л�����)
			else if (test_num < number)	//�޳���
				row++;
			else   //�޳���
				column--;
		}

	}
	return found;
}