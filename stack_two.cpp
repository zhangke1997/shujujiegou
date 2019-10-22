#include<stdio.h>//
#define MaxSize//最大的个数
struct DStack
{
    int Data[MaxSize];
    int Top1;
    int Top2;
}S;
S.Top1 = -1;
S.Top2 = MaxSize;//例如 100个数 下标0到99 空栈时top1=-1，top2=100
void Push(struct DStack *PtrS,int item,int Tag)
{
    if(PtrS->Top2-PtrS->Top1==1)
    {
        printf("满栈")；
        return;
    }
    if(Tag == 1)
    {
        PtrS->Data[++(PtrS->Top1)] = item;
    }else
    {
        PtrS->Data[--(PtrS->Top2)] = item;
    }
}

int Pop(struct DStack *PtrS,int Tag)
{
    if(Tag == 1)
    if(PtrS->Top1==-1)
    {
        printf("1空栈");
        return NULL;
    }else return PtrS->Data[(PtrS->Top1)--];
    else
    {
        if(PtrS->Top2==MaxSize)
        {
            printf("2空栈");
            return NULL;
        } else return PtrS->Data[(PtrS->Top2)++];           
    }    
}