typedef struct LNode *List;
struct LNode
{
    int Data; //节点数据
    List Next; //下个节点位置
};

struct LNode L;
List PtrL;
int Length(List PtrL)//链表长度
{
    List p = PtrL;
    int j=0;
    while(p)
    {
        p=p->Next;//遍历节点位置是否存在
        j++;
    }
    return j;
}
List FindKth(int K,List PtrL)  //按照序号查找
{
    List p=PtrL;
    int i=1;
    while(p!=NULL&&i<K)//循环掉之前的
    {
        p=p->Next;
        i++;
    }
    if(i==K) return p;
    else
    return NULL;//指针的NULL相当于int的0；
}
List Find(int X,List PtrL)//按值查找 第一个
{
    List p=PtrL;
    while (p!=NULL&&p->Data!=X)//循环掉找到之前的节点
    {
        p=p->Next;
    }
    return p;
}

List Insert(int X,int i,List PtrL)
//链表Ptrl 在第i位置插入数据为Data的节点
//并返回新链表，即首节点
{
    List p,s;
    if(i==1)
    {
        s=(List)malloc(sizeof(struct LNode));
        s->Next = PtrL;
        p->Data=X;// 不可颠倒
        return s; //返回新的链表
    }
    p=FindKth(i-1,PtrL); //查找第i-1个节点 即p
    if(p==NULL)
    {
        printf("i is wrong");
        return NULL;
    }
    else
    {
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next = p->Next;
        p->Next=s;// 不可颠倒
        return PtrL;
    }
}

List Delete(int i,List PtrL)
{
    List p,s; // s做中间指针释放内存 p =i-1个节点
    if(i==1)
    {
        s=PtrL;
        if(PtrL！=NULL) PtrL=PtrL->Next;//PtrL被重新赋值
        else return NULL;
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p == NULL)
    printf("i-1 not available");
    else  if(p->Next==NULL)
    printf("i not available");
    else
    {
        s=p->Next;
        p->Next=s->Next;
        free(s);
        return PtrL;
    }
    
}
