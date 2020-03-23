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

// length Ϊ�ַ����� str ��������
void replaceSpace(char str[], int length) {
	if (str == nullptr || length <= 0) {
		return;
	}
	int originalLength = 0; // ԭʼ�ַ����ĳ���
	int numberOfBlank = 0; // �ո�ĸ���

	int i = 0;	// ɨ�� ԭʼ�ַ����������ո���� �Լ� ԭʼ�ַ����ĳ��ȣ� ������������
	while (str[i] != '\0') {
		++originalLength;

		if (str[i] == ' ') {
			++numberOfBlank;
		}
		i++;
	}

	/* ���� newLength,  Ϊ�ѿո��滻�� '%20' ֮��ĳ���*/
	int newLength = originalLength + numberOfBlank * 2;	// �ո� -> %20 ���������ַ�
	if (newLength > length) {	// �Ƿ񳬳��ַ������С
		cout << "Out of range" << endl;
		return;
	}

	int indexOfOriginal = originalLength; // index �����±�� 0 ��ʼ��������������� ���Բ���-1
	int indexOfNew = newLength; 

	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (str[indexOfOriginal] == ' ') {	// �滻�ո�
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else {
			str[indexOfNew--] = str[indexOfOriginal];	// ��������
		}

		--indexOfOriginal;	//  �Ӻ���ǰ
	}
}