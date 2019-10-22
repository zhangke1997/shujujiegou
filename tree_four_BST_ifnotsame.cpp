//是否是同一搜索树
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode
{
    int v;
    Tree Left,Right;
    int flag;//访问标记
};
Tree NewNode(int V)
{
    Tree T=(Tree)malloc(sizeof(struct TreeNode));
    T->v=V;
    T->Left=T->Right=NULL;
    T->flag=0;
    return T;


}
Tree Insert(Tree T,int V)
{
    if(!T) T=NewNode(V);
    else{
        if(V>T->v)
        T->Right=Insert(T->Right,V);
        else
        T->Left=Insert(T->Left,V);
    }
    return T;
}
Tree MakeTree(int N)
{
    Tree T;
    int i,V;
    scanf("%d",&V);
    T=NewNode(V);
    for(i=1;i<N;i++)
    {
        scanf("%d",&V);
        T=Insert(T,V);
    }
    return T;
}
int check(Tree T,int V)
{
    if(T->flag){//找过，找下一个结点
        if(V<T->v)return check(T->Left,V);
        else if(V>T->v) return check(T->Right,V);
        else return 0;//相等则出现两次不一致
    }
    else{
        if(V==T->v){//未被访问过
            T->flag=1;//找到，标志变1
            return 1;//找到
        }
        else return 0;//未找到
    }

}

int Judge(Tree T,int N)//判断N是否匹配未标记的结点
{
    int i,V,flag=0;//flag：0表示目前一致，1目前不一致
    scanf("%d",&V);
    if(V!=T->v) flag=1;//树根是否一样
    else T->flag =1;

    for(i=1;i<N;i++)
    {
        scanf("%d",&V);
        if((!flag) && (!check(T,V))) flag=1;//读完N组数，怕影响下一组数据
    }
    if(flag) return 0;
    else return 1;
}

void ResertT(Tree T)//清除flag
{
    if(T->Left) ResertT(T->Left);
    if(T->Right) ResertT(T->Right);
    T->flag =0;
}
void FreeTree(Tree T)//释放T空间
{
    if(T->Right) FreeTree(T->Right);
    if(T->Left) FreeTree(T->Left);
    free(T);
}


int main()
{
    int N,L,i;
    Tree T;
    scanf("%d",&N);
    while(N)
    {
        scanf("%d",&L);
        T=MakeTree(N);
        for(i=0;i<L;i++){
            if(Judge(T,N)) printf("Yes\n");
            else printf("No\n");
            ResertT(T);//清除flag
        }
        FreeTree(T);
        scanf("%d",&N);
    }
    return 0;
}
