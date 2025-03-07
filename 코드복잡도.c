//#include <stdio.h>
//알고리즘 -> 문제를 해결하기위한 절차나 방법, 입력을 받아 원하는 출력을 만들어내는 과정을 서술한것
//알고리즘의 효율은 메모리,통신대역,수행시간에대하여 결정된다
//수행시간은 n, n^2 , nlogn 등등이 존재함
//C기반
//O(1)의 복잡도 코드(상수시간복잡도)
/* int func (int arr[],int n){
    int result;
    result = n/2;
    return arr[result];
} */
//O(n)의 복잡도(선형시간복잡도)
/* int func (int arr[],int n){
    int result = 0;
    for(int i;i<n;i++){
        result += arr[i];
    }
    return result;
} */
//O(n^2)의 복잡도(이차시간복잡도)
/* int func (int arr[],int n){
    int result = 0;

    for(int i;i<n;i++){
        for(int j;j<n;j++){
        result += arr[i]+arr[j];
        }
    }
    return result;
} */
//점근표기법 : lim n ->∞ 이라고 계산 -> 상수항,계수를 무시하고 최고차항의 차수로 비교함
//𝚹-표기법 : 점근적 증가율이 일치하는 모든함수의 집합 -> 평균 / O,𝛀의 교집합
//𝚶-표기법 : 점근적 증가율이 이하인 모든함수의 집합 -> 최악 
//𝛀-표기법 : 점근적 증가율이 이상인 모든함수의 집합 -> 최선
