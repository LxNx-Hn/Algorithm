#include <stdio.h>
#define Swap(x,y) (x!=y) && (x ^= y ^= x ^= y)
void OutPut(int Arr[],int len) {
    for(int i = 0; i < len; i++) 
        printf("%d ",Arr[i]);
    printf("\n");
    }
void BubbleSort(int Arr[],int n){
    for (int i=0; i<n-1; ++i)
    {
        for (int j=0; j<n-1-i; ++j)
        {
            if (Arr[j] > Arr[j + 1])
            {Swap(Arr[j], Arr[j + 1]);}
        }
    }
}

int main()
{
int Arr[] = {3,24,44,58,5,14};
int len= sizeof(Arr)/sizeof(int);
OutPut(Arr,len);
BubbleSort(Arr,len);
OutPut(Arr,len);
}