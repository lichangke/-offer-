
#include <stdio.h>

using namespace std;

struct BinaryTreeNode
{
	int                    m_nValue;
	BinaryTreeNode*        m_pLeft;		// 指向左子节点的指针
	BinaryTreeNode*        m_pRight;	// 指向右子节点的指针
	BinaryTreeNode*        m_pParent;	// 指向父节点的指针
};


BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;
	// 判断是否有 右子树
	if (pNode->m_pRight != nullptr)
	{
		// 有 右子树
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr) // 找 最左节点
			pRight = pRight->m_pLeft;

		pNext = pRight;
	}
	else if (pNode->m_pParent != nullptr)
	{
		// 没有 右子树
		BinaryTreeNode* pCurrent = pNode; // 当前节点
		BinaryTreeNode* pParent = pNode->m_pParent;	// 父节点
		while (pParent != nullptr )
		{	
			if (pCurrent == pParent->m_pLeft)
			{
				break;
			}
			// 迭代 找 父节点 直到
			// 1、 pParent 为 nullptr ， 这个是已到根节点
			// 2、 pCurrent 不是 pParent 的 右子节点， pCurrent 是  pParent 的 左子节点
			pCurrent = pParent; 
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}