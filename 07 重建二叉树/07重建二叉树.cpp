#include <exception>
#include <cstdio>

// 结点
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
preorder:	前序遍历序列
inorder:	中序遍历序列
length:		元素个数
*/
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
}

/*
递归主函数
startPreorder:	前序遍历序列起始位置
endPreorder:	前序遍历序列结束位置
startInorder:	中序遍历序列起始位置
endInorder:		中序遍历序列结束位置
eg: 以前序遍历序列{1,2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}为例子

*/
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	// eg: startPreorder = 1 endPreorder = 8  startInorder = 4 endInorder = 6
	// 前序遍历序列的第一个数字是根结点的值
	int rootValue = startPreorder[0];	// eg: 1
	// 创建根结点
	BinaryTreeNode* root = new BinaryTreeNode();	
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	// 递归终止条件，和异常处理
	if (startPreorder == endPreorder) // 前序遍历序列起始位置 == 前序遍历序列结束位置
	{
		// 中序遍历序列起始位置 == 中序遍历序列结束位置 并且 此时 前序中序都应该指向同一个结点其值相等 *startPreorder == *startInorder
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else // 否则抛出异常
			throw std::exception("Invalid input.");
	}

	// 遍历 中序遍历序列 通过 根结点的值 找到 其位置，从而知道 其左右子树数据
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&& * rootInorder != rootValue)
		rootInorder++;
	// 异常处理，可能数据有误导
	if (rootInorder == endInorder && * rootInorder != rootValue)
	{
		throw std::exception("Invalid input.");
	}

	// 这时 rootInorder 指向 根结点数， 那么 rootInorder - 1 为 左子树 中序遍历序列结束位置 eg: 2  startInorder 为 左子树 中序遍历序列起始位置 eg: 4
	int leftLength = rootInorder - startInorder; // 左子树数据个数 eg: leftLength = 3
	// 计数 左子树 前序遍历序列结束位置   startPreorder + 1  为 左子树 前序遍历序列起始位置 eg: 2   leftPreorderEnd 为 左子树 前序遍历序列结束位置 eg: 7
	int* leftPreorderEnd = startPreorder + leftLength;	// 
	// 分为 左右子树处理
	if (leftLength > 0) // 存在 左子树
	{
		// 构建左子树 递归  
		// startPreorder + 1 ： 左子树 前序遍历序列起始位置；  leftPreorderEnd ： 左子树 前序遍历序列结束位置
		// startInorder： 左子树 中序遍历序列起始位置；   rootInorder - 1  ：左子树 中序遍历序列结束位置
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
			startInorder, rootInorder - 1);
	}
	// 计数 右子树数据个数 。 (endPreorder - startPreorder) 原树 数据个数， 也就是 左子树数据个数 + 右子树数据个数
	int rightLength = (endPreorder - startPreorder) - leftLength;
	if (rightLength > 0)	// 存在 右子树
	{	
		// 构建右子树 递归  
		// leftPreorderEnd + 1 ： 右子树 前序遍历序列起始位置；  endPreorder ： 右子树 前序遍历序列结束位置
		// rootInorder + 1： 右子树 中序遍历序列起始位置；   endInorder  ：右子树 中序遍历序列结束位置
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
testName:	测试名称
preorder:	前序遍历序列
inorder:	中序遍历序列
length:		元素个数
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