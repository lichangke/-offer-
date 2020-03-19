# include<iostream>

using namespace std;

bool Find(int* matrix, int rows, int columns, int number);

int main()
{
	int matrix[4][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	// 将二维数组当一维数组操作
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
		// 从右上角开始 也就是 0行 columns - 1 列
		int row = 0;
		int column = columns - 1;
		// 迭代处理 数据范围 逐步向左下角
		while (row < rows && column > 0)
		{
			// 右上角的数
			int test_num = matrix[row * columns + column]; // 当一维数组操作
			// 找到
			if (test_num == number) {
				found = true;
				break;
			}
			// 根据 test_num 与 number 大小关系 ，移动 row column(剔除行或者列)
			else if (test_num < number)	//剔除行
				row++;
			else   //剔除列
				column--;
		}

	}
	return found;
}