#include<stdio.h>
#include<stdlib.h>
void maxHeapify(int *heap, int size, int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<size && heap[l]>heap[largest])
    {
        largest=l;
    }
    if(r<size && heap[r]>heap[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp=heap[i];
        heap[i]=heap[largest];
        heap[largest]=temp;
        maxHeapify(heap, size, largest);
    }
}

void buildMaxHeap(int *heap, int size)
{
    for(int i=size/2; i>=0; i--)
    {
        maxHeapify(heap, size, i);
    }
}
void deleteMax(int *heap, int *size)
{
    if(*size==0)
    {
        printf("Max heap is empty");
        return;
    }
    heap[0]=heap[*size-1];
    (*size)--;
    maxHeapify(heap, *size, 0);
}
void heapSort(int *heap, int size)
{
    buildMaxHeap(heap, size);
    for(int i=size-1; i>=0; i--)
    {
        
        int temp=heap[0];
        heap[0]=heap[i];
        heap[i]=temp;
        maxHeapify(heap, i, 0);
    }
}
int main()
{
    int *heap, size=10, key;
    heap=(int*)malloc(size*sizeof(int));
    for(int i=0; i<size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &heap[i]);
    }
    /*
    buildMaxHeap(heap, size);
    for(int i=0; i<size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    deleteMax(heap, &size);
    for(int i=0; i<size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    */
    heapSort(heap, size);
    for(int i=0; i<size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    return 0;
}