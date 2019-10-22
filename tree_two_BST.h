//Binary Search Tree
//BST 二叉搜索树
//1，非空左子树所有键值小于根
//2,非空右子树所有键值大于根结点
//3,左右子树都是二叉搜索树
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	int Data;
	BinTree Left;
	BinTree Right;
}


Position Find(int x,BinTree BST)//递归实现返回的是结点
{
	if(!BST) return NULL;
	if(X>BST->Data) return Find(x,BST->Right);//递归		
	else if(x<BST->Data) return Find(x,BST->Left);
		else return BST;//返回的是结点


}

Position IterFind(int x,BinTree BST)//循环实现
{
	while(BST)
	{
		if(x>BST->Data)
			BST=BST->Right;
		else if(x<BST->Left)
			BST=BST->Left;
		else 
			return BST;
	}
	return NULL;

}
Position FindMin(BinTree BST)//寻找最小结点，递归实现
{
	if(!BST)
		return NULL;
	else if(!BST->Left)//最左为空的结点是最小的
		return BST;
	else 
		return FindMin(BST->Left);
}

Position FindMax(BinTree BST)//寻找最大结点 循环实现
{
	if(BST)
		while(BST->Right)
			BST=BST->Right;
	return BST;
}

BinTree Insert(int x, BinTree BST)//大小插入
{
	if(!BST)//递归先写底层的实现
	{
		BST=malloc(sizeof(struct TreeNode));
		BST->Data=x;
		BST->Left=BST->Right=NULL;
	}
	else if(x<BST->Data)
		BST->Left=Insert(x,BST->Left);//返回的是上一个结点，新建的结点连接到最下面的那个结点，
	else if(x>BST->Data)
		BST->Right=Insert(x,BST->Right);

	return BST;
}

//删除结点 找左子树的最大值，找右子树的最小值 ，因为他们一定没有两个儿子
BinTree Delete(int x,BinTree BST)
{
	Position Tmp;
	if(!BST)
		printf("要删除的元素没有找到");
	else if (x<BST->Data)
		BST->Left=Delete(x,BST->Left);
	else if(x>BST->Right)
		BST->Right=Delete(x,BST->Right);
	else if (BST->Left && BST->Right)//左右都有
	{
		Tmp = FindMin(BST->Right);//寻找右子树最小值
		BST->Data = Tmp->Data;
		BST->Right = Delete(BST->Data,BST->Right);//删出后连接
	}
		else{
			Tmp =BST;
			if(!BST->Left)//左空
			BST=BST->Right;
			else if(!BST->Right)//右空
				BST =BST->Left;
				free(Tmp);
		}
		return BST;
}



