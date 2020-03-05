
//懒汉式  改进
#include <iostream>
using namespace std;

class Singleton
{
private:
	//静态成员变量，且是私有的，指向一个CSingleton实例，同一时间只存在一个这个变量，所以只能存在一个CSingleton的实例
	static Singleton *local_instance;
	//构造函数是私有的，不能通过构造函数创建该类的实例
	Singleton() {
		cout << "构造" << endl;
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
	// 只能通过这个函数来创建并获得一个CSingleton实例，且这个实例是唯一的（因为没有其他途径创建CSingleton实例，构造函数是私有的）所有GetInstance()之后的调用都返回相同实例的指针
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

Singleton * Singleton::local_instance = nullptr;	// 初始化类的静态成员变量
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
