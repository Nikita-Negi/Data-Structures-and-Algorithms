#include <stdio.h>
void quick_sort(int[],int,int);
int partition(int[],int,int);
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
void main()
{
int heap[10],q[10],m[10], no, i, j, c, root, temp;
printf("\n Enter no of elements :");
scanf("%d", &no);
printf("\n Enter the nos :\n");
for (i = 0; i < no; i++)
{
scanf("%d", &heap[i]);
q[i]=heap[i];
m[i]=heap[i];
}
for (i = 1; i < no; i++)
{
c = i;
do
{
root = (c - 1) / 2;
if (heap[root] < heap[c]) /* to create MAX heap array */
{
temp = heap[root];
heap[root] = heap[c]; heap[c] = temp;
}
c = root;
} while (c != 0);
}
for (j = no - 1; j >= 0; j--)
{
temp = heap[0];
heap[0] = heap[j]; /* swap max element with rightmost leaf element */
heap[j] = temp;
root = 0;
do
{
c = 2 * root + 1; /* left node of root element */
if ((heap[c] < heap[c + 1]) && c < j-1)
c++;
if (heap[root]<heap[c] && c<j) /* again rearrange to max heap array */
{
temp = heap[root];
heap[root] = heap[c];
heap[c] = temp;
}
root = c;
} while (c < j);
}
printf("\nThe sorted array using Heap sort is:\t");
for (i = 0; i < no; i++)
printf("%d\t", heap[i]);
quick_sort(q,0,no-1);
printf("\nThe sorted array using quick sort is:\t");
for(i=0;i<no;i++)
printf("%d\t",q[i]);
mergesort(m,0,no-1);
printf("\nThe sorted array using merge sort is:\t");
for(i=0;i<no;i++)
printf("%d\t",m[i]);
getch();
}
void quick_sort(int a[],int l,int u)
{
int j;
if(l<u)
{
j=partition(a,l,u);
quick_sort(a,l,j-1);
quick_sort(a,j+1,u);
}
}
int partition(int a[],int l,int u)
{
int v,i,j,temp;
v=a[l];
i=l;
j=u+1;
do {
do
i++;
while(a[i]<v&&i<=u);
do
j--;
while(v<a[j]);
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}while(i<j);
a[l]=a[j];
a[j]=v;
return(j);
}
void mergesort(int a[],int i,int j)
{
int mid;
if(i<j)
{
mid=(i+j)/2;
mergesort(a,i,mid); //left recursion
mergesort(a,mid+1,j); //right recursion
merge(a,i,mid,mid+1,j); //merging of two sorted sub-arrays
}
}
void merge(int a[],int i1,int j1,int i2,int j2)
{
int temp[50]; //array used for merging
int i,j,k;
i=i1; //beginning of the first list
j=i2; //beginning of the second list
k=0;
while(i<=j1 && j<=j2) //while elements in both lists
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=j1) //copy remaining elements of the first list
temp[k++]=a[i++];
while(j<=j2) //copy remaining elements of the second list
temp[k++]=a[j++];
//Transfer elements from temp[] back to a[]
for(i=i1,j=0;i<=j2;i++,j++)
a[i]=temp[j];
}
