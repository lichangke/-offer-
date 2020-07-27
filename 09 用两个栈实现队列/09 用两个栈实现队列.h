#pragma once
#include <stack>
#include <exception>

using namespace std;

template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	// 在队列末尾添加一个结点
	void appendTail(const T& node);

	// 删除队列的头结点
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template <typename T> void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);	// 尾部添加 直接 stack1 入栈
}

template <typename T> T CQueue<T>::deleteHead()
{
	// 删除头部 需分情况处理
	if (stack2.size() <= 0)	// stack2 中没有数据 需要从 stack1 依次出栈元素并压入stack2中
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();	
			stack1.pop();
			stack2.push(data);
		}
	}
	
	if (stack2.size() == 0) //上述处理后 还未空 说明 本身为空 
		throw new exception("queue is empty");

	T head = stack2.top();
	stack2.pop();
	return head;
}

