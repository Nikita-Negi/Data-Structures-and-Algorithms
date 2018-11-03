#include<stdio.h>
#include define n 5
int a[n][n];
int visited[n];
int Q[n];
int front=-1,rear=-1;
main()
{
int i,j;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
printf("is %d adjacent to %d",i,j);
scanf("%d",&a[i][j]);
}
for(i=1;i<=n;i++)
visited[i]=0;
for(i=1;i<=n;i++)
{
if(visited[i]==0)
BFS(i);
}
}
void BFS(int v)
{
if(front==-1 && rear==-1)
front=rear=0;
else
++rear;
Q[rear]=v;
visited[v]=1;
printf("%d ",i);
while(front!=-1 && rear!=-1)
{
v=Q[front];
if(front==rear)
front=rear=-1;
else
front++;
for(int i=v;i<=n;i++)
{
if(a[v][i]!=0)
if(visited[i]==0)
{
rear++;
Q[rear]=i;
visited[i]=1;
printf("%d ",i);
}
}
}
}
