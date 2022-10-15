#include<stdio.h>

int visited[10],order[10],orderC=0,cycstack[10];

int checkCycle(int a[10][10],int n,int src){
if(!visited[src]){
visited[src]=1;
cycstack[src]=1;
for(int i=0;i<n;i++){
if(a[src][i]==1){
if(!visited[i]&&checkCycle(a,n,i))
return 1;
else if(cycstack[i])
return 1;
}
}
}
cycstack[src]=0;
return 0; 
}

void reset(int* a,int n){
for(int i=0;i<n;i++)
a[i]=0;
}

int isCyclic(int a[10][10],int n){
for(int i=0;i<n;i++){
if(!visited[i]&&checkCycle(a,n,i))
return 1;
}
return 0;
}


void dfs(int a[10][10],int n,int src){
    visited[src]=1;
    for(int i=0;i<n;i++){
        if(a[src][i]==1&&!visited[i]){
            dfs(a,n,i);
            order[orderC++]=i;
        }
    }
}   

void DFS(int a[10][10],int n,int src){
    int c = n;
    while(c--){
        if(!visited[src]){
            dfs(a,n,src);
            order[orderC++]=src;
        }
        src = (src+1)%n;
    }
}

int main(){
    int n,src;
    printf("\nEnter number of nodes : ");
    scanf("%d",&n);
    int a[10][10];
    printf("Enter adjacency matrix : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(isCyclic(a,n)){
    printf("\nGraph is cyclic!!\n");
    return -1;
    }
    else{
    reset(visited,n);
    DFS(a,n,0);
    printf("\nAcyclic Graph!!\nTopological sort is : \n");
    for(int i=orderC;i>0;i--){
    printf("%d ",order[i-1]+1);
    }
    printf("\n");
    }
    return 0;
}