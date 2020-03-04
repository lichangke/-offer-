#include <cstring>
#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	//拷贝构造函数
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator = (const CMyString& str);

	char *getData();
private:
	char* m_pData;
};

//构造函数 1   char *pData
CMyString::CMyString(char *pData)
{
	cout << "构造函数 1" << endl;
	if (pData == nullptr)	// 参数检测
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		//  strlen 计算字符串的长度，以结束符 0x00 为字符串结束（不包含）
		//可参见 https://www.cnblogs.com/BeyondAnyTime/archive/2012/05/28/2521460.html
		int length = strlen(pData);	
		m_pData = new char[length + 1];	// new char[]
		strcpy(m_pData, pData);	//拷贝
	}
}

//构造函数 2  const CMyString &str //参数使用const的引用
CMyString::CMyString(const CMyString &str)
{
	cout << "这是构造函数 2" << endl;
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}
// 析构函数
CMyString::~CMyString()
{
	delete[] m_pData;	// delet[]
}

char *CMyString::getData() {
	return m_pData;
}

//// 方法一：
//// 赋值运算符函数  考察点 1
//CMyString& CMyString::operator = (const CMyString& str) // 考察点 2 
//{
//	cout << "这是拷贝赋值运算符！方法一" << endl;
//
//	if (this == &str)	// 
//		//检查自赋值的情况	考察点 4
//		return *this;
//
//	delete[]m_pData;	//  考察点 3
//	m_pData = nullptr;
//
//	m_pData = new char[strlen(str.m_pData) + 1];
//	strcpy(m_pData, str.m_pData);
//
//	return *this;	// 考察点 1
//}

// 方法二：
CMyString &CMyString::operator=(const CMyString &str) {
	cout << "这是拷贝赋值运算符！方法二\n" << endl;
	if (this != &str) {
		//调用拷贝构造函数
		CMyString strTmp(str);	// 进阶 6

		char *pTmp = strTmp.m_pData;
		strTmp.m_pData = m_pData;
		m_pData = pTmp;
	}
	// if 语句结束 strTmp 生命周期结束 自动调用 strTmp的析构函数
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