#include <stdio.h>     
void heapify(int a[], int n, int i)  
{  
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
    if (left < n && a[left] > a[largest])  
        largest = left;  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    if (largest != i) {  
        
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
        heapify(a, n, largest);  
    }
    
    }  
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
         printf("\nevery step of execution\n");
for(int i=0;i<=n;i++)
{
    printf("%d\t",a[i]);
}
printf("\n");
        heapify(a, i, 0);  
    }  
} 
void printArr(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        printf("%d", arr[i]);  
        printf(" ");  
    }   
}  
int main()  
{ printf("Kumar Anup 170\n Heap sort\n");
    int a[] = {1,3,5,4,6,13,10,9,8,15,17};  
    int n = sizeof(a) / sizeof(a[0]);
    printf("before sorting arrey");
    printArr(a,n);
    heapSort(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(a, n);  
    return 0;  
}  