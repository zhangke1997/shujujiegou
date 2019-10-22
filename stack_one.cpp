#include<stdio.h>//数组实现堆栈
#define MaxSize
typedef struct SNode *Stack;
struct SNode
{
    int Data[MaxSize];//MaxSize指的是个数
    int top;//指的是下标的数值,没有数据为-1，有一个是0
};


void Push(Stack PtrS,int item)  //入栈满栈顶
{
    if(PtrS->top==MaxSzie-1)
    {
        printf("满栈");
        return;
    }else
    {
        PtrS->Data[++(PtrS->top)]=item;//先自加后返回
        return;
    }
}

int Pop(Stack PtrS)
{
    if(PtrS->top==-1)
    {
        printf("空栈");
        return ERROR;
    }
    else{
        return PtrS->Data[(PtrS->top)--];//返回再自减
    }
}
