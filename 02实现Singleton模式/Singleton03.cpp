//����ʽ  
#include <iostream>
using namespace std;

class Singleton
{
private:
	Singleton() {};
public:
	static Singleton *getInstance()
	{
		cout << "getInstance()" << endl;
		static Singleton instance;   //�ֲ���̬����  
		return &instance;
	}
};

int main()
{
	Singleton * s = Singleton::getInstance();
	cout << "s = " << s << endl;
	Singleton * s1 = Singleton::getInstance();
	cout << "s1 = " << s1 << endl;
	system("pause");
	return 0;
}