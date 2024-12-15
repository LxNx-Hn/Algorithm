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
void Hanoi(int n, char Start, char Bridge, char Destination) {
    if (n == 1) {
        printf("!!%d %c->%c \n", n, Start, Destination); // 목적지로 원판을 옮기는코드
    } else {
        Hanoi(n - 1, Start, Destination, Bridge); //가장큰 원판빼고 다 치워두기
        printf("%d %c->%c \n", n, Start, Destination); //가장 큰 원판 옮기기
        Hanoi(n - 1, Bridge, Start, Destination); // 치워둔 원판 다시 옮기기
    }
}
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

int main(){
    int num;
    printf("입력:");
    scanf("%d",&num);
    Hanoi(num,'A','B','C');
    //printf("%d",Fact(num));
    
}

//2^n-1
//O(2ⁿ)