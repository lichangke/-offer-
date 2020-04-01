#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
	int value;
	ListNode *next;
};

ListNode * ReverseList1(ListNode * head);
ListNode* ReverseList2(ListNode* head);
void PrintListReversingly_Stack(ListNode* head);
void PrintListReversingly_Recursively(ListNode* head);

//插入一个新节点到链表中(放在链表头部)
void CreateList(ListNode * & head, int data)
{
	// 创建新节点
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->value = data;
	p->next = nullptr;
	// 插入到头部
	if (head == nullptr)
	{
		head = p;
		return;
	}
	p->next = head;
	head = p;
}

void  printList(ListNode* head)
{
	ListNode * p = head;
	while (p != nullptr)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}



int main()
{
	ListNode * head = nullptr;
	for (int i = 0; i<9; i++)
		CreateList(head, i);
	printList(head);
	head = ReverseList1(head);
	// head = ReverseList2(head);
	printList(head);
	//PrintListReversingly_Stack(head);
	//PrintListReversingly_Recursively(head);
	cout << endl;
	system("pause");
	return 0;
}



//递归方式：实现单链表反转
ListNode * ReverseList1(ListNode * head)
{
	// 递归终止条件
	if (head == nullptr || head->next == nullptr)
		return head;
	else
	{
		// 递归
		ListNode * newhead = ReverseList1(head->next);
		head->next->next = head;	//先反转后面的链表，从最后面的两个结点开始反转，依次向前
		head->next = nullptr;	//将原链表中前一个结点指向后一个结点的指向关系断开
		return newhead;	// 将原链表尾 新链表头 返回出来
	}
}
//迭代方式：实现单链表反转
ListNode* ReverseList2(ListNode* head) 
{
	if (head == nullptr || head->next == nullptr)
		return head;
	// 哨兵节点 迭代 反转链表

	ListNode* prev = nullptr;
	ListNode* cur = head;
	ListNode* temp = nullptr;
	while (cur != nullptr) {
		temp = cur->next; //temp作为中间节点，记录当前结点的下一个节点的位置
		cur->next = prev;  //当前结点指向前一个节点
		prev = cur;     //指针后移
		cur = temp;  //指针后移，处理下一个节点
	}
	return prev;
}

void PrintListReversingly_Stack(ListNode* head)
{
	stack<ListNode*> listStack;
	ListNode *pNode = head;
	while (pNode != nullptr)	// 循环入栈
	{
		listStack.push(pNode);
		pNode = pNode->next;
	}

	while (!listStack.empty())	// 出栈打印
	{
		pNode = listStack.top();
		cout << pNode->value << " ";
		listStack.pop();
	}
	cout << endl;
}


void PrintListReversingly_Recursively(ListNode* head)
{
	// 递归终止条件
	if (head == nullptr)
		return;
	else
	{
		PrintListReversingly_Recursively(head->next);
		cout << head->value << " ";
		return;
	}

}