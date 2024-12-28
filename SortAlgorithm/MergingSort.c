#include <stdio.h>
int Merged[8];
//배열을 반으로 나눠, 전반부와 후반부를 정렬하고, 정렬된 배열을 병합함
void OutPut(int Arr[],int len) {
    for(int i = 0; i < len; i++) 
        printf("%d ",Arr[i]);
    printf("\n");
}
void merge(int array[], int start, int end) {
    int mid = (start + end) / 2; // 중간 인덱스 계산
    int i = start; // 왼쪽 부분 시작 인덱스
    int j = mid + 1; // 오른쪽 부분 시작 인덱스
    int k = 0; // Merged 배열의 인덱스
    // 두 배열을 비교하여 정렬된 결과를 Merged 배열에 저장
    while (i <= mid && j <= end) { // 두배열중 하나라도 모든원소가 사라질때 종료
        if (array[i] <= array[j])    Merged[k++] = array[i++];
        else   Merged[k++] = array[j++];
    }
    //한쪽배열에 남은원소 추가
    for (; i <= mid; i++) Merged[k++] = array[i];
    for (; j <= end; j++) Merged[k++] = array[j];
    for (int m = 0; m < k; m++) {
        array[start + m] = Merged[m];
    }
        OutPut(array,end+1);
}
//[2,10],[8,25]->[2,8,10,25]
//병합해나가는 기능// 병합하면서 merged에 추가해야함
void Merge_sort(int array[],int start,int end){
        //2개일때부터 호출시작
        if (start < end) {
        //재귀 반복후 원소가 1개라면 호출이 안됨
        int mid = (start + end) / 2;
        Merge_sort(array, start, mid); //절반중 왼쪽
            //재귀 진행하면서 계속 나뉨
        Merge_sort(array, mid + 1, end); //나머지 오른쪽
            // ''
        merge(array, start, end);
    }
}
int main () {
    int arr[] = {35,2,25,10,13,30,16,8};
    int len = sizeof(arr)/sizeof(int);
    Merge_sort(arr,0,len-1);
    //OutPut(arr,len);
    return 0;
}
//2개-2개 비교 -> 4개배열완성
//2개-2개 비교 -> 4개완성
//

/*병합과정
->배열크기에 비례하므로 O(n)
분할과정
n크기의 배열이 k단계까지 나누어질때
배열의 크기는 n/2ᴷ=1
n->1로 가는데 필요한 수 유도
f(n)=n⋅log₂n
lim(n→∞)
​f(n)/(n⋅log₂n)=1

극한값이 상수 1에 수렴하므로
시간복잡도는 n⋅log n
 =1
*/
