
//����ʽ  �Ľ�
#include <iostream>
using namespace std;

class Singleton
{
private:
	//��̬��Ա����������˽�еģ�ָ��һ��CSingletonʵ����ͬһʱ��ֻ����һ���������������ֻ�ܴ���һ��CSingleton��ʵ��
	static Singleton *local_instance;
	//���캯����˽�еģ�����ͨ�����캯�����������ʵ��
	Singleton() {
		cout << "����" << endl;
	};
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::local_instance)
			{
				delete Singleton::local_instance;
				cout << "delete only success " << endl;
			}
		}
	};
	static CGarbo Garbo;

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
Singleton::CGarbo Singleton::Garbo;

int main()
{
	Singleton * s = Singleton::getInstance();
	cout << "s = " << s << endl;
	Singleton * s1 = Singleton::getInstance();
	cout << "s1 = " << s1 << endl;
	system("pause");
	return 0;
}
