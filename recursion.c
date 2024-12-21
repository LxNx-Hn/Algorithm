#include <stdio.h>
/* void Recursive(int n){
    printf("Recursive func\n");
    if (n>0){
    Recursive(n-1);
    }
}

int Fact(int n){
    if (n==0) return 1;
    else return n * Fact(n-1);
}

int pibo(int n){
    if (n<=1)return n;
    return pibo(n-1)+pibo(n-2);
} */


//Start자리의 원반을 Bridge자리를 이용해 Destination으로 이동시킴
/* void Hanoi(int n, char Start, char Bridge, char Destination) {
    if (n == 1) {
        printf("!!%d %c->%c \n", n, Start, Destination); // 목적지로 원판을 옮기는코드
    } else {
        Hanoi(n - 1, Start, Destination, Bridge); //가장큰 원판빼고 다 치워두기
        printf("%d %c->%c \n", n, Start, Destination); //가장 큰 원판 옮기기
        Hanoi(n - 1, Bridge, Start, Destination); // 치워둔 원판 다시 옮기기
    }
}
int main(){
    int num;
    printf("입력:");
    scanf("%d",&num);
    Hanoi(num,'A','B','C');
    //printf("%d",Fact(num));
    
} */
/*
3입력시 - 기본설정(시작점-S,경유지=B,목적지=D) / 호출시에는 목적지와 경유지가 다름

    하노이(2-호출,S(시작점)에 위치한 2번원판을 D(경유지)를 이용해 B(목적지)로 이동시켜야함)
        하노이(1-호출, S(시작점)에 위치한 1번원판을 D(경유지)로이동)
        하노이( S(시작점)에 위치한 2번원판을 B(목적지)로 이동 ) 
        하노이(1-호출, S(경유지)에 위치한 1번원판을 B(목적지)로 이동)
3원판을 D로이동
    하노이(2-호출,S(경유지)에 위치한 2번원판을 B(시작점)를 이용해 D(목적지)로 이동시켜야함)
        하노이(1-호출, S(경유지)에 위치한 1번원판을 B(시작점)로이동)
        하노이( S(경유지)에위치한 2번원판을 D(목적지)로 이동 ) 
        하노이(1-호출, S(경유지)에 위치한 1번원판을 D(목적지)로 이동)   
   

*/
//2^n-1
//O(2ⁿ)


//동적 프로그래밍 -> DP
//작은부분에서 답을 구하고 이를 저장한뒤, 큰부분의 답을 풀어나가는 방식
//이전값을 저장함으로써 재귀의 중복호출과정을 제거하여 효율을 증가
#include <stdlib.h>
/* int dp(int* dparr,int n){
    dparr[0]=1;
    dparr[1]=1;
    int temp =0; 

    for (int i=2;i<n;i++) {
        dparr[i] = dparr[i-1]+dparr[i-2];
        temp = dparr[i];
    }
    return temp;
}
int main(){
int num;
int* dparr;

printf("수입력: ");
scanf("%d", &num);
dparr=(int*)malloc(sizeof(int) * num);

int i=dp(dparr,num);
printf("%d",i);
free(dparr);
return 0;
} */