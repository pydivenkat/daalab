#include <stdio.h>
#include <stdlib.h>
int count;
int partition(int arr[], int low, int high)
{
int i,temp,key,j;
key=arr[low];
i=low+1;
j=high;
while(1)
{
count++;

while(i<high&&key>=arr[i])
{

i++;
}
while(key<arr[j])
{

j--;
}

if(i<j)
{

temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
else
{

temp=arr[low];
arr[low]=arr[j];
arr[j]=temp;
return j;
}

}


}
void quicksort(int arr[], int low, int high)
{
int p;
count++;
if(low<high)
{

p=partition(arr,low,high);
quicksort(arr,low,p-1);
quicksort(arr,p+1,high);
}
}
int main()
{
int a[1000],b[1000],c[1000],i,j,arr[100],n,c1,c2,c3;
printf("\nEnter the size of the array: ");
scanf("%d",&n);
printf("\nEnter the elements: ");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
count=0;
quicksort(arr,0,n-1);
printf("Array after sorting:\n");
for(i=0;i<n;i++)
{
printf("%d\t",arr[i]);
}
printf("\nThe count is %d\n",count);
count=0;
printf("Total count:\n");
printf("size\t ascending\t descending\t random\n");
for(i=5;i<600;i=i*2)

{
for(j=0;j<i;j++)
{
a[j]=j;
b[j]=i-j;
c[j]=rand()%i;
}
count=0;
quicksort(a,0,i-1);
c1=count;
count=0;
quicksort(b,0,i-1);
c2=count;
count=0;
quicksort(c,0,i-1);
c3=count;

printf("%d\t\t%d\t\t%d\t\t%d\n",i,c1,c2,c3);
}
}