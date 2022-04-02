include<stdio.h>
void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}
void quicksort(int arr[],int low,int high)
{
    int pi;
     if(low<high)
    {
    pi= partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
    }
}
int printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int partition(int arr[],int low,int high)
{
    int j,i,pivot;
    pivot=arr[high];
    i=low-1;//this is a partitionindex correct so far
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

int main()
{
    int arr[]={10,20,40,30,25,5,70,45};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\nbefore sortiing\n");
    printArray(arr,n);
    quicksort(arr,0,n-1);
    printf("\nAfter sorting\n");
    printArray(arr,n);
    return 0;
}
