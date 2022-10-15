#include<stdio.h>
#include<stdlib.h>
int v[23];
int cycstack[10];
int checkCycle(int a[10][10],int n,int src){
    if(!v[src]){
        v[src]=1;
        cycstack[src]=1;
        for(int i=0;i<n;i++)
        {
            if(a[src][i]==1)
            {
                if(!v[i]&&checkCycle(a,n,i))
                return 1;
                else if(cycstack[i])
                return 1;
            }
        }
    }
    cycstack[src]=0;
    return 0;
}
void reset(int v[10],int n){
    for(int i=0;i<n;i++)
    v[i]=0;
}
int isCyclic(int a[10][10],int n){
    for(int i=0;i<n;i++)
    {
    if(!v[i]&&checkCycle(a,n,i))
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    int a[10][10];
    int i,j,k,node;
    int in[10]={0};
    int v[10]={0};
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    printf("Enter adj matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j]==1)
                in[j]++;
        }
    }
    if(isCyclic(a,n)){
    printf("\nGraph is cyclic!!\n");
    return -1;
    }
    else{
        reset(v,n);
    //checkCycle(a,n,)
        printf("Topological order:\n");
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                if(in[i] == 0 && v[i] == 0)
                {
                node=i;
                printf("%5d", node);
                v[node]=1;
                break;
                }
            }
            for(i=0;i<n;i++)
            {
            if(a[node][i]==1)
                in[i]--;
            }
        }
    }
}