# include<iostream>

using namespace std;

void replaceSpace(char str[], int length);

int main()
{
	char test[15] = "We Are Happy.";
	cout << "Before:"<< test << endl;

	replaceSpace(test, 15);

	cout << "After:" << test << endl;
	system("pause");
	return 0;
}

// length 为字符数组 str 的总容量
void replaceSpace(char str[], int length) {
	if (str == nullptr || length <= 0) {
		return;
	}
	int originalLength = 0; // 原始字符串的长度
	int numberOfBlank = 0; // 空格的个数

	int i = 0;	// 扫描 原始字符串，计数空格个数 以及 原始字符串的长度， 不包括结束符
	while (str[i] != '\0') {
		++originalLength;

		if (str[i] == ' ') {
			++numberOfBlank;
		}
		i++;
	}

	/* 计算 newLength,  为把空格替换成 '%20' 之后的长度*/
	int newLength = originalLength + numberOfBlank * 2;	// 空格 -> %20 多了两个字符
	if (newLength > length) {	// 是否超出字符数组大小
		cout << "Out of range" << endl;
		return;
	}

	int indexOfOriginal = originalLength; // index 数组下标从 0 开始，这里包括结束符 所以不用-1
	int indexOfNew = newLength; 

	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (str[indexOfOriginal] == ' ') {	// 替换空格
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else {
			str[indexOfNew--] = str[indexOfOriginal];	// 搬移数据
		}

		--indexOfOriginal;	//  从后向前
	}
}