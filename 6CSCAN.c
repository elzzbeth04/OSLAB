// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int main() {
    // Write C code here
   int RQ[100],initial,n,size,sum=0,i,j,move;
   printf("Enter the number of Requests\n");
    scanf("%d", &n);
    
    // Reading the request sequence
    printf("Enter the Requests sequence\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }
    printf("Enter the head \n");
    scanf("%d",&initial);
    
    printf("enter the disk size\n");
    scanf("%d",&size);
    
    printf("enter the movemnt 0 or1 ");
    scanf("%d",&move);
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
            }
    }
    int index=0;
    for(i=0;i<n;i++)
    {
       if(RQ[i]>initial) 
       {
           index=i;
           break;
       }
    }
    
    if(move==1)
    {
        for (int i = index; i < n; i++){
            sum+=abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //last 
        if(initial<size-1)
        {
            sum=sum+abs(size-1-initial);
            initial=size-1;
        }
        sum=sum+abs(size-1-0);
        initial=0;
        //lower values
        for (int i = 0; i <index; i++) {
            sum += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
            sum=sum+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        if(initial<0)
        {
            sum=sum+abs(initial-0);
            initial=0;
        }
        printf("f");
        sum=sum+abs(size-1-initial);
        initial=size-1;
        
        for ( i = n-1; i < index; i--) {
            sum += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("total head movements %d",sum);
    }
    
   