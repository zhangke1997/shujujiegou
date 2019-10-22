#include<stdio.h>
#include<stdlib.h>
//二叉树存储：数组存储和链表//存储
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	int Data;
	BinTree Left;
	BinTree Right;
}
//
//递归遍历
///
void PreOrderTraversal(BinTree BT)//先序遍历 根左右
{
	if(BT)
	{
		printf("%d",BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}

}
void  InOrderTracversal(BinTree BT)//中序遍历 左根右
{
	if(BT)
	{
		InOderTravelsal(BT->left);
		printf("%d",BT->Data);
		InOrderTraversal(BT->Right);

	}
}
void PostOrderTraversal(BinTree BT)//后序遍历  左右根
{
	if(BT)
	{
		PostOderTravelsal(BT->left);
		
		PostOrderTraversal(BT->Right);
		printf("%d",BT->Data);

	}	

}

//
//
//




//非递归遍历
//堆栈中序遍历
void InOrderTraversal(BinTree BT)
{
	BinTree T=BT;
	Stack S = CreatStack(MaxSize);
	while(T||!IsEmpty(S))
	{
		while(T)//一直向左压入堆栈
		{
			Push(S,T);
			T=T->left;		
		}	
		if(!IsEmpty(S))
		{
			T =Pop(S);//压不动了就弹出
			printf("%5d",T->Data);
			T=T->Right;//变换为右结点 返回继续向左压入堆栈
		}

	}

}
//堆栈先序遍历
void InOrderTraversal(BinTree BT)
{
	BinTree T=BT;
	Stack S = CreatStack(MaxSize);
	while(T||!IsEmpty(S))
	{
		while(T)//一直向左压入堆栈
		{
			printf("%5d",T->Data);
			T=T->left;		
		}	
		if(!IsEmpty(S))
		{
			T=Pop(S);//弹出上一层
			Push(S,T);
			T=T->Right;//变换为右结点 返回继续向左压入堆栈
		}

	}

}

///层序遍历,先序 根左右，队列实现
void LevelOrderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	if (!BT) return;
	Q=CreatQueue(Maxsize);
	AddQ(Q,BT);
	while(!IsEmptyQ(Q))
	{
		T = DeleteQ(Q); //抛出根
		printf("%d\n",T->Data);
		if(T->Left) AddQ(Q,T->Left);//左右入
		if(T->Right) AddQ(Q,T->Right);
	}


}

//求二叉树的高度dfs

int PostOrderGetHeight(BinTree BT)
{
	int HL,HR,MaxH;
	if(BT)
	{
		HL=PostOrderGetHeight(BT->Left);
		HR=PostOrderGetHeight(BT->right);
		MaxH=(HL>HR)?HL:HR;
		return (MaxH+1);//后序遍历 回退则加一	
	}
	else  return 0; 

}
//二元运算表达式树及其遍历

//有中序遍历的两种遍历能确定一个二叉树
//左右孩子交换一样则是同构的

//二叉树的同构判断
























