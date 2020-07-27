#include "09 用两个栈实现队列.h"
#include <iostream>

int main(int argc, char* argv[])
{
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	cout << head << endl;

	queue.appendTail('d');
	head = queue.deleteHead();
	cout << head << endl;

	queue.appendTail('e');
	head = queue.deleteHead();
	cout << head << endl;

	head = queue.deleteHead();
	cout << head << endl;
	system("pause");
	return 0;
}