#include <exception>
#include <cstdio>

// ���
struct BinaryTreeNode
{
	int                    m_nValue;
	BinaryTreeNode*        m_pLeft;
	BinaryTreeNode*        m_pRight;
};
void DestroyTree(BinaryTreeNode* pRoot);
void PrintTree(const BinaryTreeNode* pRoot);
void PrintTreeNode(const BinaryTreeNode* pNode);
void Test1();
void Test(char* testName, int* preorder, int* inorder, int length);

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

/*
preorder:	ǰ���������
inorder:	�����������
length:		Ԫ�ظ���
*/
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
}

/*
�ݹ�������
startPreorder:	ǰ�����������ʼλ��
endPreorder:	ǰ��������н���λ��
startInorder:	�������������ʼλ��
endInorder:		����������н���λ��
eg: ��ǰ���������{1,2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}Ϊ����

*/
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	// eg: startPreorder = 1 endPreorder = 8  startInorder = 4 endInorder = 6
	// ǰ��������еĵ�һ�������Ǹ�����ֵ
	int rootValue = startPreorder[0];	// eg: 1
	// ���������
	BinaryTreeNode* root = new BinaryTreeNode();	
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	// �ݹ���ֹ���������쳣����
	if (startPreorder == endPreorder) // ǰ�����������ʼλ�� == ǰ��������н���λ��
	{
		// �������������ʼλ�� == ����������н���λ�� ���� ��ʱ ǰ������Ӧ��ָ��ͬһ�������ֵ��� *startPreorder == *startInorder
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else // �����׳��쳣
			throw std::exception("Invalid input.");
	}

	// ���� ����������� ͨ�� ������ֵ �ҵ� ��λ�ã��Ӷ�֪�� ��������������
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&& * rootInorder != rootValue)
		rootInorder++;
	// �쳣����������������
	if (rootInorder == endInorder && * rootInorder != rootValue)
	{
		throw std::exception("Invalid input.");
	}

	// ��ʱ rootInorder ָ�� ��������� ��ô rootInorder - 1 Ϊ ������ ����������н���λ�� eg: 2  startInorder Ϊ ������ �������������ʼλ�� eg: 4
	int leftLength = rootInorder - startInorder; // ���������ݸ��� eg: leftLength = 3
	// ���� ������ ǰ��������н���λ��   startPreorder + 1  Ϊ ������ ǰ�����������ʼλ�� eg: 2   leftPreorderEnd Ϊ ������ ǰ��������н���λ�� eg: 7
	int* leftPreorderEnd = startPreorder + leftLength;	// 
	// ��Ϊ ������������
	if (leftLength > 0) // ���� ������
	{
		// ���������� �ݹ�  
		// startPreorder + 1 �� ������ ǰ�����������ʼλ�ã�  leftPreorderEnd �� ������ ǰ��������н���λ��
		// startInorder�� ������ �������������ʼλ�ã�   rootInorder - 1  �������� ����������н���λ��
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
			startInorder, rootInorder - 1);
	}
	// ���� ���������ݸ��� �� (endPreorder - startPreorder) ԭ�� ���ݸ����� Ҳ���� ���������ݸ��� + ���������ݸ���
	int rightLength = (endPreorder - startPreorder) - leftLength;
	if (rightLength > 0)	// ���� ������
	{	
		// ���������� �ݹ�  
		// leftPreorderEnd + 1 �� ������ ǰ�����������ʼλ�ã�  endPreorder �� ������ ǰ��������н���λ��
		// rootInorder + 1�� ������ �������������ʼλ�ã�   endInorder  �������� ����������н���λ��
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
			rootInorder + 1, endInorder);
	}

	return root;
}

int main(int argc, char* argv[])
{
	Test1();
	system("pause");
	return 0;
}

void Test1()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("Test1", preorder, inorder, length);
}


/*
testName:	��������
preorder:	ǰ���������
inorder:	�����������
length:		Ԫ�ظ���
*/
void Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);

		DestroyTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}



void PrintTree(const BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is nullptr.\n");

		if (pNode->m_pRight != nullptr)
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}

	printf("\n");
}
void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}