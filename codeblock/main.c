#include<stdio.h>//ģ���׺������56*3+����
#include"stack_three.h"
int main()
{
    struct SNode *s=CreateStack();
    Push(5,s);
    Push(6,s);
    //int b1=Pop(s);
    //int b2=Pop(s);
    int bbb=Pop(s)*Pop(s);
    int aa=IsEmpty(s);
    printf("��ջΪ%d\n",bbb);
    Push(3,s);
    bbb=bbb+Pop(s);
    printf("���Ϊ:%d\n",bbb);

    return 0;
}
