//链表实现堆栈
#ifndef _STACK_THREE_H_
#define _STACK_THREE_H_

#include<stdio.h>
#include<stdlib.h>
typedef struct SNode *Stack;
struct SNode
{
    int Data;
    struct SNode *Next;
};

Stack CreateStack()//建立空栈栈顶节点，虚节点
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}
int IsEmpty(Stack S)
{
    return (S->Next==NULL);
}

void Push(int item,Stack S)//入栈 建立新节点,不需要判满
{
    struct SNode *TmpCell;
    TmpCell=(struct SNode *)malloc(sizeof(struct SNode));
    TmpCell->Data=item;
    TmpCell->Next=S->Next;//继承S
    S->Next=TmpCell;//S抬高

}
int Pop(Stack S)
{
    struct SNode *FirstCell;
    int TopElem;
    if(S->Next==NULL)
    {
        printf("空栈");
        return 0;
    }else
    {
        FirstCell=S->Next;
        S->Next=FirstCell->Next;
        TopElem=FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}

#endif
