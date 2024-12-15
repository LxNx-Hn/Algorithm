#include <stdio.h>
void OutPut(int Arr[],int len) {
    for(int i = 0; i < len; i++) 
        printf("%d ",Arr[i]);
    printf("\n");
    }
void insertionSort(int Arr[], int len) {
    for (int i = 1; i < len; i++) { 
        int key = Arr[i];           
        int j = i - 1;        
        // key보다 큰 값을 한 칸씩 뒤로 밀기      
        while (j >= 0 && Arr[j] > key) {
            Arr[j + 1] = Arr[j]; // 뒤로 미는과정
            j--;
        }
        Arr[j + 1] = key; // 삽입부분
    }
}
int main () {
    int Arr[] ={16,2,31,22,8,24};
    int len= sizeof(Arr)/sizeof(int);
    OutPut(Arr,len);
    insertionSort(Arr,len);
    OutPut(Arr,len);
    return 0;
}
//sp-O(1)
//O(n²)
//𝛀(n)
//𝚹(n²)
/*
psudo void insertion_sort(array,len):
	from i to len-1 , I+1
        key = array[i]
        Loop:
        j>=0 and arr[j]>key
            arr[j+1]=arr[j]
        arr[j+1]=key
*/