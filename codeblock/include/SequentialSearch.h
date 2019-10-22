#ifndef SEQUENTIALSEARCH_H_INCLUDED
#define SEQUENTIALSEARCH_H_INCLUDED
//��̬�����е�˳����ҡ����ֲ���
typedef struct LNode *List;
#define MAXSIZE;//��֪����ĳ���
struct LNode{
        int Element[MAXSIZE];
        int length;
};
int SequentialSearch(List Tb1,int K)
{//��β��˳�����
    int i;
    Tb1->Element[0]=K;//ͷ���ڱ�
    for(i=Tb1->length;Tb1->Element[i]!=K;i--);
    return i;

}

int BinarySearch(List Tbl,ElementType K)//���ֲ���
{
    int left,right,mid,NoFound=-1;
    left=1;
    right=Tbl->length;
    while(left<=right)//��Ԫ�ش���
    {
        mid=(left+right)/2;//ȡ�����õ���С������
        if(K<Tbl->Element[mid]) right=mid-1;
        else if(K>Tbl->Element[mid]) left=mid+1;
        else return mid;
    }
    return NoFound;
}


#endif // SEQUENTIALSEARCH_H_INCLUDED
