#ifndef QUEUE_ONE_H_INCLUDED
#define QUEUE_ONE_H_INCLUDED

#define MaxSize
struct QNode{    // ѭ������,����ʵ��
    int Data[MaxSize];
    int rear;  //����β
    int front;//����ͷ  front <- rear װ��˳��
};
typedef struct QNode *Queue;

void Add(Queue PtrQ,int item)//���
{
    if((PtrQ->rear+1)%MaxSize == PtrQ->front)//ȡ����Ϊ��ѭ��
    {
        printf("������")��
        return;
    }
    PtrQ->rear=(PtrQ->rear+1)%MaxSize;
    PtrQ->Data[PtrQ->rear]=item;
}
int deleteQ(Queue PtrQ)//����
{
    if(PtrQ->front==PtrQ->rear)
    {
        printf("���п�")��
        return ERROR;
    }else {
    PtrQ->front=(PtrQ->front+1)%MaxSize;
    return PtrQ->Data[PtrQ->front];
    }
}






#endif // QUEUE_ONE_H_INCLUDED
