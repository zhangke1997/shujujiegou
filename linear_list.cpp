

typedef struct LNode *List;
struct LNode{
    /* data */
    int Data[MAXSIZE];//ElementType 用int 代替
    int Last;;
};
struct LNode L;
List PtrL;



List MakeEmpty()//初始化
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNdoe));
    PtrL->Last = -1;//含有零个数组的下标 0表示第一个
    return PtrL;
} 

int Find(int X , List PtrL)//查找
{
    int i=0;
    while(i<=PtrL->Last && PtrL->Data[i] != X)
        i++;
    if(i>PtrL->Last) return -1;
    else
         return i;
} 
void Insert(int X,int i, List PtrL)// 第i位置插入X 数组下标是i—1
{
    int j;
    if(PtrL->Last == MAXSIZE-1)
    {
        printf("表满")；
        return；
    }
    if(i<1 || i>PtrL->Last+2)//i=1 to Last+1
    {
        printf("i不合法")；
        return;
    }
    for(j=PtrL->Last;j>=i-1;j--)
        PtrL->Data[j+1]=PtrL->Data[j];
    PtrL->Data[i-1]=X;
    PtrL->Last++;
    return;   
}
void Delet(int i,List PtrL) //删除i个元素 下表i-1
{   
    if(i<1 || i>PtrL->Last+1)
    {
        printf("i is wrong");
        return;
    }
    for(i;i<PtrL->Last+1;i++) // 教程j代替了i
        PtrL->Data[i]=PtrL->Data[i+1];
    PtrL->Last--;
    return;
}
