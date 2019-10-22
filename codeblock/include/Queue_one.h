#ifndef QUEUE_ONE_H_INCLUDED
#define QUEUE_ONE_H_INCLUDED

#define MaxSize
struct QNode{    // 循环队列,数组实现
    int Data[MaxSize];
    int rear;  //队列尾
    int front;//队列头  front <- rear 装的顺序
};
typedef struct QNode *Queue;

void Add(Queue PtrQ,int item)//入队
{
    if((PtrQ->rear+1)%MaxSize == PtrQ->front)//取余是为了循环
    {
        printf("队列满")；
        return;
    }
    PtrQ->rear=(PtrQ->rear+1)%MaxSize;
    PtrQ->Data[PtrQ->rear]=item;
}
int deleteQ(Queue PtrQ)//出队
{
    if(PtrQ->front==PtrQ->rear)
    {
        printf("队列空")；
        return ERROR;
    }else {
    PtrQ->front=(PtrQ->front+1)%MaxSize;
    return PtrQ->Data[PtrQ->front];
    }
}






#endif // QUEUE_ONE_H_INCLUDED
