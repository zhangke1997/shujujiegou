#ifndef QUEUE_TWO_H_INCLUDED
#define QUEUE_TWO_H_INCLUDED
//ѭ�����е���ʽ�洢

struct Node{
    int Data;
    struct Node *Next;
};
struct QNode{
    struct Node *rear;
    struct Node *front;
};
typedef struct QNode *Queue;
Queue PtrQ;
int DeteleQ(Queue PtrQ)//����
{
    struct Node *FrontCell;
    int FrontElem;

    if(PtrQ->front==NULL){
            printf("���п�");
            return ERROR;
    }
    FrontCell=PtrQ->front;
    if(PtrQ->front==PtrQ->rear)
        PtrQ->front=PtrQ->rear=NULL;
    else
        PtrQ->front=PtrQ->front->Next;
    FrontElem=FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}
int AddQ(Queue PtrQ,int item)
{

}



#endif // QUEUE_TWO_H_INCLUDED
