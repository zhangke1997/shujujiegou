#include<stdio.h>//模拟后缀操作符56*3+操作
#include"stack_three.h"
int main()
{
    struct SNode *s=CreateStack();
    Push(5,s);
    Push(6,s);
    int bbb=Pop(s)+Pop(s);
    int aa=IsEmpty(s);
    printf("空栈为:%d\n",aa);
    Push(3,s);
    bbb=bbb+Pop(s);
    printf("结果为:%d\n",bbb);





    return 0;
}