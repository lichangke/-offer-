//����ʽ  �����ڴ�й©�����⣬new�����Ķ���ʼ��û���ͷ�
#include <iostream>
using namespace std;

class Singleton
{
private:
	//��̬��Ա����������˽�еģ�ָ��һ��CSingletonʵ����ͬһʱ��ֻ����һ���������������ֻ�ܴ���һ��CSingleton��ʵ��
	static Singleton *local_instance;
	//���캯����˽�еģ�����ͨ�����캯�����������ʵ��
	Singleton() {};

public:
	// ֻ��ͨ��������������������һ��CSingletonʵ���������ʵ����Ψһ�ģ���Ϊû������;������CSingletonʵ�������캯����˽�еģ�����GetInstance()֮��ĵ��ö�������ͬʵ����ָ��
	static Singleton *getInstance()
	{
		if (local_instance == nullptr)
		{
			cout << "getInstance new Singleton()" << endl;
			local_instance = new Singleton();
		}
		cout << "getInstance local_instance" << endl;
		return local_instance;
	}
};

Singleton * Singleton::local_instance = nullptr;	// ��ʼ����ľ�̬��Ա����

int main()
{
	Singleton * s = Singleton::getInstance();
	Singleton * s1 = Singleton::getInstance();
	system("pause");
	return 0;
}