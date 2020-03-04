#include <cstring>
#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	//�������캯��
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator = (const CMyString& str);

	char *getData();
private:
	char* m_pData;
};

//���캯�� 1   char *pData
CMyString::CMyString(char *pData)
{
	cout << "���캯�� 1" << endl;
	if (pData == nullptr)	// �������
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		//  strlen �����ַ����ĳ��ȣ��Խ����� 0x00 Ϊ�ַ�����������������
		//�ɲμ� https://www.cnblogs.com/BeyondAnyTime/archive/2012/05/28/2521460.html
		int length = strlen(pData);	
		m_pData = new char[length + 1];	// new char[]
		strcpy(m_pData, pData);	//����
	}
}

//���캯�� 2  const CMyString &str //����ʹ��const������
CMyString::CMyString(const CMyString &str)
{
	cout << "���ǹ��캯�� 2" << endl;
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}
// ��������
CMyString::~CMyString()
{
	delete[] m_pData;	// delet[]
}

char *CMyString::getData() {
	return m_pData;
}

//// ����һ��
//// ��ֵ���������  ����� 1
//CMyString& CMyString::operator = (const CMyString& str) // ����� 2 
//{
//	cout << "���ǿ�����ֵ�����������һ" << endl;
//
//	if (this == &str)	// 
//		//����Ը�ֵ�����	����� 4
//		return *this;
//
//	delete[]m_pData;	//  ����� 3
//	m_pData = nullptr;
//
//	m_pData = new char[strlen(str.m_pData) + 1];
//	strcpy(m_pData, str.m_pData);
//
//	return *this;	// ����� 1
//}

// ��������
CMyString &CMyString::operator=(const CMyString &str) {
	cout << "���ǿ�����ֵ�������������\n" << endl;
	if (this != &str) {
		//���ÿ������캯��
		CMyString strTmp(str);	// ���� 6

		char *pTmp = strTmp.m_pData;
		strTmp.m_pData = m_pData;
		m_pData = pTmp;
	}
	// if ������ strTmp �������ڽ��� �Զ����� strTmp����������
	return *this;
}

int main()
{
	char *tmp = "hello world +++";
	CMyString myStr(tmp);	// 
	cout << "myStr: " << myStr.getData() << endl;

	CMyString otherOne = myStr;
	cout << "otherOne: " << otherOne.getData() << endl;

	char *tmp2 = "hello world ---";
	CMyString myStr2(tmp2);
	cout << "myStr2: " << myStr2.getData() << endl;

	myStr2 = otherOne;
	cout << "myStr2 after operator \"=\": " << myStr2.getData() << endl;

	char* text = "Hello world";
	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;
	cout << "str3 = " << str3.getData()<< " str2 = " << str2.getData() << " str1 = " << str1.getData() << endl;

	system("pause");
	return 0;
}