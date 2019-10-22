#ifndef SEQUENTIALSEARCH_H_INCLUDED
#define SEQUENTIALSEARCH_H_INCLUDED
//静态查找中的顺序查找、二分查找
typedef struct LNode *List;
#define MAXSIZE;//已知数组的长度
struct LNode{
        int Element[MAXSIZE];
        int length;
};
int SequentialSearch(List Tb1,int K)
{//从尾部顺序查找
    int i;
    Tb1->Element[0]=K;//头部哨兵
    for(i=Tb1->length;Tb1->Element[i]!=K;i--);
    return i;

}

int BinarySearch(List Tbl,ElementType K)//二分查找
{
    int left,right,mid,NoFound=-1;
    left=1;
    right=Tbl->length;
    while(left<=right)//有元素存在
    {
        mid=(left+right)/2;//取整不用担心小数问题
        if(K<Tbl->Element[mid]) right=mid-1;
        else if(K>Tbl->Element[mid]) left=mid+1;
        else return mid;
    }
    return NoFound;
}


#endif // SEQUENTIALSEARCH_H_INCLUDED
