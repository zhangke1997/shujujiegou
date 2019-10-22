//简单表示 临接矩阵
//版本C C++

#include<vector>
#include<iostream>
#include<stdio.h>
#define num 100;

int G[num][num],Nv,Ne;
void BuildGraph()
{
    int i,j,v1,v2,w;

    scanf("%d",&Nv);

    for(i=0;i<Nv;i++)
        for(j;j<Nv;j++)
            g[i][j]=0;
    scanf("%d",&Ne)
    for(i=0;i<Ne;i++)
        scanf("%d, %d %d",&v1,&v2,&w);
        G[v1][v2]=w;
        G[v2][v1]=w;

}




std::vector<std::vector<int>> GG((num),vector<int>(num,0));//二维容器 一维容器里面的元素再赋值一维容器
//std::vector<int> GG(MAXN,0)一维容器，<>里面包含的是 内容的类型
int Ne,Nv;
void BuildGraph2()
{
    int i,j,v1,v2,w;

    std::cin>>Nv;//行列数目

    for(i=0;i<Nv;i++)
        for(j;j<Nv;j++)
            GG[i][j]=0;
    std::cin>>Ne;
    for(i=0;i<Ne;i++)
        std::cin>>v1>>v2>>w;//无向图的权重
        GG[v1][v2]=w;
        GG[v2][v1]=w;

}