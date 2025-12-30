#include<stdio.h>

int n,i,j,a[10][10],vis[10],count =1;

void dfs(int v){
    vis[v]=1;
    printf("%d \t",v);
    for(j=1;j<=n;j++){
        if(a[v][j]==1 && vis[j]==0){
            dfs(j);
        }
    }
}

void main(){
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
        vis[i]=0;
    }
    printf("dfs traversal\n");

    for(i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }

    for(i=0;i<n;i++){
        if(vis[i]){
            count++;
        }
    }

    if(count==n){
        printf("\n graph is connected");
    }
    else{
        printf("graph is not connected");
    }
}
