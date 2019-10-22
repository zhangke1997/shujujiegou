#ifndef POLYNODE_DUOXIANGSHI_H_INCLUDED
#define POLYNODE_DUOXIANGSHI_H_INCLUDED
#include<stdlib.h>
#include<strcmp.h>
///多项式的相加，链表比数组的好处是不用事先确定项数
struct PolyNode{
    int coef;
    int expon;
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;

void Attach(int c ,int e,Polynomial *pRear)//指针的指针 ,存入队尾
{
    Polynomial P;//新节点指针
    P->coef=c;
    P->expon=e;
    P->link=NULL;
    (*pRear)->link=p; //队列尾指向新的节点，连起来
    *pRear=p;//更换队列尾的名字
}
Polynomial PolyAdd(Polynomial P1,Polynomial P2)//两指针的相加
{
    Polynomial front,rear,temp;//结果队列
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;             //分配空间
    while(P1&&P2)
        switch(Compare(P1->expon,P2->expon))
        {
        case 1:
            Attach(P1->coef,P1->expon,&rear)；
            P1=P1->link;//P1被重新定义为下一项
            break;
        case -1:
            Attach(P2->coef,P2->expon,&rear);
            P2=P2->link;
            break;
        case 0:
            sum=P1->coef+P2->coef;
            if(sum)Attach(sum,P1->expon,&rear);//系数相加为零则不操作
            P1=P1->link;
            P2=P2->link;
            break;
        }
    for(;P1;P1=P1->link)Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2=P2->link)Attach(P2->coef,P2->expon,&rear);
    rear->link=NULL;
    temp =front;              //头节点实例化，空节点删掉
    front= front->link;
    free(temp);
    return front;

}



#endif // POLYNODE_DUOXIANGSHI_H_INCLUDED
