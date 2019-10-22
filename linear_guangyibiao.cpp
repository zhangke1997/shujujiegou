//广义表 线性表单元素， 广义可以是另外一个广义表
typedef struct GNode *Glist;
struct GNode
{
    int Tag;
    union {  //union 使数据公用存储空间 表现为长度最长的
        int Data;
        Glist SubList;

    }URegion;
    Glist Next;
};


//多重链表（十字链表表示矩阵 向右向下指向） 