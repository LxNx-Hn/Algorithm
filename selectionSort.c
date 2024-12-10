#include <stdio.h>
#define swap(x,y) (x!=y) && (x ^= y ^= x ^= y)
void SelectionSort(int arr[],int len)
{
    int i,j,minValue,cnt;
    cnt=0;
    for (i=0;i<len-1;i++) {
        minValue = i;
        for (j=i+1;j<len;j++)
        {
            if (arr[minValue]>arr[j]){minValue = j; cnt+=1;} //순회를 통해 최소값 찾기
        }
        swap(arr[minValue],arr[i]);
    }   

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
        printf("\n");
    printf("%d", cnt);
}
int main() {
    int arr[] = {2,8,16,22,24,31};
    int len = sizeof(arr)/sizeof(int);
    SelectionSort(arr,len);
    return 0;
}

//BIG-O(n^2)
//∑(n-1)+ ... +1
//{n*(n-1)}/2 
