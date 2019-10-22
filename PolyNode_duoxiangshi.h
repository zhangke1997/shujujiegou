#ifndef POLYNODE_DUOXIANGSHI_H_INCLUDED
#define POLYNODE_DUOXIANGSHI_H_INCLUDED
#include<stdlib.h>
#include<strcmp.h>
///����ʽ����ӣ����������ĺô��ǲ�������ȷ������
struct PolyNode{
    int coef;
    int expon;
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;

void Attach(int c ,int e,Polynomial *pRear)//ָ���ָ�� ,�����β
{
    Polynomial P;//�½ڵ�ָ��
    P->coef=c;
    P->expon=e;
    P->link=NULL;
    (*pRear)->link=p; //����βָ���µĽڵ㣬������
    *pRear=p;//��������β������
}
Polynomial PolyAdd(Polynomial P1,Polynomial P2)//��ָ������
{
    Polynomial front,rear,temp;//�������
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;             //����ռ�
    while(P1&&P2)
        switch(Compare(P1->expon,P2->expon))
        {
        case 1:
            Attach(P1->coef,P1->expon,&rear)��
            P1=P1->link;//P1�����¶���Ϊ��һ��
            break;
        case -1:
            Attach(P2->coef,P2->expon,&rear);
            P2=P2->link;
            break;
        case 0:
            sum=P1->coef+P2->coef;
            if(sum)Attach(sum,P1->expon,&rear);//ϵ�����Ϊ���򲻲���
            P1=P1->link;
            P2=P2->link;
            break;
        }
    for(;P1;P1=P1->link)Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2=P2->link)Attach(P2->coef,P2->expon,&rear);
    rear->link=NULL;
    temp =front;              //ͷ�ڵ�ʵ�������սڵ�ɾ��
    front= front->link;
    free(temp);
    return front;

}



#endif // POLYNODE_DUOXIANGSHI_H_INCLUDED
