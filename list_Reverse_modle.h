


Ptr Reverse(Ptr head,int K)
{
    int cnt=1;
    new=head->next;
    old=new->next;
    while(cnt<K)
    {
        tmp=old->next;
        old->next=new;
        new=old;
        old=tmp;
        cnt++;
    }
    head->next->next=old;//？连接逆转的尾结点与剩下的结点
    return new;
}
//单链表对于前K个结点进行逆转
//有空结点作为首结点