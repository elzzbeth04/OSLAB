#include<stdio.h>
int main()
{
    int pno,bno,psize[10],bsize[10],fragment[10],allocation[10];
    for(int i=0;i<10;i++)
    {
        allocation[i]=-1;
    }
    printf("enter no of process: ");
    scanf("%d",&pno);
    for(int i=0;i<pno;i++)
    {
        printf("enter psize: ");
        scanf("%d",&psize[i]);
    }
    printf("enter no of blocks: ");
    scanf("%d",&bno);
    for(int i=0;i<bno;i++)
    {
        printf("enter bsize: ");
        scanf("%d",&bsize[i]);
    }
    for(int i=0;i<pno;i++)
    {
        int bstidx=-1;
        for(int j=0;j<bno;j++)
        {
            if(bsize[j]>=psize[i])
            {
                if(bstidx==-1||bsize[j]<bsize[bstidx])
                {
                    bstidx=j;
                }
            }
        }
        if(bstidx!=-1)
        {
            allocation[i]=bstidx;
            bsize[bstidx]-=psize[i];
            fragment[i]=bsize[bstidx];
        }
    }
    printf("process\tpsize\tbno\tfragment\n");
    for(int i=0;i<pno;i++)
    {
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(allocation[i]!=-1)
        {
            printf("%d\t\t%d\n",allocation[i]+1,fragment[i]);
        }
        else {
            printf("Not Allocated\n");
        }
    }
    return 0;
}