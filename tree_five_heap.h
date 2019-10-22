//树堆，优先队列，元素的优先权（关键字）而不是顺序。
///优先队列：数组、链表、有序数组、有序链表
//优先队列：用树，查找树，避免一端删除不平衡，一直删除最大值
//堆：完全二叉数且根结点比子结点大或者小（最大堆、最小堆）

//最大堆
#include<stdlib.h>
#include<stdio.h>

typedef struct HeapStruct *MaxHeap; 
struct HeapStruct
{
    int *Elements;//数组存放 元素从1开始存放
    int Size; //当前元素的个数
    int Capacity;//最大容量
};

MaxHeap Create(int MaxSize)//创建容量为MaxSize的空最大堆
{
    MaxHeap H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSize+1)*sizeof(int));//从一开始存储
    H->Capacity=MaxSize;
    H->Size=0; 
    H->Elements[0]=Maxdata;//赋值哨兵为堆中所有的最大值
    return H;
}

bool IsFull(MaxHeap H)
{
    return (H->Size==H->Capacity);
}

bool Insert(MaxHeap H,int item)
{
    int i;
    if(IsFull(H))
    {
        printf("最大堆满了");
        return false;

    }
    i=++H->Size;//当前要存入数组的下标
    for(;H->Elements[i/2]<item;i/=2)//向上返回根结点 直到item找到合适的根结点下标i 使得根结点大于插入值则退出
    {//哨兵的作用体现出来 当插入最大值时 i=1时与i/2=0 与哨兵比较，没有哨兵就要并上一个i>0,哨兵提高了性能
        H->Elements[i]=H->Elements[i/2];//向下过滤根结点，不用担心覆盖问题第一个i是新建的
    }
    H->Elements[i]=item;
    return true;//，从最大的下标开始找合适的i、

}

bool IsEmpty(MaxHeap H)
{
    return (H->Size==0);
}


int deleteMax(MaxHeap H)
{
    int Parent,Child;
    int MaxItem,temp;
    if(IsEmpty(H))
    {
        printf("最大堆满了");
        return;
    }
    MaxItem = H->Elements[1];//删除的最大值永远在Element[1] 保存一下 下面要替换
    temp =H->Elements[H->Size--];//删除最大的用temp代替Element[1]然后再调整
    for(Parent=1;Parent*2<=H->Size;Parent=Child)
    {
        Child=Parent*2;//左儿子
        if((Child!=H->Size) && (H->Elements[Child]<H->Elements[Child+1]))
        Child++;//指向最大的字节点
        if(temp >= H->Elements[Child]) break;//temp 比左右儿子都要大 那就找到了根结点的位置是Parent
        else
        H->Elements[Parent]=H->Elements[Child];//大的儿子替换掉根结点，然后Parent会被大的子结点 代替，相当于移动达下一层

    }
    H->Elements[Parent] =temp;//找到了 break返回的操作
    return MaxItem;
}

void PercDown(MaxHeap H,int p)//建造最大堆    下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
//作用：先按照顺序输入在通过这个函数调整位置
{
    int Parent,Child;
    int x;
    x=H->Elements[p];
    for(Parent=p;Parent*2<=H->Size;Parent=Child)
    {
        Child=Parent*2;
        if((Child!=H->Size) && (H->Elements[Child]<H->Elements[Child+1]))
        Child++;
        if(x>H->Elements[Child]) break;
        else
        {
            H->Elements[Parent]=H->Elements[Child];

        }
        H->Elements[Parent]=x;
        
    }
}
void BuildHeap( MaxHeap H )
{ /* 调整H->Data[]中的元素，使满足最大堆的有序性  */
  /* 这里假设所有H->Size个元素已经存在H->Data[]中 */
 
    int i;
 
    /* 从最后一个结点的父节点开始，到根结点1 */
    for( i = H->Size/2; i>0; i-- )
        PercDown( H, i );
}


