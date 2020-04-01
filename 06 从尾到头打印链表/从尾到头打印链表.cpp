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

//����һ���½ڵ㵽������(��������ͷ��)
void CreateList(ListNode * & head, int data)
{
	// �����½ڵ�
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->value = data;
	p->next = nullptr;
	// ���뵽ͷ��
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



//�ݹ鷽ʽ��ʵ�ֵ�����ת
ListNode * ReverseList1(ListNode * head)
{
	// �ݹ���ֹ����
	if (head == nullptr || head->next == nullptr)
		return head;
	else
	{
		// �ݹ�
		ListNode * newhead = ReverseList1(head->next);
		head->next->next = head;	//�ȷ�ת�����������������������㿪ʼ��ת��������ǰ
		head->next = nullptr;	//��ԭ������ǰһ�����ָ���һ������ָ���ϵ�Ͽ�
		return newhead;	// ��ԭ����β ������ͷ ���س���
	}
}
//������ʽ��ʵ�ֵ�����ת
ListNode* ReverseList2(ListNode* head) 
{
	if (head == nullptr || head->next == nullptr)
		return head;
	// �ڱ��ڵ� ���� ��ת����

	ListNode* prev = nullptr;
	ListNode* cur = head;
	ListNode* temp = nullptr;
	while (cur != nullptr) {
		temp = cur->next; //temp��Ϊ�м�ڵ㣬��¼��ǰ������һ���ڵ��λ��
		cur->next = prev;  //��ǰ���ָ��ǰһ���ڵ�
		prev = cur;     //ָ�����
		cur = temp;  //ָ����ƣ�������һ���ڵ�
	}
	return prev;
}

void PrintListReversingly_Stack(ListNode* head)
{
	stack<ListNode*> listStack;
	ListNode *pNode = head;
	while (pNode != nullptr)	// ѭ����ջ
	{
		listStack.push(pNode);
		pNode = pNode->next;
	}

	while (!listStack.empty())	// ��ջ��ӡ
	{
		pNode = listStack.top();
		cout << pNode->value << " ";
		listStack.pop();
	}
	cout << endl;
}


void PrintListReversingly_Recursively(ListNode* head)
{
	// �ݹ���ֹ����
	if (head == nullptr)
		return;
	else
	{
		PrintListReversingly_Recursively(head->next);
		cout << head->value << " ";
		return;
	}

}