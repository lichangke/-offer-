
#include <stdio.h>

using namespace std;

struct BinaryTreeNode
{
	int                    m_nValue;
	BinaryTreeNode*        m_pLeft;		// ָ�����ӽڵ��ָ��
	BinaryTreeNode*        m_pRight;	// ָ�����ӽڵ��ָ��
	BinaryTreeNode*        m_pParent;	// ָ�򸸽ڵ��ָ��
};


BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;
	// �ж��Ƿ��� ������
	if (pNode->m_pRight != nullptr)
	{
		// �� ������
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr) // �� ����ڵ�
			pRight = pRight->m_pLeft;

		pNext = pRight;
	}
	else if (pNode->m_pParent != nullptr)
	{
		// û�� ������
		BinaryTreeNode* pCurrent = pNode; // ��ǰ�ڵ�
		BinaryTreeNode* pParent = pNode->m_pParent;	// ���ڵ�
		while (pParent != nullptr )
		{	
			if (pCurrent == pParent->m_pLeft)
			{
				break;
			}
			// ���� �� ���ڵ� ֱ��
			// 1�� pParent Ϊ nullptr �� ������ѵ����ڵ�
			// 2�� pCurrent ���� pParent �� ���ӽڵ㣬 pCurrent ��  pParent �� ���ӽڵ�
			pCurrent = pParent; 
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}