#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include<time.h>

int main()
{
 /*   int a[4]={0,1,3};
   int *p=a;
   int b;
     scanf("%d",&b);
  for(int i=0;i<4;i++)
   {
        printf("%d\n",b);
        printf("%d\n",*(p+i)); 
   }*/
 //  printf("%.2f\n",(double)10000*clock()/CLOCKS_PER_SEC);
 int n=0,i=0;
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
     while(scanf("%d",&n)==1)
          {
               printf("%d\n",n);
               i++;
          }
          printf("%d\n",i);
   
   
    return 0;
   
}

