#include <stdio.h>
#define SWAP(x, y) { int temp = x; x = y; y = temp; }

void OutPut(int Arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {

        int pivot = arr[(left + right) / 2]; 
        int i = left;
        int j = right;

        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                SWAP(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (left < j) quickSort(arr, left, j);
        if (i < right) quickSort(arr, i, right);
    }
}

int main() {
    int arr[] = {35, 2, 20, 13, 30, 25, 21, 23};
    int len = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, len - 1); 
    OutPut(arr, len);

    return 0;
}